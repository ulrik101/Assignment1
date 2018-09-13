#include "Header.h"

bool checkYNInput(std::string userInput)//Determines if the given input is a "y" or "n". Implemented to detect incorrect input
{
	if(userInput == "y" || userInput == "n")
	{
		return true;
	}
	else
	{
		return false;
	}
}


void promptUserNextList()
{
	std::cout << "Process other List? [y/n]" << std::endl;

	std::string userInput = "";
	std::cin >> userInput;
	if (checkYNInput(userInput)==true) {//checks whether or not input is a 'y' or 'n'
		if(userInput=="y"){
      fileProcess();
		}
		if(userInput=="n")
		{
      setContinueApp(false);
		}

	}
	else
	{
		std::cout << "Incorrect Input. Please use 'y' or 'n'" << std::endl;
	}
}
