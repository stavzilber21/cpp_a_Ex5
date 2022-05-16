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

        class My_Iterator{
            private:
                Node *curr;
                int i;

            public:
                My_Iterator(){
                    this->curr = NULL;
                    this->i = 0;
                }
                My_Iterator operator++(int){
                    My_Iterator iter = *this;
                    return iter;
                }
                My_Iterator& operator++(){
                    return *this;
                }
                bool operator!=(const My_Iterator& iter) const{
                    return false;
                }
                string* operator->() const{
                    return nullptr;
                }
                string operator*() const{
                    return "";
                }

        };
        int* begin();
        int* end();
        My_Iterator begin_level_order();
        My_Iterator end_level_order();
        My_Iterator begin_reverse_order();
        My_Iterator reverse_order();
        My_Iterator begin_preorder();
        My_Iterator end_preorder();
    };

}