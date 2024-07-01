#include"cpd.h"

int main(int argc, char* argv[]){
    std::vector<var> vect;
    var value = {"A", {{"Make Class", 0.33f}, {"Miss Class", 0.33f}, {"Late to Class", 0.34f}}};

    vect.push_back({"B", {{"Care", 0.5f}, {"Don't Care", 0.5f}}});
    vect.push_back({"C", {{"Rain", 0.3f}, {"Sunny Day", 0.5f}, {"Hail", 0.2f}}});
    vect.push_back({"D", {{"Low Traffic", 0.15f}, {"Regular Traffic", 0.5f}, {"High Traffic", 0.35f}}});

    cpd c(value, vect);
    c.print();
}