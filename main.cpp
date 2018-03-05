//main.cpp
//main class for running the MIS environment

#include <string>
#include <iostream>
#include "MIS/MIS.h"

int main(int argc, char* argv[]){
   string filename; 
   if (argc < 1) {
      cout << "Usage: MIS filename" << endl;
      return -1;
   }
   filename = argv[1];
   MIS* myMIS = new MIS();
   try {
      myMIS->makeParser(filename);
   } catch (exception& e) {
      
   }
   myMIS->run();
   delete(myMIS);
}
   