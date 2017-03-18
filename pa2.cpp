// Daniel Tymecki
// pa2.cpp aka Memory Manager

// Initialize preprocessor components
#include <iostream>
#include <stdexcept>
#include "pa2.h"
#include <string>
#include <cstring>

using namespace std;

// Main function relys on a command prompt input
int main(int argc, char**argv)
{
	// Initialize variables
	int choice = 0;
	bool best = false;
	// Sets a string named 'command' to represent the user's command line argument
	string command = argv[1];
	// Determines whether the user has chosen best or worse for the management style
	if(strcmp(command.c_str(),"worst") == 0)
	{
		cout<<"Using worst fit algorithm..."<<endl;
		best = false;		
	}
	else if(strcmp(command.c_str(),"best") == 0)
	{ 
		cout<<"Using best fit algorithm..."<<endl;
		best = true;		
	}
	// Builds Memory Manager object taking in the selected style as a boolean.
	Memory_Manager OS(best);
	// Initializes the Memory Manager (Named OS because it simiulates a basic Operating System)
	OS.initialize();
	// Loops menu until the user selects the option to quit
	do
	{
		// Calls function that prints menu that evaluates the user's choice and assigns it by reference
		OS.printMenu(choice);
		if (choice == 1)
		{
			// If choice is one, calls Memory Manager's Add function
			OS.Add();
		}
		else if (choice == 2)
		{
			// If choice is two, calls Memory Manager's Remove function
			OS.Remove();
		}	
		else if (choice == 3)
		{
			// If choice is three, prints out the the number of frags in memory using Memory Manager's frag calculator function
			cout << "There are " << OS.Frag_calc() << " fragment(s).\n";
		}	
		else if (choice == 4)
		{
			// If choice is four, prints out memory.
			OS.printMem();
		}
		
		else if (choice == 5)
		{
			// If choice is five, politely wishes the user well and exits the program
			cout << "Thanks for using MM! Having a great day! :)\n\n";
		}
	} while (choice != 5);
	return 0;
}
