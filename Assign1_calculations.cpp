#include "Header.h"
#include<cmath>
#include<math.h>
#include<algorithm>
#include<sstream>
#include<iomanip>

//statistic variables
int A = 0;
int C = 0;
int T = 0;
int G = 0;


int AA = 0;
int AC = 0;
int AT = 0;
int AG = 0;
int CA = 0;
int CC = 0;
int CT = 0;
int CG = 0;
int TA = 0;
int TC = 0;
int TT = 0;
int TG = 0;
int GA = 0;
int GC = 0;
int GT = 0;
int GG = 0;

int totalChars = 0;
int totalBigrams = 0;

//operation variables
int sum = 0;
float sumOfSquares = 0.0;
int numOfSeq = 0;
float mean = 0.0;
float variance = 0.0;
float standardDev = 0.0;

void addSum(int dnaLength)//function to add to the sum
{
  sum+=dnaLength;
}
void addSumOfSquares(float distFromMean)//function to add together the squared sum
{
  sumOfSquares+=distFromMean;
}

void addNumOfSeq()//general counter for how many dna sequences there are
{
  numOfSeq+=1;
}

float calcMean()//calculates the mean
{
  mean = sum/numOfSeq;
  return mean;
}

float calcVariance()//calculates the variance of letters
{
  variance = sumOfSquares/(numOfSeq-1);
}

float calcStanDev()//calculates standard deviation of letters
{
  standardDev = sqrt(sumOfSquares/numOfSeq);
  return standardDev;
}

float calcProbability(int letterNum)//using ints and a switch to determine which letter probability to return
{
  float probability;
  int letterCount;
  switch (letterNum) {
    case 1:
    letterCount = A;
    break;
    case 2:
    letterCount = C;
    break;
    case 3:
    letterCount = T;
    break;
    case 4:
    letterCount = G;
    break;
  }
  probability = ((float)letterCount / (float)totalChars);
  return probability;
}
float calcBigramProbability(int letterNum)//using ints and a switch to determine which letter probability to return
{
  float probability;
  int BigramCount;
  switch (letterNum) {
    case 1:
    BigramCount = AA;
    break;
    case 2:
    BigramCount = AC;
    break;
    case 3:
    BigramCount = AT;
    break;
    case 4:
    BigramCount = AG;
    break;
    case 5:
    BigramCount = CA;
    break;
    case 6:
    BigramCount = CC;
    break;
    case 7:
    BigramCount = CT;
    break;
    case 8:
    BigramCount = CG;
    break;
    case 9:
    BigramCount = TA;
    break;
    case 10:
    BigramCount = TC;
    break;
    case 11:
    BigramCount = TT;
    break;
    case 12:
    BigramCount = TG;
    break;
    case 13:
    BigramCount = GA;
    break;
    case 14:
    BigramCount = GC;
    break;
    case 15:
    BigramCount = GT;
    break;
    case 16:
    BigramCount = GG;
    break;

  }
  probability = (float)BigramCount / (float)totalBigrams;
  return probability;
}
void resultProcess()//starts the result process by clearing variables
{
  A = 0;
  C = 0;
  T = 0;
  G = 0;

  sum = 0;
  sumOfSquares = 0.0;
  numOfSeq = 0;
  mean = 0.0;
  variance = 0.0;


  totalChars = 0;
  totalBigrams = 0;


  AA = 0;
  AC = 0;
  AT = 0;
  AG = 0;
  CA = 0;
  CC = 0;
  CT = 0;
  CG = 0;
  TA = 0;
  TC = 0;
  TT = 0;
  TG = 0;
  GA = 0;
  GC = 0;
  GT = 0;
  GG = 0;
}

