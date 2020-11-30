// 이 방식이 그래도 dp 같이 풀려고 했던 방식.
#include<stdio.h>

double max_value = 10000000000;
double min_value = 0;
int buildings;
int limit;
double max_point;
double min_point;
double dist_min;
double dist_max;
int count_people_max;
int max_people=0;

void dq(double *building_point, int *building_people, int *mark, int left, int right) {
  int mid = left + (right-left)/2;
  if(right-left == 1) {
    if(mark[left]==1) {
      // mark
      if(building_people[left]>max_people) max_people=building_people[left];
      if(right==buildings-1) {
        if(building_people[buildings-1]>max_people) max_people=building_people[buildings-1];
      }
      return ;
    }
    else {
      // count_people_min=building_people[i];
      count_people_max=building_people[left];
      // dist_min = (building_point[i]-limit*2 > 0) ? building_point[i]-limit*2 : min_point;
      dist_max = (building_point[left]+limit*2<max_value) ? building_point[left]+limit*2 : max_point;
      // printf("i:%d, dist_max:%0.lf\n",i, dist_max);
      // 크다고 할 때
      for(int j=left; j<buildings; j++) {
        if(left==j) continue;
        if(building_point[left] <= building_point[j] && building_point[j] <= dist_max) {
          count_people_max+=building_people[j];
        }
        else break;
      }
      // 오른쪽 끝에 도달한 경우.
      if(right==buildings-1) {
        if(building_point[left] <= building_point[right] && building_point[right] <= dist_max) {
          count_people_max+=building_people[right];
        }
        else {
          if(building_people[buildings-1]>max_people) max_people=building_people[buildings-1];
        }
      }
      // 비교군이니까 필요함.
      if(max_people<count_people_max) max_people = count_people_max;
      return ;
    }

  }
  else {
    dq(building_point, building_people, mark, left, mid);
    dq(building_point, building_people, mark, mid, right);
  }
}


void qsorting(double *building_point, int *building_people, int left, int right) {
  if(left >= right) {
    return;
  }
  int key = left;
  int i=left+1;
  int j=right;
  int temp;

  while(i<=j) {
    while(i <= right && building_point[i] <= building_point[key]) {
      i++;
    }
    while(j > left && building_point[j] >= building_point[key]) {
      j--;
    }
    if(i > j) {
      temp = building_point[j];
      building_point[j] = building_point[key];
      building_point[key] = temp;
      temp = building_people[j];
      building_people[j] = building_people[key];
      building_people[key] = temp;
    } else {
      temp = building_point[i];
      building_point[i] = building_point[j];
      building_point[j] = temp;
      temp = building_people[i];
      building_people[i] = building_people[j];
      building_people[j] = temp;
    }
  }
  qsorting(building_point, building_people, left, j - 1);
  qsorting(building_point, building_people, j + 1, right);
}

int main() {
  scanf("%d %d",&buildings, &limit);
  int building_people[buildings];
  double building_point[buildings];
  int between[buildings];
  int mark[buildings];
  // int max[buildings];
  // printf("result : %d %d\n",buildings, limit);
  getchar();

  // printf("max_value: %0.f\n",max_value);
  // building_people=malloc(sizeof(int) * buildings);
  // building_point=malloc(sizeof(double) * buildings);
  // printf("buildings : %d\n",buildings);
  // for(int i=0; i<buildings; i++) {
  //   building_people[i] = 0;
  //   building_point[i] = 0;
  // }

  // 값 입력 구간
  //[0]에 있는 것이 building의 point, [1]에 있는 것이 people
  max_point = min_value;
  min_point = max_value;
  for(int i=0; i<buildings; i++) {
    scanf("%d %lf",&building_people[i], &building_point[i]);
    // printf("%d %0.lf\n",building_people[i], building_point[i]);
    max_point = (max_point<building_point[i]) ? building_point[i] : max_point;
    min_point = (min_point>building_point[i]) ? building_point[i] : min_point;
    getchar();
  }
  qsorting(building_point, building_people, 0, buildings-1);
  for(int i=0; i<buildings; i++) {
    mark[i] = 0;
  }
  for(int i=buildings-1; i>0; i--) {
    between[i] = building_point[i]-building_point[i-1];
    if(between[i]>2*limit) mark[i-1] = 1;
  }
  between[0] = 0;
  // for(int i=0; i<buildings; i++) {
  //   printf("mark[%d]: %d\n",i, mark[i]);
  // }
  //
  // for(int i=0; i<buildings; i++) {
  //   printf("between[%d]:%d\n",i,between[i]);
  // }
  //
  // for(int i=0; i<buildings; i++) {
  //   if(mark[i] == 0) {
  //
  //   }
  // }



  // 지울까말까
  // int max_temp = 0;
  // int start = 1;
  // for(int i=1; i<buildings; i++) {
  //   max_temp = 0;
  //   start = i;
  //   if(between[i] > limit*2) {
  //     max_update(between, building_point, building_people, i-1, i-1);
  //     max_update(between, building_point, building_people, i, i);
  //   }
  //   else {
  //     while(max_temp+between[start] <= limit*2) {
  //       start++;
  //       if(start==end) {
  //         max_update()
  //       }
  //     }
  //   }
  // }

  // printf("max_point : %0.f, min_point : %0.f\n",max_point, min_point);
  // for(int i=0; i<buildings; i++) {
  //   printf("%0.f %d\n", building_point[i], building_people[i]);
  // }
  // qsorting(building_point, building_people, 0, buildings-1);
   // sorting을 다시 넣었음.
  // int temp_people;
  // double temp_point;
  // int min_index;
  // for(int i=0; i<buildings-1; i++) {
  //   min_index = i;
  //   for(int j=i+1; j<buildings; j++) {
  //     if(building_point[min_index] >= building_point[j]) {
  //       min_index = j;
  //     }
  //   }
  //   if(min_index != i) {
  //     temp_point = building_point[min_index];
  //     temp_people = building_people[min_index];
  //     building_point[min_index] = building_point[i];
  //     building_people[min_index] = building_people[i];
  //     building_point[i] = temp_point;
  //     building_people[i] = temp_people;
  //   }
  // }
  // printf("after : \n");
  // for(int i=0; i<buildings; i++) {
  //   printf("%0.f %d\n", building_point[i], building_people[i]);
  // }
  dq(building_point, building_people, mark, 0, buildings-1);
  // for(int i=0; i<buildings; i++) {
  //   // count_people_min=building_people[i];
  //   count_people_max=building_people[i];
  //   // dist_min = (building_point[i]-limit*2 > 0) ? building_point[i]-limit*2 : min_point;
  //   dist_max = (building_point[i]+limit*2<max_value) ? building_point[i]+limit*2 : max_point;
  //   // printf("i:%d, dist_max:%0.lf\n",i, dist_max);
  //   // 크다고 할 때
  //   for(int j=0; j<buildings; j++) {
  //     if(i==j) continue;
  //     if(building_point[i] <= building_point[j] && building_point[j] <= dist_max) {
  //       count_people_max+=building_people[j];
  //     }
  //   }
  //   if(max_people<count_people_max) max_people = count_people_max;
  //   if(dist_max == max_point) break;
  // }
  // if(building_people[buildings-1]>max_people) max_people=building_people[buildings-1];

  printf("%d\n",max_people);
  return 0;
}
