#include "Header.h"
#include<fstream>
#include<cmath>

std::string fileName = "";
/*
void appendToFile(std::string fileName, std::string userString)//nursury method for early setup
{
  ofstream outputFile;
  outputFile.open(fileName, ios::out | ios::app );
  outputFile << userString << endl;
  outputFile.close();
}

void createList(std::string fileName)//nursury method for early setup
{
  ofstream outputFile;
  outputFile.open(fileName, ios::out | ios::app );
  for(int i = 0; i<1000; i++)
  {
    outputFile << generateDNA() << endl;
  }
  outputFile.close();
}
*/

void fileProcess()
{
  std::cout << "Insert Exact Name of File." << std::endl;
  std::cin >> fileName;
  ifstream file(fileName);
  if(file.is_open())//checks whether or not the file exists. If it does, it opens.
  {
    std::cout << "File Found " + fileName << std::endl;
    resultProcess();
    while(!file.eof())//continue while there is a next line.
    {
      std::string local_string;

      file >> local_string;
      int length = local_string.size();

      if(analyzeSequence(local_string, true))//checks whether or not sequence contains invaldi characters. ignores if invalid
      {
        addSum(length);
        addNumOfSeq();
      }
    }
    file.clear();
    file.seekg( 0, std::ios::beg );
    float mean = calcMean();


    //Second calculations for determining variance
    while(!file.eof())//continue while there is a next line
    {
      std::string local_string;
      file >> local_string;
      if(analyzeSequence(local_string, false))//checks whether or not sequence contains invaldi characters. ignores if invalid
      {
        addSumOfSquares(pow(local_string.size()- mean,2));
      }
    }
    printInfo();
    file.close();
  }
  else
  {
    std::cout << "No file was found. Be sure to enter the exact file name and extension." << std::endl;
  }
}


void outputFileCreate()//creates the out file
{
  ofstream outputFile;
  outputFile.open("David_Ulriksen.out");
  outputFile << "David Ulriksen\n002270761\nDA & CPSC MAJOR" << endl<< endl;
  outputFile.close();
}


void outputFileLabel()//labels the results of incoming dna statistical results
{
  ofstream outputFile;
  outputFile.open("David_Ulriksen.out", ios::out | ios::app );
  outputFile << endl;
  outputFile << fileName + " Results"<< endl<< endl;
}

void outputAppendResult(std::string resultString)//Appends Statistic results to out file
{
  ofstream outputFile;
  outputFile.open("David_Ulriksen.out", ios::out | ios::app );
  outputFile << resultString << endl;
  std::cout << resultString << std::endl;
  outputFile.close();
}
