CIT245-Data-Structures-Cpp  
Assignments from CIT245 - Data Structures and Programming C++  
  
Assignment Prompt:  
Write a program that uses a function that returns a number between 1 and 6.  
Use this function to simulate the roll of a die.  
Allow the user to specify the number of trials and then tabulate that number of rolls of two dice.  
The program must allow for repeated simulations. Initialize rand() using srand() and time().  
  
Possible Outcomes for any roll  
11 12 13 14 15 16  
21 22 23 24 25 26  
31 32 34 35 36 37  
41 42 43 44 45 46  
51 52 53 54 55 56  
61 62 63 64 65 66  
  
Possible Totals    
 2  3  4  5  6  7  
 3  4  5  6  7  8  
 4  5  6  7  8  9  
 5  6  7  8  9 10  
 6  7  8  9 10 11  
 7  8  9 10 11 12  
  
Therefore, for example, the odds of a 7 are 6:36 in any given roll.  
  
If you roll 36 times then the expected outcome for a 7 is 6.  
So odds are that you will get a 7, 6 times.  
The odds you will get a 2 are 1.  
Tabulate the difference between the expected outcome (odds) and the random number generator outcome – list this as error.  
  
In general, you should notice a decrease in error with more trials.  
