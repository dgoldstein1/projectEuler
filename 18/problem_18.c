#include <stdio.h>

int main() {

  int grid[15][15] = {
    {75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {53, 22, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {17, 47, 82, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {18, 35, 87, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {20,  4, 82, 47, 65, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {19,  1, 23, 75,  3, 34, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {88,  2, 77, 73,  7, 63, 67, -1, -1, -1, -1, -1, -1, -1, -1},
    {99, 65,  4, 28,  6, 16, 70, 92, -1, -1, -1, -1, -1, -1, -1},
    {41, 41, 26, 56, 83, 40, 80, 70, 33, -1, -1, -1, -1, -1, -1},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29, -1, -1, -1, -1, -1},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, -1, -1, -1, -1},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, -1, -1, -1},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, -1, -1},
    {63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, -1},
    { 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}
  };

  int nRows = 15;
  int nCols = 15;

  // start from botton rows rewriting graph
  for (int row = nRows - 2 ; row >= 0; row --) {
    for (int col = 0 ; col  < nCols ; col ++) {
      
      if (grid[row][col] != -1 ) {
        int lowerNumbers[3] = {0,0,0};
        
        // not first in row
        if (col != 0) lowerNumbers[0] = grid[row + 1][col - 1];

        // add in lower numbers
        lowerNumbers[2] = grid[row + 1][col + 1];
        lowerNumbers[1] = grid[row + 1][col];

        // get largest from available
        int currMax = 0;
        for (int i = 0 ; i < 3 ; i ++) 
          if (lowerNumbers[i] > currMax) currMax = lowerNumbers[i];

        // curr index in grid as curr number + greatest lower number
        grid[row][col] += currMax;
      }
    }
  }
  printf("%i\n", grid[0][0]);

	return 0;
}






















