#include <stdio.h>

int max_weight;
int backs=0;
int carrier = 0;

void carry(int *weight, int *check, int index) {
  int max = 0;
  int inx = 0;
  int temp_max = 0;
  int temp_index = 0;

  for(int t=0; t<backs; t++) {
    if(index != t && check[t] == 0) {
      if(weight[index]+weight[t]>max_weight) {
        continue;
      }
      else if(weight[index]+weight[t]== max_weight) {
        check[t] = 1;
        check[index] = 1;
        carrier++;
        return ;
      }
      else {
        temp_index = t;
        temp_max = weight[index] + weight[t];
        if(temp_max>max) {
          max = temp_max;
          inx = temp_index;
        }
      }
    }
  }
  //
  if(max == 0) {
    if(weight[index] <= max_weight) {
      check[index] = 1;
      carrier++;
    }
  }
  else {
    check[inx] = 1;
    check[index] = 1;
    carrier++;
  }
}

int main(void) {
  scanf("%d",&max_weight);
  int weight[100000];
  int check[100000];
  for(int i=0; i<100000; i++) {
    int temp;
    scanf("%d", &temp);
    if(getchar() == '\n') {
      if(temp != 0) {
        weight[i] = temp;
        check[i] = 0;
        backs++;
        if(temp == max_weight) {
          carrier++;
          check[i] = 1;
        }
      }
    }
    else break;
  }
  for(int i=0; i<backs; i++) {
    if(check[i] == 0) {
      carry(weight,check, i);
    }
  }
  printf("%d",carrier);
  return 0;
}
