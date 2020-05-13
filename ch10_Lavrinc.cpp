/*  Samantha Lavrinc
	03-03-2020 ~ CIT 245-701B
	This program demonstrates pointers and wrappers.*/

#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

class WrapArrayDeep {
public:
    WrapArrayDeep();

    // The big three :
    WrapArrayDeep(const WrapArrayDeep& array);
    WrapArrayDeep& operator =(const WrapArrayDeep& array);
    ~WrapArrayDeep();

    void display();
    void change();

private:
    int arrSize = 5, abcstart = 97, symstart = 123;
    char* pch= new char[arrSize];
};

class WrapArrayShallow {
public:
    WrapArrayShallow();
    WrapArrayShallow(const WrapArrayShallow& was);
    ~WrapArrayShallow();
    void display();
    void change();

private:
    int arrSize = 5, abcstart = 97, symstart = 123;
    char* pch = new char[arrSize];
};

void wrapperSection() { 
    // created w/separate function to reflect 
    // objects destructed beyond scope

    //deep
    WrapArrayDeep wad1, *wad2;
    wad2 = new WrapArrayDeep(wad1);

    //shallow
    WrapArrayShallow was1, *was2;
    was2 = new WrapArrayShallow(was1);

    cout << "\n-----------------------------" << endl;
    cout << "\nThis program section instantiates a wrapper class"
         << "\nfor a dynamic array of 5 elements" << endl;

    cout << "\nWrapArrayDeep 1 = " << endl;
    wad1.display();

    cout << "WrapArrayDeep 2 using the copy constructor on 1 = " << endl;
    wad2->display();

    cout << "changing contents of WrapArrayDeep1... " << endl;
    wad1.change();
    wad1.display();
    wad2->display();

    cout << "\nWrapArrayShallow 1 = " << endl;
    was1.display();

    cout << "WrapArrayShallow 2 using the copy constructor on 1 = " << endl;
    was2->display();

    cout << "changing the contents of WrapArrayShallow1... " << endl;
    was1.change();
    was1.display();
    was2->display();

    cout << "\nremoved destructor for WrapperArrayShallow" << endl;
    //delete was2; crashed compiler
    delete wad2;
}

int main() {
    int i = 7;
    int* pi = &i;
    int** ppi = &pi;

    cout << "This program section uses 3 variables" << endl;
    cout << "i = 7, pi = pointer to i, ppi = pointer to pi" << endl;

    cout << endl;
    cout << "pi = " << pi << endl;
    cout << "dereference pi = " << *pi << endl;
    cout << "address of pi = " << &pi << endl;
    cout << "address of i = " << &i << endl;

    cout << endl;
    cout << "ppi = " << ppi << endl;
    cout << "dereference of ppi = " << *ppi << endl;
    cout << "address of ppi = " << &ppi << endl;
    cout << "double dereference of ppi = " << **ppi << endl;

    wrapperSection();
  
    cout << "\n-----------------------------" << endl;
    cout << "\nDemo Complete. Exiting... " << endl;
    system("PAUSE");
    return 0;
} 

WrapArrayDeep::WrapArrayDeep() {
    *pch = abcstart;
    for (int i = 1; i < arrSize; i++) {
        *(pch + i) = (abcstart + i);
    }
} 

WrapArrayDeep::WrapArrayDeep(const WrapArrayDeep& array){
    *pch = abcstart;
    for (int i = 1; i < arrSize; i++) {
        *(pch + i) = array.pch[i];
        }
}

WrapArrayDeep& WrapArrayDeep::operator =(const WrapArrayDeep& array) {
    if (arrSize != array.arrSize) {
        delete [] pch;
        pch = new char[array.arrSize];
    }

    arrSize = array.arrSize;
    for (int i = 0; i < arrSize; i++) {
        pch[i] = array.pch[i];
    }
    return *this;
}

WrapArrayDeep::~WrapArrayDeep() {
    cout << "calling destructor for WrapArrayDeep" << endl;
    delete [] pch;
} 

void WrapArrayDeep::display() {
    for (int i = 0; i < arrSize; i++) {
        cout << pch[i] << " ";
    }
    cout << endl;
} 

void WrapArrayDeep::change() {
    *pch = symstart;
    for (int i = 1; i < arrSize; i++) {
        *(pch + i) = (symstart + i);
    }
}

WrapArrayShallow::WrapArrayShallow() {
    *pch = abcstart;
    for (int i = 1; i < arrSize; i++) {
        pch[i] = (abcstart + i);
    }
}

WrapArrayShallow::~WrapArrayShallow() {
    cout << "calling destructor for WrapArrayShallow" << endl;
    delete [] pch;
} 

WrapArrayShallow::WrapArrayShallow(const WrapArrayShallow& array) {
    pch = array.pch;
}

void WrapArrayShallow::display() {
    for (int i = 0; i < arrSize; i++) {
        cout << *(pch + i) << " ";
    }
    cout << endl;
}

void WrapArrayShallow::change() {
    *pch = symstart;
    for (int i = 1; i < arrSize; i++) {
        pch[i] = (symstart + i);
    }
} 
