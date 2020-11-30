#include <stdio.h>
#include <stdlib.h>
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
      // 합이 같을 때, 캐리어 1개가 된다.
      else if(weight[index]+weight[t]== max_weight) {
        // printf("weight[%d]+weight[%d] : %d+%d = %d\n",index, t, weight[index],weight[t], weight[index]+weight[t]);
        check[t] = 1;
        check[index] = 1;
        carrier++;
        return ;
      }
      // 합이 적을 때, 그 중 최댓값이 캐리어가 된다.
      // 인덱스와 더한 값을 항상 저장하고, max값과 비교해서 max값 보다 크면 max값이 업데이트된다.
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
    // printf("weight[%d] : %d\n",index, weight[index]);
    if(weight[index] <= max_weight) {
      check[index] = 1;
      carrier++;
    }
  }
  else {
    // printf("weight[%d]+weight[%d] : %d+%d = %d\n",index, inx, weight[index],weight[inx], weight[index]+weight[inx]);
    check[inx] = 1;
    check[index] = 1;
    carrier++;
  }
}

int main() {
  char buf[4096];
  int line = 0;
  int weight[100000];
  int check[100000];
  int first = 0;
  FILE *fp = fopen("input.txt", "r");

  if(fp == NULL) {
    exit(0);
  }
  while(!feof(fp)) {
    int temp;
    fscanf(fp, "%d\n", &temp);
    line++;
    // fgets(buf,sizeof(buf),fp);
    if(first == 0) {
      max_weight = temp;
      first++;
    }
    else {
      weight[backs] = temp;
      if(temp == max_weight) {
        carrier++;
        check[backs] = 1;
      }
      else check[backs] = 0;
      backs++;
    }
    // printf(buf);
  }
  fclose(fp);
  printf("backs : %d\n",backs);
  printf("max_weight: %d\n",max_weight);
  printf("carrier: %d\n",carrier);

  printf("before\n");
  for(int i=0; i<backs; i++) {
    printf("weight[%d] : %d\n",i, weight[i]);
  }
  for(int i=0; i<backs; i++) {
    printf("check[%d] : %d\n",i, check[i]);
  }
  printf("backs : %d\n",backs);
  for(int i=0; i<backs; i++) {
    if(check[i] == 0) {
      carry(weight,check, i);
    }
  }
  printf("after\n");
  for(int i=0; i<backs; i++) {
    printf("weight[%d] : %d\n",i, weight[i]);
  }
  for(int i=0; i<backs; i++) {
    printf("check[%d] : %d\n",i, check[i]);
  }

  printf("%d\n",carrier);

  return 0;
}
