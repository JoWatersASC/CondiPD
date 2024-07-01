#ifndef CPD_H
#define CPD_H

#include<map>
#include<set>
#include"var.h"

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