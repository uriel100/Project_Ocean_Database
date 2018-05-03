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
  if ( animal < 1 ) {
    animal = 1; 
  }
   else  if (animal > 8) {
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
  animal = new_animal;
  }

};
