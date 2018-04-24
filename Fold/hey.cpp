/////////////////////////////////////////////////////////////////////////////////////////////
// ProgramName: Program Three - Survival of the Lucky
// Author: Arshia Clare
// Description: 
//     
// Course: 1063 Data Structures
// Semester: Spring 2018
// Date: 27 04 2018
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node{
  string Data;
  Node *Prev;
  Node *Next;
  Node(string x,Node *NewPrev = NULL, Node *NewNext = NULL){
      Data = x;
      Prev = NewPrev;
      Next = NewNext;
  }
};

class Animal{
private:
    Node *Head;
    Node *Tail;
    Node *Current;
public:
  Animal()
  {
    Head = Tail = Current = NULL;
  }
  
  void doublyLink(string word){
    if (Head == NULL){
      Head = new Node(word, Head, Head);
      Tail = Head;
      Current = Head;
    }
    else{
      Head->Prev = new Node(word, Tail, Head);
      Head = Head->Prev;
      Tail->Next= Head;
    }
  }
  
  void MoveIt(int move){
    if(move%2==0){
      for(int i=0; i<move; i++){
       Current = Current->Next;
      }
    }
    else{
      for(int i =0; i<move;i++){
        Current = Current->Prev;
      }
    }
  }
  
  void Delete(){
   
   //check empty
    if(Current!=NULL){
      Node* temp = Current;
      temp->Next->Prev = temp->Prev;
      temp->Prev->Next = temp->Next;
      temp=temp->Next;
      delete Current;
      Current = temp;
      
      if(Current==NULL)
        Head = Tail = Current = NULL;
    }
  }
  
  void Header(ofstream &outfile){
    outfile << "///////////////////////////////////////////////////////////////////\n";
    outfile << "// ProgramName: Program Three - Survival of the Lucky\n";
    outfile << "// Author: Arshia Clare\n";
    outfile << "// Description: \n";
    outfile << "// Course: 1063 Data Structures\n";
    outfile << "// Semester: Spring 2018\n";
    outfile << "// Date: 27 04 2018\n";
    outfile << "///////////////////////////////////////////////////////////////////\n\n\n";
  }

};

int main() 
{
  ifstream infile;
  infile.open("animals.txt");
  ofstream outfile;
  outfile.open("eliminated.txt");
  
  Animal K;
  string a;
  int count = 0; //how many animals
  int length = 0; //store animals' length
  int num = 0;  //the user prompted multiplier
  
  //Printing out the Header
  K.Header(outfile);
  
  //Load animals to doubly linked list
  while(infile >> a){
     K.doublyLink(a);
     count++;         //incrementing count of animals

  }
  infile.clear();
  //reset the file
  infile.seekg(0);
  
  cout << count << endl;
 //Prompting the user for multiplier between 1 and 13
    cout << "Please type a number in" << endl;
    cin >> num;
    //loops if the number doesn't fit in the range
    //continues unitl the user types the correct number
  while(num < 1 || num > 13){
      cout << "Please type another number!" << endl;
      cin >> num;
    }
    outfile << "This is the user prompted multiplier: " << num << endl;

  //read in the animal from the input
  while(infile >> a)
  {
    length = a.size() * num;
    K.MoveIt(length);
    

  }
  
  
}
