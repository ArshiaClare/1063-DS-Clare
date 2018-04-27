//////////////////////////////////////////////////////////////////////////
// ProgramName: Program Three - Survival of the Lucky
// Author: Arshia Clare 
// Description: 
//The program lets the user enter in two values: random seed and multiplier.
//This program reads in from the input file called the "animals.txt", 
//then it stores the name into a doubly linked list(D.L.L).
//The D.L.L. lets the pointer to go back and forward in the list and it is circular. 
//Then it is reset. The program calls the input again, but this time to to do the problem solving. 
//The length of each animal name is multiplied to the user given multiplier.
//Then it moves right if the number is even, or otherwise it goes left.
//Wherever it lands, then the animal is deleted and called in the main. 
//After all the deletes, there will be one animal name which is the winner.
//All the answer (outfile reduced to save paper&easier printing) including
//the order that the animals were deleted and the final winner is printed 
//in "eliminated.txt".
// Course: 1063 Data Structures
// Semester: Spring 2018
// Date: 27 04 2018
//////////////////////////////////////////////////////////////////////////////////////


//Filename: main.cpp

#include <iostream>
#include <fstream>
#include <string>

#include "DBList.h"

using namespace std;

int main() {
  
  DBList List;
  string a;       //a stores animals
  string b;       //b stores the animals "kicked" out
  int size = 0;   //size of the animal list
  int num = 0;    //is the user prompted value used as a multiplier
  int length = 0; //to store the animal's characters
  int rand = 0;   //is a user prompted value for the random seed
  
  
  //Prompting the user for a random value!
  cout << "Input a random seed, it can be between 0 to your liking" << endl;
  cin >> rand;    //reads in the value
  srand(rand);
  
  
  //output and input files called
  ifstream fin("animals.txt");
  ofstream outfile("eliminated.txt");
  
  //this function calls allows the user to see the programmer's info,
  //program info, and last update date.
  List.Header(outfile);
    
  //Loads the doubly linked list
  while(!fin.eof()){
    fin>>a;
    size++;         //keeps track of the number of animal names read in
    List.InsertRear(a); //this function call allows the creation of the doubly linked List
  }
    
  fin.clear();
  fin.seekg(0, std::ios::beg); // back to the start!
  
    
  //Prompting the user for multiplier between 1 and 13
  cout << "Please type a number in" << endl;
  cin >> num;       //reads it in
  //loops if the number doesn't fit in the range
  //continues unitl the user types the correct number
  while(num < 1 || num > 13){
    cout << "Please type another number!" << endl;
    cin >> num;
  }
  //allows the user to know which number they had chosen
  outfile << "This is the user prompted multiplier: " << num << endl;
  
    
    //reads from the input again
    while(!fin.eof()){
      fin>>a;
      //formatting
      outfile << "First: ";
      //this loops until size is 1 in which it breaks
      while(size>1){
        //length stores the number of characters in the animal name * the multiplier
        length = a.length() * num;
        //calls function MoveIt to:
        //recognize the direction which it will go in the D.L.L. &
        //returns the animals which it lands on
        //stored in b
        b = List.MoveIt(length);
        
        //size starts at 235 and
        //%11 is every size that is the multiple of 11 
        //and size = 1 is not included in this calculation
        //If/else used for shortening the output file
        if(size%11 == 0){
          outfile << "- " << b << endl;
          cout << " " << b << endl;
        }
        else{
          cout << " " << b << endl;
        }
        fin>>a;
        //decrementing the size so it reaches 1
        size--;
      }
    }
    
    //Print() is to outfile the final and only node left in the list
    //the finalist!
    List.Print(outfile);
}
