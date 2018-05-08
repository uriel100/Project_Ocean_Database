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
    //char data;
    string facts;
    string address;
    string name;
    public:
    Node( string new_name, string new_facts){ name = new_name; facts = new_facts;}
    void setLeft(Node* l){left = l;};
    void setRight(Node* r){right = r;};
    void setRoot(Node* rt){root = rt;}
    void setParent(Node* p){parent = p;};
    void setData(string sad){name = sad;};
    void setFacts(string f){facts = f;};
    void setAddress(string a){address = a;};
    //void setName(string x){data = x;};
    Node* getRoot(){return root;};
    Node* getLeft(){return left;};
    Node* getRight(){return right;};
    //string getName(){return name;};
    string getFacts(){return facts;};
    string getAddress(){return address;};
    string getData(){return name;};
};

class Tree{
    Node* root = NULL;
    public:
    Tree(){root = NULL;
    new_node = new Node("Polar Bear", "facts");
    insert(Node* new_node,'P');
    new_node = new Node("Jellyfish", "facts");
    insert(Node* new_node,'J');
    new_node = new Node("Great White Shark", "facts");
    insert(Node* new_node,'G');
    new_node = new Node("East Pacific Red Octopus", "facts");
    insert(Node* new_node,'E');
    new_node = new Node("Sea Otter", "facts");
    insert(Node* new_node,'O');
    new_node = new Node("Sea Turtle", "facts");
    insert(Node* new_node,'T');
    new_node = new Node("Starfish", "facts");
    insert(Node* new_node,'S');
    new_node = new Node("Whale Shark", "facts");
    insert(Node* new_node,'W');
          
     }
    void insert(Node* tmp, char c){
        Node* n = new Node();
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
    
     Node *search1(Node* n2, string k){
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
       string searchFacts(Node* n2, string k){
        //if(!n2){return false;} //goes in main
        if(k == n2 -> getData()){
            return n2->getFacts();
        }
        Node* tmp = NULL;
        tmp = search1(n2, k);
        return tmp -> getFacts();
    }


};
