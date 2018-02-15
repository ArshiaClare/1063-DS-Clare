3)  int *A;
    A= new int[5];
    int height =6;
    int width =6;

  for(int i=0; i< 5; i++){
    A[i] = 5; //rand()%10;
    cout <<setw(3) << A[i]; 
  } 
4)  int **B;
    B = new int*[height];
    for(int i=0; i< width; i++){
    B[i] = new int[width];
    }
  
  for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
          B[i][j] = rand()%10;
            cout<< B[i][j];
        }
        cout<<endl;
  }  
 5) int *A;
int count = 0;
A= new int[5];
int height =6;
int width =6;

  for(int i=0; i< 5; i++){
    A[i] = rand()%10;
    cout << setw(3) << A[i]; 
    count += A[i];
  }
  cout << setw(3) << count;
}
#include <iostream>
#include <iomanip>

using namespace std;

struct Stats{
  int min;
  int max;
  double avg;
  Stats(){
    min = 0;
    max = 0;
    avg = 0.0;
  };
};

int main() {
//   int  i,j, k=1;
// int Nums[15][15];

//   for(i=0;i<15;i++){
//   for(j=0;j<15;j++){
//       Nums[i][j]=k;
//       k++;
//       cout<< setw(5) << k;
//   }
//   cout<< endl;
//   }
//   for (int row = 0; row< 15; row++){
//   for(int col = 0; col < 15; col++){
//     cout<< setw(5) << Nums[col][row];
//   }
//   cout << endl;
//   }


//allocating 1d array
// int *A;
// A= new int[5];
// int height =6;
// int width =6;

//   for(int i=0; i< 5; i++){
//     A[i] = 5; //rand()%10;
//     cout <<setw(3) << A[i]; 
//   }
  
//   //allocating 2d array
//   int **B;
//   B = new int*[height];
//   for(int i=0; i< width; i++){
//     B[i] = new int[width];
//   }
  
//   for(int i=0;i<height;i++){
//         for(int j=0;j<width;j++){
//           B[i][j] = rand()%10;
//             cout<< B[i][j];
//         }
//         cout<<endl;
//   } 

//#5
// int *A;
// int count = 0;
// A= new int[5];
// int height =6;
// int width =6;

//   for(int i=0; i< 5; i++){
//     A[i] = rand()%10;
//     cout << setw(3) << A[i]; 
//     count += A[i];
//   }
//   cout << setw(3) << count;
// }
//#6
// int **B;
// small = 11;
//   B = new int*[height];
//   for(int i=0; i< width; i++){
//     B[i] = new int[width];
//   }
  
//   for(int i=0;i<height;i++){
//         for(int j=0;j<width;j++){
//           B[i][j] = rand()%10;
//           if(small > B[i][j])
//           {
//             small = B[i][j];
//           }
//         cout<< B[i][j];
//         }
//         cout<<endl;
//   } 
// }

}
