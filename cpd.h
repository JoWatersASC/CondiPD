#ifndef CPD_H
#define CPD_H
#include<vector>
#include<iostream>
#include<map>
#include<set>

struct var{
    std::string name;
    std::vector<std::pair<std::string, float>> vals;

    void print(std::ostream& out){
        out << name << std::endl;
        for(auto p : vals){
            out << p.first << ": " << p.second << std::endl;
        }
    }
};

class cpd{
    public:
        cpd();
        cpd(var variable, std::vector<var> dependencies);
        
        void print(int method = 0);
        void printVar();
        void printCPD();

    private:
        var v;
        std::vector<var> depList;
        std::map<std::set<std::string>, float> pDist;
        std::ostream& out;

        void build(int index, std::set<std::string> s);
};

template<typename T>
void print(std::set<T> s, std::ostream& out = std::cout){
    out << "(";
    
    for(T t : s){
        out << t << ", ";
    }

    out << "\b\b)" << std::endl;
}
#endif