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
    char data;
    string name;
    public:
    Node(){}
    void setLeft(Node* l){left = l;};
    void setRight(Node* r){right = r;};
    void setRoot(Node* rt){root = rt;}
    void setParent(Node* p){parent = p;};
    void setData(char sad){data = sad;};
    void setName(string x){data = x;};
    Node* getRoot(){return root;};
    Node* getLeft(){return left;};
    Node* getRight(){return right;};
    string getName(){return name;};
    char getData(){return data;};
};

class Tree{
    Node* root = NULL;
    public:
    Tree(){root = NULL;}
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
};
