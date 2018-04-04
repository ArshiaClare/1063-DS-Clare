```
///////////////////////////////////////////////////////////////////////////////
//                   YOU MUST COMPLETE AND COMMENT YOUR CODE!
// Title:            Program 2
// Files:            priority_queue.cpp
//                     input_data.txt
// Semester:         CMPS 1063 Spring 2018
//
// Author:           Arshia Clare
// Email:            arshiaclare@gmail.com
// Description:
//This program reads in two words; first one is the condition to push or pop 
//and second one is the word that is added to the list. Then in the push method
//the program will sort the input words in the order of high priority 
//(smallest words) and by alphabethic order. 
//Then when the pop method is implicated the word with the
//highest priority comes out first.
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////
// List Based Queue
//
// First In First Out
//
// Method:
//    void push()
//    string pop()
//    bool empty()
//    void LeftOvers()
//
/////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
* Struct Node
* creates a node that contains both val and the next pointer.
* 
* Params:
* None
* Returns: 
* none
* it is simply for our usage  
*/
struct Node
{
  string val;
  Node *next;
  Node()
  {
    val = " ";
    next = NULL;
  }
  Node(string v)
  {
    val = v;
    next = NULL;
  }
};

/**
* class Queue
*     it uses the methods to make a queue list!
* Methods:
*  - Queue()       : constructor
*  - string pop()  : pop method without parameters
*  - void push(string v) : push method with parameters
*  - bool empty() : checks if the list is empty and alerts us
*  - bool pop(string &v) : pop method with parameters
*  - void LeftOvers(ofstream &outfile) : prints anything not popped.
*/
class Queue
{
  private:
    Node *Front;
    Node *Rear;

  public:
    /**
   * Queue
   * constructor 
   * base case the list is empty
   * params:
   *     - none
   * purpose: sets Front and Rear to NULL
   * returns:
   *    - none
   */
  Queue()
  {
    Front = Rear = NULL;
  }

    /**
   * pop()
   * it pops an item off the Queue
   * it modifies Front
   * 
   * params: none
   * returns: string 
   * it is either an answer or prints "error: cannot pop off empty queue." with " "
   * 
   */
  string pop()
  {
    if (!empty())
    {
      Node *temp = Front;   // temp pointer so we can delete node
      string v = temp->val; // grab value out of node
      Front = Front->next;  // move pointer to next node
      delete temp;          // give mem back to system
      return v;
    }
    else
    {
      cout << "error: cannot pop off empty queue." << endl;
      return " ";
    }
  }
    
    /**
  * Function Push:
  *      Pushes an item (the animal name) onto the queue.
  *       it sorts the names into the priority queue in this method
  * Params:
  * it is a string v
  * v is the animal name
  *      
  * * Returns
  *      void
  */
  void push(string v)
  {
    Node *n = new Node(v);
    Node *temp = Front;      //temp points to Front
    Node *temp2 = NULL;      //new node is created
    //it checks the conditions for
    //Front reaching NULL and
    //temp's value's length comparing with the length of the number read in
    //location for new node
    while(temp != NULL && temp->val.length() < v.length()){
      //temp2 follows temp
      temp2 = temp; 
      temp = temp->next;
    }
    //location for new node
    //this one is for same length in alphabethic order
    while(temp != NULL && temp->val.length() == v.length() && v > temp->val){
        //temp2 follows temp
        //swaps 
      temp2 = temp; 
      temp = temp->next;
    }
     
    // handles the empty case
    if (empty())
    {
      Front = n;
      Rear = n;
    }
    
    //this is where the insert happens
    else if(temp2 == NULL){
      n->next = Front;
      Front = n;
    }
    
   else{
      temp2->next = n;  //next pointer of temp2 points to n
      n->next = temp;   //its linking the pointers
    }
    
    
  }
   /**
* Function empty:
*   is called to check if the queue is empty if so then Front doesn't exist
* 
* Params:None
*
* Returns
*      bool : it checks if the statement is true or false
*     if true then we know the queue is empty.
*       
*/
  bool empty()
  {
    return (Front == NULL);
  }
  /**
  * Function print: If the function is called then we print from Front
  * Params: None
  * Returns: void
  * it cout the temporary node created not Front itself
  */

  void print()
  {
    Node *temp = Front;
    while (temp){
      cout << temp->val << "->";
      temp = temp->next;
    }
    cout << endl;
  }
/**
 * pop(string &v)
 * it pops an item off the Queue
 * it modify Front
 * 
 * params: is a pass by reference
 * returns: bool
 * if it is true then the word is popped of the list using the temp and Front. Front is stored in temp which then moves the pointer to the next val (so it is not lost). THen temp is deleted.
 * false: it is prints "error: cannot pop off empty queue."
 * 
 */

 bool pop(string &v)
 {
   if (!empty())
   {
     Node *temp = Front;   // temp pointer so we can delete node
     string t = temp->val; // grab value out of node
     Front = Front->next;  // move pointer to next node
     delete temp;          // give mem back to system
     v = t;
     return true;
     }
     else
     {
       cout << "error: cannot pop off empty queue." << endl;
       return false;
      }
    }
    
    /**
 * Remainder(ofstream &outfile)
 * the method has Front stored in temp
 * this method is accessed after the pop method so it prints the words that didn't pop off. 
 * params: outfile called
 * returns: void
 * 
 */
  
  void LeftOvers(ofstream &out){
    //n points to Front
    Node *n = Front;
    //The header
    out << endl << endl;
    out << "Animals Remaining on the Queue (in order of priority): \n";
    //if its not empty
    //it'll outfile the remaining queue
    while(!empty()){
      out << n->val << endl;
      n = n->next;
    }
  }
};

int main()
{
  //input_data.txt is called
  ifstream infile;
  infile.open("input_data.txt");
  
  //priority_out.txt is created
  ofstream outfile;
  outfile.open("priority_out.txt");
  
  Queue Q;
  string animal; // animal name
  string cond; // cond is condition/method so it can be push or pop
  outfile << "Arshia Clare\n";
  outfile << "Program 2\n\n";
  outfile << "Animals Popped off the Queue:\n";
  while(infile >> cond)
  {
    infile >> animal;
    //condition is push
    //cout << cond << endl;
    if (cond == "push"){
      Q.push(animal);
      cout << "i push: " << animal << endl;
    }else{
      //condition is pop
      Q.pop(animal);
      outfile  << animal << endl;
    }
  }
  Q.LeftOvers(outfile);
}
```
