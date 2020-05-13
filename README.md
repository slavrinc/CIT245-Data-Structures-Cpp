CIT245-Data-Structures-Cpp  
Assignments from CIT245 - Data Structures and Programming C++  
  
Assignment Prompt:  
Create an int  i with a value of 7.  
Create a pointer to integer pi.  
Point your pointer pi to your int variable i.  
Print out your pointer, the address of your pointer and a dereference of your pointer.  
  
Create a pointer to your integer pointer ppi.  
Point it to your pointer to int pi.  
Print out ppi, the address of ppi, a dereference to ppi and a double dereference to ppi.  

Part 2  
  
Understanding deep vs. shallow copy is essential for a programmer.  
You will get into severe problems trying to code if you do not understand it.  
  
The essence of the problem is that 2 objects, which should have independent memory storage, accidently wind up sharing memory.  
  
I want you to wrap a character array (and array with 'a','b','c','d','e' is strictly speaking not a string since it does not end in '\0') with a class (this is just a class that contains an array) and then properly(in Deep) and improperly (in Shallow) assign memory.  
  
Make a class WrapArrayDeep that has a private pointer to char.  
Your default constructor should allocate an array of size 5.  
You should have a copy constructor that does a deep copy. (allocates a new array)  
  
Make a similar class, WrapArrayShallow, that has an improper copy constructor that causes your copy to point to the array in the source object. (instead of making a new array, have pch point to the original array)  
  
Demonstrate the difference between the classes use   
WrapArrayDeep  wad1, *wad2;   
for the variables holding your WrapArrayDeeps and for WrapArrayShallow:   
WrapArrayShallow  was1, *was2;   
  
Be sure to include a destructor in each class – note it must be an ARRAY destructor put a cout in the destructor showing it was called..  
  
In WrapArrayDeep:  
Use pointer arithmetic to load your array with ASCII values for letters.  
*pca = 97;  
*(pca+1) = 98;  
etc.  
Use array notation to print your array.  
for(int I = 0; I < 5; I++)  
   cout << pca[i] << endl;  
  
In WrapArrayShallow:  
Use array notation to load your array with char data.  
pca[0]='v';  
pca[1]='w';  
etc  
Use pointer arithmetic to print your array.  
for(int I = 0; I < 5; i++)  
   cout << *(pca + 1) << endl;  

