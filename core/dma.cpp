#include<iostream>
using namespace std;
int main(){

      int row = 5;
      int col = 4;
      int **mat = new int*[row];
      for(int i=0 ; i < row ;i ++) {
            mat[i ] = new int[col];
      }
      int *data = new int[row *col];
      int **grid = new int*[row];
      for(int i=0 ; i < row ; i ++) {
            grid[i ] = data +i*col;
      }

      

      return 0 ;
}
