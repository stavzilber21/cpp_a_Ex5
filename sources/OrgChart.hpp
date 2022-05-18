#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
namespace ariel{
    class OrgChart : public error_code {
    private:
        struct Node{
            int level;
            string name;
            Node *parentNode;
            vector<Node*>node_childs;
        };
        Node *root;
        int max_level;
    public:
        OrgChart();
        OrgChart& add_root(string name);
        OrgChart& add_sub(string name1, string name2);
        friend ostream& operator<<(ostream& output, const OrgChart &org);

        string * begin();
        string * end();
        vector<string>::iterator begin_level_order();
        vector<string>::iterator end_level_order();
        vector<string>::iterator begin_reverse_order();
        vector<string>::iterator reverse_order();
        vector<string>::iterator begin_preorder();
        vector<string>::iterator end_preorder();
    };

}