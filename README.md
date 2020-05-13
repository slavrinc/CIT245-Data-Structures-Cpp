CIT245-Data-Structures-Cpp  
Assignments from CIT245 - Data Structures and Programming C++  
  
Assignment Prompt:  
Write a program that reduces a fraction to lowest terms.  
Two functions should be implemented.  
Function gcd should find and return the greatest common denominator and be called as g = gcd(num,den);. 
Function reduce(num,den); should call gcd to provide the lowest terms.  
The lowest terms should be returned via reference in num and den.  
  
Pseudo code for gcd is:  
function gcd(a, b)  
    while b ≠ 0  
       t = b  
       b = a mod b  
       a = t  
    return a   


