//Parser.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Reads in .mis files and returns appropriate information to the MIS system

#ifndef PARSER
#define PARSER

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Label.h"

class Label; //forward declaration

class Parser{
   public:
      Parser(std::string filename);
      ~Parser();
      std::vector<std::string> getNextLine();
      void goToLabel(std::string name);
      bool hasNextLine();
      void insert(Label L);
      int getPosition();
      std::string getName();
   private:
      std::ifstream stream;
      std::vector<Label> labels;
      std::string name;
};

#endif