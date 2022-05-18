#include "OrgChart.hpp"
#include <string>
using namespace std;
using namespace ariel;

OrgChart::OrgChart(){}

OrgChart& OrgChart::add_root(string name){
    return *this;
}

OrgChart& OrgChart::add_sub(string name1, string name2){
    return *this;
}

ostream& ariel::operator<<(ostream& output, const OrgChart &org){
    return output;
}

string * OrgChart::begin(){
    string *i =0;
    return i;
}
string* OrgChart:: end(){
    string *i =0;
    return i;
}
vector<string>::iterator OrgChart::begin_level_order(){

    return {};
}
vector<string>::iterator OrgChart::end_level_order(){
    return {};
}
vector<string>::iterator OrgChart::begin_reverse_order(){
    return {};
}
vector<string>::iterator OrgChart::reverse_order(){
    return {};
}
vector<string>::iterator OrgChart::begin_preorder(){
    return {};
}
vector<string>::iterator OrgChart::end_preorder(){
    return {};
}