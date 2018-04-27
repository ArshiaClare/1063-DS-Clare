//Name: Arshia Clare
//Filename: DBList.h

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node{
  string Data;

  Node *Prev;
  Node *Next;
  Node(string x){
      Data = x;
      Prev = NULL;
      Next = NULL;
  }
};

struct DBList{

    Node *Head;
    Node *Tail;
    Node *Current;
    Node* _Find(string);

    DBList();
    void InsertFront(string);
    void InsertFront(Node*&);
    void InsertRear(string);
    void InsertRear(Node*&);
    bool Delete(string);   //Removes item from list
    bool Find(string);     //Locate and see if exists
    bool Update(string,string);   //Change existing value
    void Print(ofstream&);
    void Print(int,ofstream&);
    
    //functions that i added:
    string MoveIt(int);   //moves right and left
    string DeleteNode(Node*); //deleting the node
    void Header(ofstream&); //prints header
    

};
