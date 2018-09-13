#include "Header.h"

std::string generateDNALetter()//Used to generate Initial DNA letters
{
  std::string letter;
  std::string sequence = "AaCcTtGg";
  int randInt = rand() % 8;
  letter = sequence[randInt];
  return letter;
}

std::string generateDNA()//Used to generate Initial DNA sequences
{
  int dnaLength = rand() % 100;
  std::string sequence;
  for(int i = 0; i <= dnaLength; i++)
  {
    sequence+=generateDNALetter();
  }
  return sequence;
}
