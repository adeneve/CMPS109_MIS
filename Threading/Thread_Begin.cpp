#include "Thread_Begin.h"
#include <iostream>
#include <mutex>

using namespace std;

//ruuThread -- Thread Function
// iterate through instructions, locking the variables map each time
static void runThread(map<string, Keyword*>* Keyword_Factory,map<string, Threading_Keyword*>* Thread_Factory,map<string, Type*>* variables,mutex* m, vector<thread>* threads, Parser* Parser1, Parser* Parser2, map<string, int>* Locked_Vars, int thread_id, ofstream* file){
  //Do 1 through to check for viable Labels TODO
  cout << "in thread" << endl;
  vector<string> args;
  if(Parser2 == NULL){
    cout << "parser has not been created" << endl;

   } else {
      while(Parser2->hasNextLine()){
         args = Parser2->getNextLine();
         cout << "args[0] is" + args[0] << endl;
         if(args[0] == "THREAD_END"){
                cout << "thread has seen end" << endl;
                return;
               }
         Keyword* KeywordObj;
         Threading_Keyword* ThreadObj;
         
         // lock checking, BETTER TO do lock checking in the keyword functions
         //for(int i = 0; i < args.size() ; i++){
           // while((*Locked_Vars)[args[i]] != 0){} // while variable is locked.
        // }
          // critical section
         // m->lock();
         if (args[0] == "VAR"){ 
          cout << "true1" << endl;
            KeywordObj = (*Keyword_Factory)[args[2]];
         } else {
            KeywordObj = (*Keyword_Factory)[args[0]];
            ThreadObj = (*Thread_Factory)[args[0]];
         }

         if(KeywordObj != NULL){
            try{
              
               KeywordObj = KeywordObj->clone(args, *variables, Parser2);
               KeywordObj->execute();
               
            }
            catch(exception & e){
               *file << e.what() << endl;
            }
            //char val;
            //MIS_variables["$mychar1"]->getValue(&val);
            //cout << val << endl;
         } else if(ThreadObj != NULL && KeywordObj == NULL){ 
                cout << "true2" << endl;
               if(args[0] == "THREAD_BEGIN"){
                  *file << "cant have nested threads" << endl;
               }
              //m->unlock();
               ThreadObj = ThreadObj->clone(args, variables, Parser2, Keyword_Factory, Thread_Factory, m, threads, thread_id, Locked_Vars, file);
               ThreadObj->execute();
              // m.lock();


         } else {
            *file << "Keyword does not exist." << endl;
            }
          //  m.unlock();
         }
      }
  
  

  }



//Prepare new Parsers at the correct Thread Begin Location
void Thread_Begin::initialize(vector<string> args, map<string, Type*>* variables, Parser* MIS_Parser, map<string, Keyword*>* Keyword_Factory,map<string, Threading_Keyword*>* Thread_Factory,mutex* m, vector<thread>* threads, int thread_id, map<string, int>* Locked_Vars, ofstream* file){
  this->thread_id = thread_id;
  cout << "in initialize" << endl;
  vector<string> args1;
  vector<string> args2;
  Parser* Parser1 = new Parser(MIS_Parser->getName());
  Parser* Parser2 = new Parser(MIS_Parser->getName());
  int Thread_Begins_Seen = 0;
  //configure new Parsers to start at the correct thread Begin
  while(Parser1->hasNextLine()){
    args1 = Parser1->getNextLine();
    args2 = Parser2->getNextLine();
    if(args[0] == "THREAD_BEGIN"){
      Thread_Begins_Seen++; 
      if(Thread_Begins_Seen == this->thread_id){
        break; //Parsers are at the correct location, let Parser1 track labels first.
      }
    }

  }
      //thread Factory_Thread(runThread, ref(Keyword_Factory), ref(Thread_Factory), ref(variables), ref(m) , ref(threads), ref(MIS_Parser), ref(instructions), ref(Locked_Vars), ref(this->thread_id)); // start the factory work on the chunk of code
      threads->emplace_back(thread(runThread, Keyword_Factory, Thread_Factory,variables,m,  threads, Parser1, Parser2, Locked_Vars, thread_id, file)); // will be used for barrier
     // Joining will be done by Barrier keyword
     //thread(runThread, Parser1, Parser2, Keyword_Factory, Thread_Factory, variables);
      

}

// Pass in regular data along with threading variables/structures
Threading_Keyword* Thread_Begin::clone(vector<string> args, map<string, Type*>* variables, Parser* MIS_Parser, map<string, Keyword*>* Keyword_Factory,map<string, Threading_Keyword*>* Thread_Factory,mutex* m, vector<thread>* threads, int thread_id, map<string, int>* Locked_Vars, ofstream* file){
	Threading_Keyword* newThread = new Thread_Begin();
  cout << "in clone" << endl;
	newThread->initialize(args, variables, MIS_Parser, Keyword_Factory, Thread_Factory, m, threads, thread_id, Locked_Vars, file);
	return newThread;
}

void Thread_Begin::execute(){}