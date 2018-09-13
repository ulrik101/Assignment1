#include "Header.h"

bool continueApp = true;//


void setContinueApp(bool localContinueApp)//setter
{
	continueApp = localContinueApp;
}


int main()
{
	outputFileCreate();
	do {
		promptUserNextList();
	} while(continueApp == true);

  return EXIT_SUCCESS;
}
