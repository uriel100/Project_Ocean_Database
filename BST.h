# include <iostream>
# include <cstdlib>
# include <cctype>
# include <string>
# include <vector>
# include <iterator>
# include <algorithm>

using namespace std;

class Node{
    Node* left = NULL;
    Node* right = NULL;
    Node* parent = NULL;
    Node* root = NULL;
    string facts;
    string name;
    char data;
    public:
    Node(){}
    Node(string new_name, string new_facts){ name = new_name; facts = new_facts;}
    void setLeft(Node* l){left = l;};
    void setRight(Node* r){right = r;};
    void setRoot(Node* rt){root = rt;}
    void setParent(Node* p){parent = p;};
    void setData(char sad){data = sad;};
    void setFacts(string f){facts = f;};
    Node* getRoot(){return root;};
    Node* getLeft(){return left;};
    Node* getRight(){return right;};
    string getFacts(){return facts;};
    char getData(){return data;};
};

class Tree{
    Node* root = NULL;
    public:
    Tree(){root = NULL;
    new_node = new Node("Polar Bear", "facts");
    insert(new_node, 4);
    new_node = new Node("Jellyfish", "facts");
    insert(new_node, 3);
    new_node = new Node("Great White Shark", "facts");
    insert(new_node, 2);
    new_node = new Node("East Pacific Red Octopus", "facts");
    insert(new_node, 1);
    new_node = new Node("Sea Otter", "facts");
    insert(new_node, 5);
    new_node = new Node("Sea Turtle", "facts");
    insert(new_node, 6);
    new_node = new Node("Starfish", "facts");
    insert(new_node, 7);
    new_node = new Node("Whale Shark", "facts");
    insert(new_node, 8);
          
     }
    void insert(Node* tmp, char c){
        Node* n = tmp;
        n->setData(c);
        if (root == NULL){//empty case
            //  tmp->setRoot(n);
            root = n;
        }
        else{//not empty
            if(c < tmp->getData()){
                if (tmp->getLeft()== NULL){
                    tmp->setLeft(n);//set to new node
                    return;
                }
                else insert(tmp->getLeft(),c);//finally
            }
            if(c > tmp->getData()){
                if (tmp->getRight()== NULL){
                    tmp->setRight(n);
                 return;
                }
                else insert(tmp->getRight(), c);
            }
            if (c == tmp->getData()){
                return;
            }
        }
    }
    
     Node *search1(Node* n2, char k){
        if(n2){
            if(n2->getData() == k)
                return n2;
            else{
                if(k < n2->getData())
                    search1(n2->getLeft(), k);
                else
                    search1(n2->getRight(),k);
            }
        }
    }     
       string searchFacts(Node* n2, char k){
        //if(!n2){return false;} //goes in main
        if(k == n2 -> getData()){
            return n2->getFacts();
        }
           
        Node* tmp = NULL;
        tmp = search1(n2, k);
        return tmp -> getFacts();
           
    }


};
