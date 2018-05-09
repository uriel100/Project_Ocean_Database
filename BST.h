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
    new_node = new Node("Polar Bear", "Polar bears are the largest land carnivores in the world. Did you know that a polar bear’s fur isn’t white? It’s actually transparent with a hollow core that reflects light. This helps the bears blend in with their surroundings – a useful trick, especially when hunting wary seals! Scientists predict that American polar bears could face extinction in the next 50 years if urgent actions aren't taken to help them survive. You can help. Adopt a polar bear.");
    insert(new_node, 4);
    new_node = new Node("Jellyfish", "Jellyfish don't have brains and are 95% water. If a jellyfish is cut in two, the pieces of the jellyfish can regenerate and create two new organisms. An assemblage of jellies is a swarm or, better yet, a smack.");
    insert(new_node, 3);
    new_node = new Node("Great White Shark", "The great white is at the top of the food chain and has few threats in the ocean. Great white sharks have about 300 teeth, arranged in many rows. After mating the female great white develops several eggs which hatch in her womb. The newly-hatched shark pups feed on unfertilized eggs in the womb as they develop before being born.");
    insert(new_node, 2);
    new_node = new Node("East Pacific Red Octopus", "The plural of octopus is octopuses, not octopi, octopodes, or octopussies. Red octopuses have boneless, highly flexible and soft bodies that allow them to squeeze through very small spaces, even those as small as one of their eyeballs! Octopuses can sometimes suffer from autophagy, or self-cannibalism, due to stress. That is what is described as eating its own arms.");
    insert(new_node, 1);
    new_node = new Node("Sea Otter", "Sea otters have the thickest fur of any mammal in the animal kingdom. The layers manage to trap air next to the otter’s skin, which keeps the otters dry and warm and also helps with buoyancy—pups have so much air trapped in there, they actually can’t dive under water, even if they want to. A mother will often wrap the babies in kelp to keep them in one place while she hunts.");
    insert(new_node, 5);
    new_node = new Node("Sea Turtle", "Sea turtles have stronger muscles than humans. Sea turtles are one of the Earth's most ancient creatures. The seven species that can be found today have been around for 110  million years, since the time of the dinosaurs. Some can live to be 100 years old.");
    insert(new_node, 6);
    new_node = new Node("Starfish", "Starfish do not have a brain or any blood. The average lifespan of a sea star is 35 years and can regenerate lost limbs. Starfish are not fish they are related to sand dollars and sea urchins.");
    insert(new_node, 7);
    new_node = new Node("Whale Shark", "Whale Sharks are the biggest fish in the sea. They open their mouths, let water come in and their bodies filter out food, and release the water and any debris back into the ocean. Whale Sharks can live 100 to 150 years. Although massive, whale sharks are docile fish and sometimes allow swimmers to hitch a ride. They are currently listed as a vulnerable species; however, they continue to be hunted.");
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
