# include <iostream>
# include <cstdlib>
# include <cctype>
# include <string>
# include <vector>
# include <iterator>
# include <algorithm>

using namespace std;
void die(string s = "") {
    if (s == "")
        cout << "BAD INPUT!" << endl;
    else
        cout << s << endl;
    exit(1);
}

Class LL {
private:
  int animal = 0;
  string address;
  string url;
  string name;
 LL *prev = nullptr;
 LL *next = nullptr;
  
public:
  LL( int new_animal = 0, string new_name = " ", string new_address = " ", string new_url = " ", LL *new_prev = nullptr, LL *new_next= nullptr)
  {
    animal = new_animal;
  if (new_animal < 1 ) {
    animal = 1; 
  }
   else  if (new_animal > 8) {
   animal = 8;
   } // in main i need to cout error messages. this why we are clamp
 
 name = new_name;
 prev = new_prev;
 next = new_next;
 address = new_address;
 url = new_url;

  }
  int get_new_animal() {
    return animal;
  }
    
  void set_animal( int new_animal) {
      if (new_animal < 1 ) {
           animal = 1; 
           }
   else  if (new_animal > 8) {
        animal = 8;
        }
       else animal = new_animal;
  }
    
  string get_name() {
  return name;
  }
void set_name(string new_name) {
    name = new_name;
}
string get_address(){
return address;
}
void set_address(string new_address) {
address = new_address;
}
string get_url(){
return url;
}    
void set_url( string new_url) {
    url = new_url;
}
};

// new class
class List {
    LL *head = nullptr;
    LL *tail = nullptr;
    int size = 0;
  public:
    List() {} //Set above
    ~List() { //This should free all memory allocated in this list
        while (head) {
            LL *tmp = head;
            head = head ->get_next();
            delete tmp;
        }
        //YOU:  ne delete for every new
    }
    int get_size() {
        return size;//YOU
    }
 
    string print_list() {
        LL *temp = head;
        ostringstream ss; //This lets us write to a string like we do to cout
        if (!temp) {
            ss << "Empty List\n";
            return ss.str(); //Converts the stringstream to a string so we can return it
        }
        while (temp) {
            ss << "Province: " << left << setw(12) << temp->get_province() << " Cost: " << temp->get_cost() << endl;
            temp = temp->get_next();
        }
        return ss.str();
    }

    string insert_at_beginning(int cost, string province) {
        string retval = province + " inserted";
        LL *new_node = new LL(cost, province, nullptr, head);
        if (size == 0) tail = new_node;
        else head->set_prev(new_node); //WTF is this for kerney!!!
        head = new_node;
        size++;
        return retval;
    }
    string insert_at_end(int cost, string province) {
        string retval = province + " inserted";
        LL *new_en = new LL(cost, province, tail, NULL);
        if (size == 0) {
      head = new_en;
        } else tail -> set_next(new_en); //WTF again`:
        tail = new_en;
        size++;//YOU
        return retval;
    }
    //This function will delete a single node from the LL with a cost <= amount
    //amount_out will hold how much change was left over after the delete was done
    //It will return sentence containing "X deleted\n" (if node X was deleted) or "Nothing deleted"
    string delete_amount(int amount, int &amount_out) {
        string s; //Will be set to the province name deleted
        LL *ptr = head;
        if (head == NULL) {
            //YOU: First, handle the list being empty
            return "Nothing deleted";
        }

        //YOU: Second, handle there being one element in the list
        else if (head == tail && head->get_cost() <= amount) {
            head = NULL;
            tail = NULL;
            amount_out = amount -  ptr->get_cost();
            s = ptr-> get_province();
            delete ptr;
            size--;
            return s + " deleted";
        } else {
            //YOU: Third, handle deleting from the head or tail
            while (ptr) {
                //cout << "Looking at: " << ptr->get_province() << endl;
                if (ptr == head && ptr-> get_cost()  <= amount) {
                    head->get_next()->set_prev(NULL);  
                    head = head ->get_next();
                    amount_out = amount -  ptr->get_cost();
                    s = ptr->get_province();
                    delete ptr;
                    size--;
                    return s + " deleted";
                }


                else if (ptr == tail && ptr-> get_cost() <= amount) {
                    ptr->get_prev()->set_next(NULL); // set_next takes in what our next should be
                    tail = tail->get_prev();
                    amount_out = amount -  ptr->get_cost();
                    s = ptr->get_province();
                    delete ptr;
                    size--;
                    return s + " deleted";
                }
                //YOU: Handle deleting from the middle of the list
                else if (ptr->get_cost() <= amount) {
                    ptr->get_prev()->set_next(ptr->get_next());
                    ptr->get_next()->set_prev(ptr->get_prev());
                    amount_out = amount - ptr->get_cost();
                    s = ptr->get_province();
                    delete ptr;
                    size--;

                    return s + " deleted";
                }
                ptr = ptr->get_next();

            }
        }
        return "Nothing deleted";
    }
};

