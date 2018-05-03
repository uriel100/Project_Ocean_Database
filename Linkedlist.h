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
