#ifndef VAR_H
#define VAR_H

#include<vector>
#include<iostream>

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

int getW(var v){
    if(v.vals.size() == 0) return 2;
    int max = 0;
    
    for(auto val : vals){
        if(val.first.length() > max) max = val.first.length();
    }

    return max + 2;
}
#endif