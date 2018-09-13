
#include <iostream>
using namespace std;

//functions within Assign1_Main.cpp
void setContinueApp(bool localContinueApp);

//functions within Assign1_UserInput.cpp
bool checkYNInput(std::string userInput);
void promptUserNextList();


//functions within Assign1_FileManagement.cpp.cpp
void appendToFile(std::string fileName, std::string userString);
void fileProcess();
void outputFileCreate();
void outputAppendResult(std::string resultString);
void outputFileLabel();

//functions within Assign1_DNA
std::string generateDNA();


//functions within Assign1Assign1_calculations
void addSum(int dnaLength);
void addSumOfSquares(float distFromMean);
void addNumOfSeq();
float calcMean();
float calcVariance();
float calcStanDev();
float calcProbability(int letterNum);
float calcBigramProbability(int letterNum);
void resultProcess();
bool analyzeSequence(std::string dnaSequence, bool doCalc);
void printInfo();
void createNewDna();
