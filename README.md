CIT245-Data-Structures-Cpp  
Assignments from CIT245 - Data Structures and Programming C++  
  
Assignment Prompt:  
Use an STL stack to reverse a line of input characters that are read into a string.  
Your stack should contain the characters of the user's string.  
Use getline() for input – it needs to be part of your C++ tool inventory.  
  
A note on getline:  Suppose I am doing the following -  
  
This program reverses a string using the STL stack  
Enter your string of less than 80 characters followed by an ENTER  
a string input  
Enter another? 1 = continue. Anything else to stop  
1  
Enter your string of less than 80 characters followed by an ENTER  
a second string  

This code will not work by simply using the following loop:  
  
	int go = 1;  
	cout << "This program reverses a string using the STL stack" << endl;  
	while(go == 1){  
		cout << "Enter your string of less than 80 characters followed by an ENTER" << endl;  
		char* s = (char *)malloc(80);  
		cin.getline(s,81,'\n');  
		cout << s << endl;  
		cout << "Enter another? 1 = continue. Anything else to stop" << endl;  
		cin >> go;  
	}  
  
Try it and see what happens!  Also note that I never got rid of the memory I allocated with malloc – your code must get rid of it.   Also, malloc outside the loop for more efficient code.  
  
You must use a getchar() (part of the cstdio library) after cin >> go;  
  
The reason is that when you enter 1 you also use the Enter key.  This is still in the buffer when you hit getline again!  
So you will read in '\n'   
  
Also note that when you get something off of the STL stack you must use .top() to look at it followed by .pop() to remove it.  


