#include <stdio.h>

int afuel;
int bfuel;
int tfuel;
int city;
int rel;

int amax=0;
int bmax=0;
int tmax=0;

struct Max {
  int alpha;
  int beta;
  int total;
};

int search(int *left, int *right, int *alpha, int index, struct Max m1, int before) {
  if(index == city) {
    m1.alpha=0;
    m1.beta=0;
    m1.total=0;
  }
  // printf("index : %d\n",index);
  if(left[index] != before) {

  }
  if(right[index] != before) {

  }
  if(alpha[left[index]] == 0) {
    if(left[index] != 1 && left[index] != city)
      alpha[left[index]] = 1;
    search(left, right, alpha, left[index], m1);
  }

  if(alpha[right[index]] == 0) {
    if(right[index] != 1 && right[index] != city)
      alpha[right[index]] = 1;
    search(left,right,alpha, right[index], m1);
  }



}

int main() {
  int afuel;
  int bfuel;
  int tfuel;
  int city;
  int rel;
  struct Max m1;
  m1.alpha=0;
  m1.beta=0;
  m1.total=0;
  scanf("%d %d %d %d %d",&afuel, &bfuel, &tfuel, &city, &rel);
  printf("afuel : %d, bfuel:%d, tfuel:%d, city:%d, rel:%d\n",afuel,bfuel,tfuel,city,rel);
  getchar();
  int left[city+1];
  int right[city+1];
  // int alpha[city+1];
  // int beta[city+1];
  int check[city+1];
  for(int i=0; i<=city; i++) {
      left[i] = 0;
      right[i] = 0;
      check[i] = 0;
      // alpha[i] = 0;
      // beta[i] = 0;
  }
  for(int i=0; i<rel; i++) {
    int tempi;
    int tempj;
    scanf("%d %d", &tempi, &tempj);
    left[tempi] = tempj;
    right[tempj] = tempi;
    getchar();
  }
  int final;
  final = search(left, right, check, 8, m1, 0);

  printf("%d\n",final);
}
