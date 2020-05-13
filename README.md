CIT245-Data-Structures-Cpp  
Assignments from CIT245 - Data Structures and Programming C++  
  
Assignment Prompt:  
You should know inheritance from Java but to get a chance to use C++ syntax, make a base class gun.  
Gun should have  
	    string manufacturer;  
	    string caliber;  
  
handgun should inherit from gun and add  
  
	string grips;  
	string sights;  
	bool laser;   
  
Finally have classes revolver and pistol that inherit from handgun.  Revolver should add:  
	bool singleAction;  
	int numberOfRounds;  
Pistol should have:  
	bool semiauto;  
  
Make good decisions about constructors, private variables, mutators and accessors.  
  
Make an appropriate test program by instantiating and printing at least one revolver and one pistol.  
  
Example Output:  
  
Revolver: Smith & Wesson, 0.357, 6 shot, double action, hoague grips, laser, Trijicon  
Pistol: Glock, 9mm, semi-auto, manufacturers grips, no laser, 3 dot sights  


