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

int* OrgChart::begin(){
    int *i =0;
    return i;
}
int* OrgChart:: end(){
    int *i =0;
    return i;
}
OrgChart::My_Iterator OrgChart::begin_level_order(){
    return OrgChart::My_Iterator();
}
OrgChart::My_Iterator OrgChart::end_level_order(){
    return OrgChart::My_Iterator();
}
OrgChart::My_Iterator OrgChart::begin_reverse_order(){
    return OrgChart::My_Iterator();
}
OrgChart::My_Iterator OrgChart::reverse_order(){
    return OrgChart::My_Iterator();
}
OrgChart::My_Iterator OrgChart::begin_preorder(){
    return OrgChart::My_Iterator();
}
OrgChart::My_Iterator OrgChart::end_preorder(){
    return OrgChart::My_Iterator();
}