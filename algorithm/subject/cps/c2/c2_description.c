#include <stdio.h>

int size;
int max_num = 0;
int min_i;
int min_j;
int dp(int (*model)[size], int (*memory)[size], int i, int j);

int left(int (*model)[size], int (*memory)[size], int i, int j) {
  memory[i][j-1] = dp(model,memory,i,j-1);
  return memory[i][j-1] + model[i][j-1] - model[i][j];
}
int right(int (*model)[size], int (*memory)[size], int i, int j) {
  memory[i][j+1] = dp(model, memory,i,j+1);
  return memory[i][j+1] + model[i][j+1] - model[i][j];
}
int top(int (*model)[size], int (*memory)[size], int i, int j) {
  memory[i-1][j] = dp(model, memory,i-1,j);
  return memory[i-1][j] + model[i-1][j] - model[i][j];
}
int bottom(int(* model)[size], int(* memory)[size], int i, int j) {
  memory[i+1][j] = dp(model, memory, i+1, j);
  return memory[i+1][j] + model[i+1][j] - model[i][j];
}

int dp(int(* model)[size], int(* memory)[size], int i, int j) {
  // printf("dp : %d %d\n",i, j);
  int max=0;
  if(memory[i][j] != 0) return memory[i][j];
  else {
    if(i == 0) {
      // 왼쪽 대각 모서리
      if(j==0) {
        if(model[i][j] < model[i+1][j]) {
          max = (max < bottom(model, memory, i, j)) ? bottom(model,memory,i,j) : max;
        }
        if(model[i][j] < model[i][j+1]) {
          max = (max < right(model, memory, i, j)) ? right(model,memory,i,j) : max;
        }
      }
      // 오른쪽 대각 모서리
      else if(j==size-1) {
        if(model[i][j] < model[i+1][j]) {
          max = (max < bottom(model, memory, i, j)) ? bottom(model,memory,i,j) : max;
        }
        if(model[i][j] < model[i][j-1]) {
          max = (max < left(model, memory, i, j)) ? left(model,memory,i,j) : max;
        }
      }
      // 그냥 맨 위 열
      else {
        if(model[i][j] < model[i][j-1]) {
          max = (max < left(model, memory, i, j)) ? left(model,memory,i,j) : max;
        }
        if(model[i][j] < model[i+1][j]) {
          max = (max < bottom(model, memory, i, j)) ? bottom(model,memory,i,j) : max;
        }
        if(model[i][j] < model[i][j+1]) {
          max = (max < right(model, memory, i, j)) ? right(model,memory,i,j) : max;
        }
      }
     }
    else if(i == size-1) {
      // 왼쪽 아래 대각 모서리
      if(i==0) {
        if(model[i][j] < model[i-1][j]) {
          max = (max < top(model, memory, i, j)) ? top(model,memory,i,j) : max;
        }
        if(model[i][j] < model[i][j+1]) {
          max = (max < right(model, memory, i, j)) ? right(model,memory,i,j) : max;
        }
      }
      // 오른쪽 아래 대각 모서리
      else if(i==size-1) {
        if(model[i][j] < model[i][j-1]) {
          max = (max < left(model, memory, i, j)) ? left(model,memory,i,j) : max;
        }
        if(model[i][j] < model[i-1][j]) {
          max = (max < top(model, memory, i, j)) ? top(model,memory,i,j) : max;
        }
      }
      // 그냥 맨 아랫 열
      else {
        if(model[i][j] < model[i][j-1]) {
          max = (max < left(model, memory, i, j)) ? left(model,memory,i,j) : max;
        }
        if(model[i][j] < model[i-1][j]) {
          max = (max < top(model, memory, i, j)) ? top(model,memory,i,j) : max;
        }
        if(model[i][j] < model[i+1][j]) {
          max = (max < bottom(model, memory, i, j)) ? bottom(model,memory,i,j) : max;
        }
        if(model[i][j] < model[i][j+1]) {
          max = (max < right(model, memory, i, j)) ? right(model,memory,i,j) : max;
        }
      }
    }
    // 맨 왼쪽 열
    else if(j == 0) {
      if(model[i][j] < model[i-1][j]) {
        max = (max < top(model, memory, i, j)) ? top(model,memory,i,j) : max;
      }
      if(model[i][j] < model[i+1][j]) {
        max = (max < bottom(model, memory, i, j)) ? bottom(model,memory,i,j) : max;
      }
      if(model[i][j] < model[i][j+1]) {
        max = (max < right(model, memory, i, j)) ? right(model,memory,i,j) : max;
      }
    }
    // 맨 오른쪽 열
    else if(j == size-1) {
      if(model[i][j] < model[i][j-1]) {
        max = (max < left(model, memory, i, j)) ? left(model,memory,i,j) : max;
      }
      if(model[i][j] < model[i-1][j]) {
        max = (max < top(model, memory, i, j)) ? top(model,memory,i,j) : max;
      }
      if(model[i][j] < model[i+1][j]) {
        max = (max < bottom(model, memory, i, j)) ? bottom(model,memory,i,j) : max;
      }
    }
    // 그냥 가운데쯤.
    else {
      if(model[i][j] < model[i][j-1]) {
        max = (max < left(model, memory, i, j)) ? left(model,memory,i,j) : max;
      }
      if(model[i][j] < model[i-1][j]) {
        max = (max < top(model, memory, i, j)) ? top(model,memory,i,j) : max;
      }
      if(model[i][j] < model[i+1][j]) {
        max = (max < bottom(model, memory, i, j)) ? bottom(model,memory,i,j) : max;
      }
      if(model[i][j] < model[i][j+1]) {
        max = (max < right(model, memory, i, j)) ? right(model,memory,i,j) : max;
      }
    }
  }
  return max;
}

int main() {
  scanf("%d",&size);
  getchar();
  // printf("size: %d\n",size);
  int model[size][size];
  int memory[size][size];

  for(int i=0; i<size; i++) {
    for(int j=0; j<size; j++) {
      scanf("%d ",&model[i][j]);
      memory[i][j] = 0;
    }
  }

  int max = 0;
  for(int i=0; i<size; i++) {
    for(int j=0; j<size; j++) {
      if(memory[i][j] == 0) {
        memory[i][j] = dp(model, memory, i, j) ;
        if(memory[i][j]>max) max = memory[i][j];
      }
    }
    printf("\n");
  }
  printf("%d\n",max);


  // printf("memory\n");
  // for(int i=0; i<size; i++) {
  //   for(int j=0; j<size; j++) {
  //     printf("%d ",memory[i][j]);
  //   }
  //   printf("\n");
  // }

}
