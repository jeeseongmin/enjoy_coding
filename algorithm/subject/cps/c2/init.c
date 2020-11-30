#include <stdio.h>

int main() {
  int arr[4][4] = {
    {1, 6, 10, 3},
    {5, 5, 6, 1},
    {5, 7, 2, 3},
    {11,5, 7, 4}
  };
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }

}
