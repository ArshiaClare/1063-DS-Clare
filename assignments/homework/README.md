/*  Name: Arshia Clare
**  Date: April 9, 2018
**  Class: CMPS 1063
**  Homework (A15)
*/

#include <iostream>
#include <ctime>

using namespace std;
struct node{
  int data;
  node* next;
};

class intLinkedList{
  private:
  node* Head;
  public:
  intLinkedList(){
    Head = NULL;
  }
  void insert(int x){
    //empty list case
    if(!Head){
      Head = new node;
      Head->data = x;
      Head->next = NULL;
    }else{//not empty list
      node* T = new node;
      T->data = x;
      T->next = Head;
      Head = T;
    }
  }
  
  node* Find(int key){
    node* temp = Head;
    while(temp){
      if(temp->data == key){
        return temp;
      }
      temp = temp->next;
    }
    return NULL;
  }
  
  node* Remove(int key){
    node* result = Find(key);
    if(result){
      node* temp = Head;
      while(temp->next != result){
        temp = temp->next;
      }
      temp->next = result->next;
      delete result;
    }
  }
  
  void print(){
    node* p = Head;
    while(p){
      cout<<p->data<<" ";
      p = p->next;
    }
    cout<<endl;
  }
  
  void divideByX(int x){
    node* banana = Head;
    
    while(banana){
      banana->data /= x;
      banana = banana->next;
    }
  }
  
  //assumptions are list is >= length(2);
  // swaps sets of neighbors
  // 1: head->A->B->C->D->NULL
  // 2: head->B->A->D->C->NULL
  void EvenswapNeighbors(){
    node* prev = Head;
    node* temp = Head->next;
    node* check = Head;
    int tempvar;
    
    while(prev->next->next != NULL){
      tempvar = temp->data;
      temp->data = prev->data;
      prev->data = tempvar;
      temp = temp->next->next;
      prev = prev->next->next;
    }
    //for even number of values in the list
    if(prev->next->next == NULL){
      tempvar = temp->data;
      temp->data = prev->data;
      prev->data = tempvar;
    }
  }
  //assumptions are list has odd number of values;
  // swaps sets of neighbors
  // 1: head->A->B->C->D->E->NULL
  // 2: head->B->A->D->C->E->NULL
  void OddswapNeigbors(){
    node* prev = Head;
    node* temp = Head->next;
    node* check = Head;
    int tempvar;
    
    while(temp->next->next != NULL){
      tempvar = temp->data;
      temp->data = prev->data;
      prev->data = tempvar;
      temp = temp->next->next;
      prev = prev->next->next;
    }
    //for odd number of values in the list
    if(temp->next->next == NULL){
      tempvar = temp->data;
      temp->data = prev->data;
      prev->data = tempvar;
    }
  }
  
};

int main() {
  srand(8734587);

  intLinkedList mylist;
  int size = 10;
  for(int i=0;i<size;i++){
    mylist.insert(rand()%100);
  }
  mylist.print();
  if((size)%2 == 0)
  {
    mylist.EvenswapNeighbors();
  }
  else if((size)%2 != 0){
    mylist.OddswapNeigbors();
  }
  mylist.print(); 
}
