#include<stdio.h>

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
  double max_value = 10000000000;
  double min_value = 0;
  int buildings;
  int limit;
  // int *building_people;
  // double *building_point;
  scanf("%d %d",&buildings, &limit);
  int *p1;
  double *p2;
  int building_people[buildings];
  double building_point[buildings];

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
  double max_point = min_value;
  double min_point = max_value;
  for(int i=0; i<buildings; i++) {
    scanf("%d %lf",&building_people[i], &building_point[i]);
    // printf("%d %0.lf\n",building_people[i], building_point[i]);
    max_point = (max_point<building_point[i]) ? building_point[i] : max_point;
    min_point = (min_point>building_point[i]) ? building_point[i] : min_point;
    getchar();
  }

  // printf("max_point : %0.f, min_point : %0.f\n",max_point, min_point);
  // for(int i=0; i<buildings; i++) {
  //   printf("%0.f %d\n", building_point[i], building_people[i]);
  // }

  qsorting(building_point, building_people, 0, buildings-1);

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

  double dist_min;
  double dist_max;
  int count_people_min;
  int count_people_max;
  int max_people=0;
  for(int i=0; i<buildings-1; i++) {
    // count_people_min=building_people[i];
    count_people_max=building_people[i];
    // dist_min = (building_point[i]-limit*2 > 0) ? building_point[i]-limit*2 : min_point;
    dist_max = (building_point[i]+limit*2<max_value) ? building_point[i]+limit*2 : max_point;
    // 크다고 할 때
    for(int j=i+1; j<buildings; j++) {
      if(building_point[i] <= building_point[j] && building_point[j] <= dist_max) {
        count_people_max+=building_people[j];
      }
      else break;
    }
    if(max_people<count_people_max) max_people = count_people_max;
  }
  if(building_people[buildings-1]>max_people) max_people=building_people[buildings-1];

  printf("%d\n",max_people);
  // free(building_people);
  // free(building_point);
  return 0;
}
