CIT245-Data-Structures-Cpp  
Assignments from CIT245 - Data Structures and Programming C++  
  
Assignment Prompt:  
Write a class that represents a player in a game.  
The player should have a name, password, experience points, an inventory array of four strings, and a location x,y.  
Your class should have mutator and accessor methods for all variables.  
For example: setName(), getName().  
It should have a suitable display method. Mutators and accessors should be public but all variables should be private.  
To implement get inventory, use string * getInv();  
Use the scope resolution operator to implement larger methods such as display().  
Use in class methods for shorter methods such as setName(), getName().  
  
Example:  
  
void setName(string name){this->name = name;}  
string *getInv();  
...  
string* player::getInv(){return inventory;}  
  
Note that in the above method setName “this->” is required for disambiguation. If written  
void setName(string n){name = n;}  
“this->” is not required.  
  
Write a test program that creates three players and displays them.  
  

