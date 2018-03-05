//JumpOperation.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Abstract Base class for file input stream operations

#include "JumpOperation.h"

void JumpOperation::execute() {
   bool jump;
   if (this->jumpCondition()){
      P->goToLabel(name);
   }
   delete (this);
}
