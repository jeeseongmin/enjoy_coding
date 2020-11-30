#include <stdio.h>
#include <stdlib.h>

void check_max();
void reset();
void check(int node);

int marine;
int min_rel;
int total_rel;
int max_rel = 0;
int **arr_rel;
int *count_rel;
int *mark;
// int *wait_rel;
// int *result_rel;
int max = 0;

int main() {
  scanf("%d %d %d",&marine, &min_rel, &total_rel);
  getchar();
  // printf("result : %d %d %d\n", marine, min_rel, total_rel);
  arr_rel = malloc(sizeof(int *) * marine+1);
  count_rel = malloc(sizeof(int *) * marine+1);
  mark = malloc(sizeof(int *) * marine+1);
  // wait_rel = malloc(sizeof(int *) * marine+1);
  // result_rel = malloc(sizeof(int *) * marine+1);

  for(int i=0; i<marine+1; i++) {
    arr_rel[i] = malloc(sizeof(int) * marine+1);
    count_rel[i] = 0;
    mark[i] = 0;
    // wait_rel[i] = 0;
    // result_rel[i] = 0;
    for(int j=0; j<marine+1; j++) {
      arr_rel[i][j] = 0;
    }
  }

  int temp_x, temp_y;
  for(int i=0; i<total_rel; i++) {
    scanf("%d %d", &temp_x, &temp_y);
    getchar();
    // printf("%d %d\n", temp_x, temp_y);
    arr_rel[temp_x][temp_y] = 1;
    arr_rel[temp_y][temp_x] = 1;
    count_rel[temp_x]++;
    count_rel[temp_y]++;
  }
  for(int i=1; i<marine+1; i++) {
    check(i);
    reset();
  }
  // 인접 행렬 재정리 -> 최소 관계 수보다 작은 것 삭제.
  // for(int i=1; i<marine+1; i++) {
  //   if(count_rel[i]<min_rel) {
  //     count_rel[i]--;
  //     for(int j=1; j<marine+1; j++) {
  //       if(arr_rel[i][j] == 1) {
  //         count_rel[j]--;
  //         arr_rel[i][j] = 0;
  //         arr_rel[j][i] = 0;
  //       }
  //     }
  //   }
  //   // 아니어도 child들이 조건이 안될 수도 있기 때문에
  //   // else {
  //   //   if(check(i)==0) {
  //   //     i--;
  //   //   }
  //   // }
  //   // reset();
  // }

  int max_cnt = 0;
  for(int i=1;i<marine+1; i++) {
    // printf("count_rel[%d]: %d\n",i, count_rel[i]);
    if(count_rel[i] >= min_rel) {
      max_cnt++;
    }
  }

  // max 따지기.
  // for(int i=1; i<marine+1; i++) {
  //   if(count_rel[i] >= min_rel) {
  //     wait_rel[i] = 1;
  //     if(count_rel[i]>=min_rel) {
  //       for(int j=1; j<marine+1; j++) {
  //         if(arr_rel[i][j] == 1) {
  //           wait_rel[j] = 1;
  //         }
  //       }
  //     }
  //     check_max();
  //   }
  // }

  // adjacency Matrix Debug
  // for(int i =0; i<marine+1; i++) {
  //   for(int j=0; j<marine+1; j++) {
  //     printf("%d ",arr_rel[i][j]);
  //   }
  //   printf("\n");
  // }
  free(count_rel);
  for(int i =0; i<marine+1; i++) {
    free(arr_rel[i]);
  }
  free(arr_rel);
  printf("%d",max_cnt);
  return 0;
}




// 자, 여기서는 뭘 하냐하면 입력받은 노드를 바탕으로 연관된 모든 항목을 담습니다.

// void check_max() {
//   int temp_max = 0;
//   for(int i =0; i<marine+1; i++) {
//     temp_max+=wait_rel[i];
//   }
//   if(temp_max > max) max = temp_max;
//   for(int i =0; i<marine+1; i++) {
//     wait_rel[i]=0;
//   }
// }

// void around(int node) {
//   mark[node] = 1;
//
//   if(count_rel[i]<min_rel) {
//     for(int j=1; j<marine+1; j++) {
//       if(arr_rel[i][j] == 1) {
//         count_rel[i]--;
//         count_rel[j]--;
//         arr_rel[i][j] = 0;
//         arr_rel[j][i] = 0;
//       }
//     }
//   }
//   else {
//     for(int i=1; i<marine+1; i++) {
//       if(arr_rel[node][i] == 1 && mark[i] == 0) {
//
//         around(i);
//       }
//     }
//   }
// }


void check(int node) {
  mark[node]=1;
  // 현노드가 조건을 만족하는지 체크
  // 만족하지 않는다면 값을 내리고 관련 타 노드들을 0으로 변환.
  if(0<count_rel[node] && count_rel[node]<min_rel) {
    count_rel[node]--;
    for(int j=1; j<marine+1; j++) {
      if(arr_rel[node][j] == 1) {
        count_rel[j]--;
        arr_rel[node][j] = 0;
        arr_rel[j][node] = 0;
      }
    }
  }
  for(int i=1; i<marine+1; i++) {
    // child && 지나갔던 길인지 체크
    if(arr_rel[node][i] == 1 && mark[i] == 0) {
      // child면서 안지나갔던 길이면 체크!
      check(i);
    }
  }
}

void reset() {
  for(int i=1; i<marine+1; i++) {
    mark[i]=0;
  }
}
