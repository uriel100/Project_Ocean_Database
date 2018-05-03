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
    string name;
    public:
    Node(){}
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
    
     Node search1(Node* n2, string k){
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
     bool searchAddress(Node* n2, string k){

        if(!n2){return false;}
         if(k == n2 -> getData()){
            return n2->getAddress();
        }
            Node* nptr = search1(n2, k);
            return nptr -> getAddress();
};
