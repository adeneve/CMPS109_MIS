#include "MIS.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

MIS::MIS(): Thread_id(0){
   Keyword_Factory["NUMERIC"] = new Numeric();
   Keyword_Factory["REAL"] = new Real();
   Keyword_Factory["CHAR"] = new Char();
   Keyword_Factory["STRING"] = new String();
   Keyword_Factory["ADD"] = new Add();
   Keyword_Factory["SUB"] = new Sub();
   Keyword_Factory["DIV"] = new Div();
   Keyword_Factory["MUL"] = new Mult();
   Keyword_Factory["ASSIGN"] = new Assign();
   Keyword_Factory["OUT"] = new Out();
   Keyword_Factory["SET_STR_CHAR"] = new SETSC();
   Keyword_Factory["GET_STR_CHAR"] = new GETSC();
   Keyword_Factory["JMP"] = new Jump();
   Keyword_Factory["JMPGTE"] = new JumpGTE();
   Keyword_Factory["JMPLTE"] = new JumpLTE();
   Keyword_Factory["JMPGT"] = new JumpGT();
   Keyword_Factory["JMPLT"] = new JumpLT();
   Keyword_Factory["JMPZ"] = new JumpZ();
   Keyword_Factory["JMPNZ"] = new JumpNZ();
   Keyword_Factory["LABEL"] = new Label();
   Keyword_Factory["SLEEP"] = new Sleep();

   Thread_Factory["THREAD_BEGIN"] = new Thread_Begin();
   Thread_Factory["LOCK"] = new Lock();
   Thread_Factory["UNLOCK"] = new Unlock();
   Thread_Factory["BARRIER"] = new Barrier();
      
};

MIS::~MIS(){
}


void MIS::makeParser(string fileName){
	MIS_Parser = new Parser(fileName);
}

void MIS::run(){

	vector<string> args;
   ofstream file;
   string err_name = MIS_Parser->getName() + ".err";
   file.open(err_name, ofstream::app);

	if(MIS_Parser == NULL){
		cout << "parser has not been created" << endl;
   } else {
      while(MIS_Parser->hasNextLine()){
         args = MIS_Parser->getNextLine();
         Keyword* KeywordObj;
         Threading_Keyword* ThreadObj;
         
         // lock checking
        // for(int i = 0; i < args.size() ; i++){
        //    while(Locked_Vars[args[i]] != 0){} // while variable is locked.
        // }
        // m.lock();
          // critical section

         if (args[0] == "VAR"){ 
            KeywordObj = Keyword_Factory[args[2]];
         } else {
            KeywordObj = Keyword_Factory[args[0]];
            ThreadObj = Thread_Factory[args[0]];
         }

         if(KeywordObj != NULL){
            try{
              // m.unlock();
               KeywordObj = KeywordObj->clone(args, MIS_variables, MIS_Parser);
               KeywordObj->execute();
              // m.lock();
            }
            catch(exception & e){
               file << e.what() << endl;
            }
            //char val;
            //MIS_variables["$mychar1"]->getValue(&val);
            //cout << val << endl;
         } else if(ThreadObj != NULL && KeywordObj == NULL){ 
               if(args[0] == "THREAD_BEGIN"){
                  Thread_id++; // thread counter is used to ID the threads
                  //CALL thread function.
                  while(MIS_Parser->hasNextLine()){
                     if(MIS_Parser->getNextLine()[0] == "THREAD_END"){
                        cout << "found END" << endl;
                        break;
                     }
                  }

               }
              //m.unlock();
               ThreadObj = ThreadObj->clone(args, &MIS_variables, MIS_Parser, &Keyword_Factory, &Thread_Factory, &m, &Threads, Thread_id, &Locked_Vars, &file);
               ThreadObj->execute();
              // m.lock();


         } else {
            file << "Keyword does not exist." << endl;
            }
            //m.unlock();
         }
      }
   file.close();
   
}
