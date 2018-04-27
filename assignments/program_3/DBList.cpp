//Name: Arshia Clare
//Filename: DBList.cpp

#include <iostream>
#include <string>
#include <fstream>
#include "DBList.h"

using namespace std;

/*constructor:
/ purpose: sets Head, Tail and Current to NULL
/params: none
/base case the list is empty
*/
DBList::DBList(){
  Head = NULL;
  Tail = NULL;
  Current = NULL;
}

/*
/ Function: InsertFront 
/ Description:Inserts a value at the front of the list by calling 
/     actual insert with a node.
/ Params: string : data element to be inserted
/ Returns: none (void)
*/
void DBList::InsertFront(string Data){
  Node* Temp = new Node(Data);
  InsertFront(Temp);

}

/*
/Function: InsertFront  
/Description: Inserts a value at the front of the list
/ Params: Node*& : node to be appended to front
/Returns: none(void)
*/
void DBList::InsertFront(Node* &Temp){
  //empty list 
  //forming a node
  if(!Head){
    Head = Temp;
    Tail = Temp;
    Tail->Next = Head;
    Current = Temp;
    Head->Prev = Tail;
  }else{
    //links everything to each other to make a circular DLL
    Temp->Next = Head;
    Temp->Prev = Tail;
    Head->Prev = Temp;
    Tail->Next = Temp;
    Head = Temp;
    Current = Head;
  }
}

/*
/Function: InsertRear(Node*)
/Description: Inserts a value to the back of the list
/ Params: Node*& : passed from the other InsertRear(string)
/   used to link everything
/Returns: none(void)
*/

void DBList::InsertRear(Node* &Temp){
  //empty list 
  //calls InsertFront
  if(!Head){
    DBList::InsertFront(Temp);
  }else{
    //links everything to each other to make a circular DLL
    Tail->Next = Temp;
    Temp->Prev = Tail;
    Tail=Temp;
    Temp->Next = Head;
    Head->Prev = Tail;
    Current = Tail;
  }
}

/*
/ Function:InsertRear(string)
/ Description: Inserts a value at the rear of the list by calling 
/     actual insert with a node.
/ Params:string : data element to be inserted
/ Returns: none (void)
*/
void DBList::InsertRear(string Data){
  if(!Head){
    DBList::InsertFront(Data);
  }else{
    Node* Temp = new Node(Data);
    InsertRear(Temp);
  }
}


/*
/Function: Delete(string)
/Description: Checks if there is a node to actual delete.
/     it links the nodes together if there is more than 1 node 
/     then deletes the necessary pointer. If there is only one 
/     node it deletes then sets everything to NULL
/Params: string
/Returns: bool (true or false)
*/
bool DBList::Delete(string x){
  //One node 
  if(Head == Tail && Head->Data==x){
    delete Head;
    Head = NULL;
    Tail = NULL;
    Current = NULL;
    return true;
  //Beginning of list
  }else if(Head->Data == x){
    Head = Head->Next;
    Current = Head;
    delete Head->Prev;
    Head->Prev = Tail;
    return true;
  //End of list
  }else if(Tail->Data == x){
    Tail = Tail->Prev;
    delete Tail->Next;
    Tail->Next = Head;
    Current = Tail;
    return true;
  //Middle of list
  }else{
    Node* Location = DBList::_Find(x);
    if(Location){
      //very loopy
      Location->Prev->Next = Location->Next;
      Location->Next->Prev = Location->Prev;
      Current = Location->Next;
      delete Location;
      return true;
    }
  }
  return false; 
}

/*
/Function: Find(string)
/Params: string
/Returns: bool (true or false)
*/
bool DBList::Find(string x){
  return false;
}