bool analyzeSequence(std::string dnaSequence, bool doCalc)//analyzes dna sequence and calls sum functions
{
  if(dnaSequence=="")//blank check
  {
    return false;
  }
  int tempA = 0;
  int tempC = 0;
  int tempT = 0;
  int tempG = 0;

/*
  int tempAA = 0;
  int tempAC = 0;
  int tempAT = 0;
  int tempAG = 0;
  int tempCA = 0;
  int tempCC = 0;
  int tempCT = 0;
  int tempCG = 0;
  int tempTA = 0;
  int tempTC = 0;
  int tempTT = 0;
  int tempTG = 0;
  int tempGA = 0;
  int tempGC = 0;
  int tempGT = 0;
  int tempGG = 0;
*/
  std::transform(dnaSequence.begin(), dnaSequence.end(), dnaSequence.begin(), ::tolower);

  int currentCombo;

  tempA = std::count(dnaSequence.begin(), dnaSequence.end(), 'a');
  tempC = std::count(dnaSequence.begin(), dnaSequence.end(), 'c');
  tempT = std::count(dnaSequence.begin(), dnaSequence.end(), 't');
  tempG = std::count(dnaSequence.begin(), dnaSequence.end(), 'g');

  int tempTotal = tempA+tempC+tempT+tempG;
  if(tempTotal == dnaSequence.size())//checks if there are any characters beside ACTG
  {
    if(doCalc==true)//only calculate if specified.This way the function can be used only for proper characters
    {
      A +=tempA;
      C +=tempC;
      T +=tempT;
      G +=tempG;
      totalChars+=tempTotal;
      std::replace(dnaSequence.begin(),dnaSequence.end(),'a','1');
      std::replace(dnaSequence.begin(),dnaSequence.end(),'c','2');
      std::replace(dnaSequence.begin(),dnaSequence.end(),'t','3');
      std::replace(dnaSequence.begin(),dnaSequence.end(),'g','4');
      for(int i =0; i < dnaSequence.size()-1; i++)
      {
        currentCombo = stoi(dnaSequence.substr(i,2));//converts to int so that i can use a switch and not 16 god damn if statements
        totalBigrams +=1;
        switch (currentCombo) {

          case 11:
          AA+=1;
          break;
          case 12:
          AC+=1;
          break;
          case 13:
          AT+=1;
          break;
          case 14:
          AG+=1;
          break;
          case 21:
          CA+=1;
          break;
          case 22:
          CC+=1;
          break;
          case 23:
          CT+=1;
          break;
          case 24:
          CG+=1;
          break;
          case 31:
          TA+=1;
          break;
          case 32:
          TC+=1;
          break;
          case 33:
          TT+=1;
          break;
          case 34:
          TG+=1;
          break;
          case 41:
          GA+=1;
          break;
          case 42:
          GC+=1;
          break;
          case 43:
          GT+=1;
          break;
          case 44:
          GG+=1;
          break;
        }
      }
    }
    return true;//string is valid dna sequence
  }
  else
  {
    return false;//string is invalid dna sequence
  }
}
void printInfo()//processes information to be be printed to console and out file
{
  std::string allBigrams = "AAACATAGCACCCTCGTATCTTTGGAGCGTGG";
  std::cout << std::endl << "          Results" << std::endl << std::endl;
  outputFileLabel();//labels which files these are the results to

  outputAppendResult("A = " + to_string(A));
  outputAppendResult("C = " + to_string(C));
  outputAppendResult("T = " + to_string(T));
  outputAppendResult("G = " + to_string(G));
  outputAppendResult("Total Characters = " + to_string(totalChars));
  outputAppendResult("Total Bigrams = " + to_string(totalBigrams));
  outputAppendResult("A% = " + to_string(calcProbability(1)));
  outputAppendResult("C% = " + to_string(calcProbability(2)));
  outputAppendResult("T% = " + to_string(calcProbability(3)));
  outputAppendResult("G% = " + to_string(calcProbability(4)));
  for(int i = 0; i < 32; i+=2)//for printing the 16 bigram statements
  {
    float bigramProb = calcBigramProbability((i/2)+1);
    outputAppendResult(allBigrams.substr(i,2) + "% = " + to_string(bigramProb));
  }
  outputAppendResult("Mean = " + to_string(mean));
  outputAppendResult("Variance = " + to_string(calcVariance()));
  outputAppendResult("Standard Deviation = " + to_string(calcStanDev()));

  std::cout << std::endl << std::endl;

  //createNewDna();
}

float boxMuller()
{
  float a = (float)(rand() % 100)/100;
  //std::cout << "a: "<< a << std::endl;
  float b = (float)(rand() % 100)/100;
  //std::cout << "b: "<< b << std::endl;
  float c = (sqrt(-2*log(a))*cos(2*M_PI*b));
  //std::cout << "c: "<< c << std::endl;

  return c;
}

float randDnaLength()
{
  float d = variance*(boxMuller()) + mean;
  std::cout << "d: "<< d << std::endl;
  return d;
}

float roundFloat(float num)
{
  float rounded = floor(num + 0.5);
  std::cout << "rounded: "<< rounded << std::endl;
  return rounded;
}

void createNewDna()
{
  int remainingA = A;
  int remainingC = C;
  int remainingT = T;
  int remainingG = G;

  //std::cout << "Started" << std::endl;
  for(int i = 1; i <=20; i++)
  {
    std::string newSeq = "";

    int seqLen = (int)roundFloat(randDnaLength());

    std::cout << "Started next seq: "<< seqLen << std::endl;
/*
    for(int x = 1; x <= seqLen; x++)
    {
      newSeq+="a";
    }
    std::cout << newSeq << std::endl;
*/
  }
}
