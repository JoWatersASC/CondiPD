#include"cpd.h"

cpd::cpd() : depList({}), out(std::cout){
    v = {"null", {{"true", 0.5f}, {"false", 0.5f}}};
}

cpd::cpd(var variable, std::vector<var> dependencies) : v(variable), depList(dependencies), out(std::cout){
    int vSize = v.vals.size();
    int dSize = depList.size();

    std::set<std::string> s;
    build(0, s);
}

void cpd::build(int index, std::set<std::string> s){
    if(index >= depList.size()){
        float prob = 1.0f;
        
        for(int i = 0; i < v.vals.size() - 1; i++){
            // out << v.vals.size() << std::endl;
            std::set<std::string> newSet = s;
            auto valpair = v.vals[i];
            std::string valStr = v.name + "=" + valpair.first;
            
            newSet.insert(valStr);
            
            out << "P(" << valStr << " | ";

            for(auto str : s){
                out << str << ", ";
            }
            out << "\b\b) = ?\n=> ";

            float input = 1.1f;    
            std::cin >> input;
            while(input > prob){
                out << "Please input a number less than the remaining probability(" << prob << ")\n=> ";
                std::cin >> input;
            }

            prob -= input;
            pDist[newSet] = input;

        }

        std::string valStr = v.name + "=" + v.vals[v.vals.size() - 1].first;
        s.insert(valStr);
        pDist[s] = prob;
        
        return;
    }

    var dep = depList[index];

    for(int i = index; i < dep.vals.size(); i++){
        std::string valStr = dep.name + "=" + dep.vals[i].first;
        s.insert(valStr);
        build(index + 1, s);
        s.erase(valStr);
    }
}

void cpd::print(int method){
    if(depList.size() == 0) method = 1;

    switch(method){
        case 0:
            printCPD();
        case 1:
            printVar();
        default:
            return;
    }
}

void cpd::printVar(){
    out << v.name << std::endl;
    for(auto val : v.vals){
        auto name = val.first;
        auto value = val.second;

        out << "P(" << v.name << "=" << name << ") = " <<  value << std::endl;
    }
}

void cpd::printCPD(){
    out << "P(" << v.name << "|";
    for(var dependency : depList){
        out << dependency.name << ",";
    }
    out << "\b)" << std::endl;

    std::vector<std::string> output;
    for(auto distSet : pDist){
        auto dependencies = distSet.first;
        std::string input = "P(";
        out << "P(";
        
        for(auto str : dependencies){

            out << str << ",";
        }
        out << "\b) = " << distSet.second << std::endl;
    }
}