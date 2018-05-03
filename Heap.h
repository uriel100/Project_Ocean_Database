# include <iostream>
# include <cstdlib>
# include <cctype>
# include <string>
# include <vector>
# include <iterator>
# include <algorithm>

using namespace std;

Class LL {
private:
  int animal = 0;
  string address;
  string url;
  string name;
 
  
public:
  LL( int new_animal = 0, string new_name = " ", string new_address = " ", string new_url = " ", LL *new_prev = nullptr, LL *new_nect= nullptr)
    
 animal = new_animal;
 name = new_name;
 address = new_address;
 url = new_url;


};