/*
Function: Print(int,ofstream&)
Description: this is used in the program to print the final winner
    it checks where head is. the tail is printed.
Params: int, ofstream
Returns: nothing
*/
void DBList::Print(int columns,ofstream &outfile){
  Node *Temp = Head;
  int count = 1;
  
  while(Temp != Tail){
    Temp = Temp->Next;
    if(columns && count % columns == 0)
    count++;
  }
  outfile <<"Winner: " << Tail->Data<< "!!!" << endl;
}

/*
Function: Print(ofstream&)
Params: outfile
Returns: nothing (void)
*/
void DBList::Print(ofstream &outfile){
  DBList::Print(0,outfile);
}

/*
Function: _Find(string)
Description: it looks for a certain animal name and 
if it is found then it is returned. otherwise returns 
NULL
Params: string
Returns: Node
*/
Node* DBList::_Find(string key){
  Node* Temp = Head;
  
  while(Temp){
    if (Temp->Data == key){
      return Temp;
    }
    Temp = Temp->Next;
  }
  return NULL;
}

//things I have added
/*
/Function: MoveIt(int)
/Description: it takes in an int value. The value in the if/else statements
/     are mod to see if it is even or odd. If it is even it moves right, 
/     otherwise moves left. 
/Params: int value
/Returns: a string which is recieved from the Function DeleteNode()
*/

string DBList::MoveIt(int move){
  Node *temp = Current;  
  if(move%2==0)
  {
    for(int i=0; i<move; i++)
    {
      Current = Current->Next;
    }
    temp = Current;
  }
  else
  {
    for(int i =0; i<move;i++)
    {
      Current = Current->Prev;
    }
    temp = Current;
  }

    Current = Current->Next;
    return DeleteNode(temp);
  
}
/*
/Function: DeleteNode(Node*)
/Description: the function is called by MoveIt to check if temp
/     is Head or Tail or somewhere between, and it does the specific
/     move to make sure that it is still linked together before 
/     deleting the temp (Node). 
/Params: a Node
/Returns: string data value of temp
*/

string DBList::DeleteNode(Node* temp){
  if(temp == Head){
      Head = Head->Next;
    }
  if(temp == Tail){
      Tail = Tail->Prev;
    }
    temp->Prev->Next = temp->Next;
    temp->Next->Prev = temp->Prev;
    return temp->Data;
    delete temp;
}


/* 
/  Function: Header(ofstream&)
/  Description: It prints to the outfile the name of the program, my name, date,
/  program's description, and other info.
/  Params:  outfile
/  Returns: nothing
*/
void DBList::Header(ofstream &outfile){
  outfile << "///////////////////////////////////////////////////////////////////\n";
  outfile << "// ProgramName: Program Three - Survival of the Lucky\n";
  outfile << "// Author: Arshia Clare\n\n";
  outfile << "// Description: \n";
  outfile << "//The program lets the user enter in two values: random seed and multiplier.\n";
  outfile << "//This program reads in from the input file called the 'animals.txt',\n"; 
  outfile << "//then it stores the name into a doubly linked list(D.L.L).\n";
  outfile << "//The D.L.L. lets the pointer to go back and forward in the list and it is circular. \n";
  outfile << "//Then it is reset. The program calls the input again, but this time to to do the problem solving.\n"; 
  outfile << "//The length of each animal name is multiplied to the user given multiplier.\n";
  outfile << "//Then it moves right if the number is even, or otherwise it goes left.\n";
  outfile << "//Wherever it lands, then the animal is deleted and called in the main. \n";
  outfile << "//After all the deletes, there will be one animal name which is the winner.\n";
  outfile << "//All the answer (outfile reduced to save paper&easier printing) including\n";
  outfile << "//the order that the animals were deleted and the final winner is printed \n"; 
  outfile << "//in 'eliminated.txt'.\n\n";
  outfile << "// Course: 1063 Data Structures\n";
  outfile << "// Semester: Spring 2018\n";
  outfile << "// Date: 27 04 2018\n";
  outfile << "///////////////////////////////////////////////////////////////////\n\n\n";
}
