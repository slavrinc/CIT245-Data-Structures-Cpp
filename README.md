CIT245-Data-Structures-Cpp  
Assignments from CIT245 - Data Structures and Programming C++  
  
Assignment Prompt:
Make a program that can write advice to a file.  Your program should not require a data file to be present when it is run.  If a file needs to be created, your program should do so.

According to ANSI standards, all compilers should operate the same way.  Naturally they do not.  David Busch one of my Spring 2011 students, managed to come up with code that worked with both MSVC++ and DevC++.

In MSVC++ his code:

inStream.open("advice.txt");

When no file is present, passes the test:

    // Does this file exist?
    if (!inStream.fail())  // file exists...

Because MS has decided to create a file if none exists.  I believe this is not ANSI standard but is more convenient for a programmer.

For DevC++, his code:

        if (!inStream.fail()){  // file exists…
        here is code to read in the orginal advice.  Of course in MSVC++ the file is empty.
    } 
    else{    // This file does NOT exist.
        inStream.close(); // close the input file stream
        inOutStream.open("advice.txt", ios::in | ios::out | ios::trunc);  // create new file
    } 

Handles the case where no file exists and one must be created. I suggest using this approach since it is compiler independent.

Important:  Note that there are 3 types of file streams, an ofstream only does output, an ifstream only does input.  If you want input and output on the same file you use an fstream.  inStream.open("advice.txt",ios::app); will always cause an error if you declared ifstream inStream; Unfortunately, it will compile but will always fail at run time because you are trying to append to an input stream.


