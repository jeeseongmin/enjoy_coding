#include <stdio.h>

int max_weight;
int backs=0;
int carrier = 0;

void carry(int *weight, int *check, int index) {
  int max = 0;
  int inx = 0;
  int temp_max = 0;
  int temp_index = 0;
  max = weight[index];
  if(max > max_weight) return ;
  else check[index] = 1;
  // printf("index : %d, max : %d\n",index, max);

  for(int t=backs-1; t>=0; t--) {
    // printf("t: %d\n",t);
    if(index != t && check[t] == 0) {
      if(max+weight[t]>max_weight) {
        continue;
      }
      // 합이 같을 때, 캐리어 1개가 된다.
      else if(max+weight[t]== max_weight) {
        // printf("max+weight[%d] : %d+%d = %d\n",t, max,weight[t], max+weight[t]);
        check[t] = 1;
        carrier++;
        return ;
      }
      // 합이 적을 때, 그 중 최댓값이 캐리어가 된다.
      // 인덱스와 더한 값을 항상 저장하고, max값과 비교해서 max값 보다 크면 max값이 업데이트된다.
      else {
        max = max + weight[t];
        check[t]=1;
      }
    }

  }
  //
  if(max == max_weight) {
    // printf("weight[%d] : %d\n",index, weight[index]);
    // if(weight[index] <= max_weight) {
    //   check[index] = 1;
    //   carrier++;
    // }
    return ;
  }
  else {
    carrier++;
    // printf("weight[%d]+weight[%d] : %d+%d = %d\n",index, inx, weight[index],weight[inx], weight[index]+weight[inx]);
    // check[inx] = 1;
    // check[index] = 1;
    // carrier++;
  }
}

void QuickSort(int *weight, int *check, int left, int right) {
  int L = left, R = right;
  int temp;
  int pivot = weight[(left + right) / 2]; //피봇 위치(중앙)의 값을 받음.
  //아래의 while문을 통하여 pivot 기준으로 좌, 우 크고 작은 값 나열. = Partition
  while (L <= R) {
    while (weight[L] < pivot) //left부터 증가하며 pivot 이상의 값을 찾음.
      L++;
    while (weight[R] > pivot) //right부터 감소하며 pivot 이하 값을 찾음.
      R--;
    //L, R 모두 최대 pivot 위치까지 이동.
    if (L <= R) { //현재 L이 R이하면. (이유 : L>R 부분은 이미 정리가 된 상태임).
      if (L != R) { //같지 않은 경우만.
        temp = weight[L];
        weight[L] = weight[R];
        weight[R] = temp;
        temp = check[L];
        check[L] = check[R];
        check[R] = temp;
      } //L과 R이 같다면 교환(SWAP)은 필요 없고 한 칸씩 진행만 해주면 됨.
      L++; R--; //그리고 L,R 한 칸 더 진행.
    }
  }
  //조건 확인하여 재귀함수로.
  if (left < R)
    QuickSort(weight, check, left, R);
  if (L < right)
    QuickSort(weight, check, L, right);
}

int main() {
  scanf("%d",&max_weight);
  // printf("max_weight:%d\n",max_weight);
  getchar();
  int weight[100000];
  int check[100000];
  for(int i=0; i<100000; i++) {
    int temp;
    scanf("%d", &temp);
    if(getchar() == '\n') {
      weight[i] = temp;
      check[i] = 0;
      backs++;
      if(temp == max_weight) {
        // printf("weight[%d] : %d\n",i, weight[i]);
        carrier++;
        check[i] = 1;
      }
    }
    else break;
  }
  // printf("backs: %d\n",backs);
  // printf("max_weight:%d\n",max_weight);
  // printf("before\n");
  // for(int i=0; i<backs; i++) {
  //   printf("weight[%d] : %d\n",i, weight[i]);
  // }
  // for(int i=0; i<backs; i++) {
  //   printf("check[%d] : %d\n",i, check[i]);
  // }
  // printf("\n");

  QuickSort(weight,check,0,backs-1);
  // printf("\n");
  // printf("after\n");
  // for(int i=0; i<backs; i++) {
  //   printf("weight[%d] : %d\n",i, weight[i]);
  // }
  //
  // for(int i=0; i<backs; i++) {
  //   printf("check[%d] : %d\n",i, check[i]);
  // }

  // int end = backs - carrier;

  for(int i=backs-1; i>=0; i--) {
    if(check[i] == 0) {
      // printf("i: %d\n",i);
      carry(weight,check, i);
    }
  }

  printf("%d",carrier);
}
