//Label.cpp
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Sets a label a specific place in the input stream

#include "Label.h"
#include <iostream>

using namespace std;

Label::Label(int pos, string name){
   this->position = pos;
   this->name = name;
}

Label::Label(){}

Keyword* Label::clone(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   Label * label = new Label();
   label->initialize(rawData,typeVars,P);
   return label;
}

void Label::initialize(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   if (rawData.size() > 1){
      this->name = rawData[1];
      this->P = P;
      this->position = P->getPosition();
   } else {
      //throw new SyntaxException()
   }
}

void Label::execute(){
   P->insert(*this);
}

int Label::getPosition(){
   return position;
}

string Label::nameOf(){
   return name;
}