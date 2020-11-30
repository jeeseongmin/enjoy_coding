#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int pole[], int here, int size) {
    int left = here * 2 + 1;
    int right = here * 2 + 2;
    int max=here;
    if (left < size&&pole[left]>pole[max])
        max = left;
    if (right < size&&pole[right]>pole[max])
        max = right;

    if (max != here) {
        swap(&pole[here], &pole[max]);
        heapify(pole, max, size);
    }
}
void buildHeap(int pole[], int size) {
    int i;
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(pole, i, size);
        // for (j = 0; j < size; j++)
        //     printf("%d ", pole[j]);
        // printf("\n\n");
    }
}
void heapSort(int pole[],int size) {
    int treeSize;
    buildHeap(pole, size);
    for (treeSize = size - 1; treeSize >= 0; treeSize--) {
        swap(&pole[0], &pole[treeSize]);
        heapify(pole, 0,treeSize);
    }
}

int main() {
  int poles = 0;
  int amp = 0;
  scanf("%d %d",&poles, &amp);
  // printf("poles : %d, amp : %d\n",poles, amp);
  int pole[poles];
  for(int i =0; i<poles; i++) {
    scanf("%d\n",&pole[i]);
  }
  heapSort(pole,poles);
  // for(int i =0; i<poles; i++) {
  //   printf("%d\n",pole[i]);
  // }

  // for(int i=0; i<poles; i++) {
  //   printf("%d\n",pole[i]);
  // }
  int left = pole[0];
  int right= pole[poles-1]-pole[0];
  // printf("%d %d\n",left, right);
  int min = 0;
  int mid;
  // amp와 일치가 되면 그때 dist 끝.
  // 근데 이제 최소값을 생각해야 하기 때문에.
  // 만약 temp_amp가 amp보다 크거나 같다면, 최소 거리의 범위를 늘려야 함.
  // 만약 temp_amp가 amp보다 작다면, 최소 거리의 범위를 줄여야 함.
  while(left<=right) {
    mid = (left+right) / 2;
    // printf("[%d ~ %d] : average = %d\n", left, right, mid);
    int temp_amp = 0;
    int _current=pole[0];
    int _next;
    temp_amp++;
    for(int i=1; i<poles; i++) {
      _next = pole[i];
      // printf("%d ~ %d\n",_next, _current);
      if(_next - _current >= mid) {
        // printf("+ %d\n",_next);
        temp_amp++;
        _current = _next;
      }
    }
    // printf("temp_amp : %d\n",temp_amp);
    // 설치한 증폭기 수가 목표 중폭기 수보다 크거나 같을 때.
    if(temp_amp >= amp) {
      left = mid+1;
      min = mid;
    }
    // 설치한 증폭기 수가 목표 중폭기 수보다 작을 때.
    else {
      right = mid-1;
    }
  }
  printf("%d\n",min);
  return 0;
}
