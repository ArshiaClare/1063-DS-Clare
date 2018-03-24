```
//Arshia Clare
//March 26, 2018
//Homework

#include <iostream>
#include <string>

using namespace std;

string toLower(string w){
  for(int i=0;i<w.length();i++){
    
    if((int)w[i]>=65 && (int)w[i]<=90){
      w[i] = w[i]+32;
    }
  }
  return w;
}

string toUpper(string w){
  for(int i=0;i<w.length();i++){
    
    if((int)w[i]>= 97 && (int)w[i]<=122){
      w[i] = w[i]-32;
    }
  }
  return w;
}

int main() {
  string x = "ANTELOPE";
  cout << x << endl;
  cout << toLower(x) << endl;
  cout << toUpper(x) << endl;
}
```
