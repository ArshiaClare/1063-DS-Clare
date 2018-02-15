#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int  i,j, k=1;
int Nums[15][15];

  for(i=0;i<15;i++){
   for(j=0;j<15;j++){
      Nums[i][j]=k;
      k++;
      cout<< setw(5) << k;
   }
   cout<< endl;
  }
  for (int row = 0; row< 15; row++){
   for(int col = 0; col < 15; col++){
    cout<< setw(5) << Nums[col][row];
   }
   cout << endl;
  }
}
