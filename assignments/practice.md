```
//Arshia Clare
//Feb 26, 2018
//Extra Credit
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node{
  string word;
  Node* next;
  Node(){
    word = "";
    next = NULL;
  }
  Node(string w){
    word = w;
    next = NULL;
  }
};

class List{
private:
  Node* Top;
  int listSize;
  
public:
  List(){
    Top = NULL;
    listSize = 0;
  }
  
  void Push(string word){
    
    if(Top==NULL){
      //empty list easy fix
      Top = new Node(word);
    }else{
      //list is not empty so link it in
      //So I used the book to basically get the point of how to do it 
      //it is on page 1044. 
      Node* temp = Top;
      while (temp->next != NULL)
        temp = temp->next;
      temp->next = new Node(word);
      
      
    }
    
  }
  
  void Print(){
    Node* temp = Top;
    while(Top != NULL){
      cout<<Top->word<<" ";
      Top = Top->next;
    }
  }
  
  string Pop(){
    string word;
    
    return word;
  }
  
};

int main() {
  List L;
  string word;
  
  ifstream fin;
  
  fin.open("animals.txt");
  
  while(!fin.eof()){
    fin>>word;
    //cout<<word<<" ";
    L.Push(word);
  }
  
  L.Print();
  
}
```
