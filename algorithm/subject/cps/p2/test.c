#include<stdio.h>
#include<stdlib.h>

int main() {
  float max_value = 10000000000;
  float min_value = 0;
  int buildings;
  float limit;
  float **building_info;
  scanf("%d %f",&buildings, &limit);
  // printf("result : %d %0.f\n",buildings, limit);
  getchar();

  building_info=malloc(sizeof(float *) * buildings);
  // printf("buildings : %d\n",buildings);
  for(int i=0; i<buildings; i++) {
    building_info[i] = malloc(sizeof(float *) * 2);
    for(int j=0; j<2; j++) {
      building_info[i][j] = 0;
    }
  }
  // 값 입력 구간
  //[0]에 있는 것이 building의 point, [1]에 있는 것이 people
  float max_point = min_value;
  float min_point = max_value;
  for(int i=0; i<buildings; i++) {
    scanf("%f %f",&building_info[i][1], &building_info[i][0]);
    max_point = (max_point<building_info[i][0]) ? building_info[i][0] : max_point;
    min_point = (min_point>building_info[i][0]) ? building_info[i][0] : min_point;
    getchar();
  }
  // printf("max: %0.f, min: %0.f\n",max_point, min_point);

  // 디버그
  // for(int i=0; i<buildings; i++) {
  //   for(int j=0; j<2; j++) {
  //     printf("%0.f ",building_info[i][j]);
  //   }
  //   printf("\n");
  // }

  // selection sorting
  float temp_people;
  float temp_point;
  int min_index;
  for(int i=0; i<buildings-1; i++) {
    min_index = i;
    for(int j=i+1; j<buildings; j++) {
      if(building_info[min_index][0] >= building_info[j][0]) {
        min_index = j;
      }
    }
    if(min_index != i) {
      temp_point = building_info[min_index][0];
      temp_people = building_info[min_index][1];
      building_info[min_index][0] = building_info[i][0];
      building_info[min_index][1] = building_info[i][1];
      building_info[i][0] = temp_point;
      building_info[i][1] = temp_people;
    }
  }

  // printf("after: \n");
  // for(int i=0; i<buildings; i++) {
  //   for(int j=0; j<2; j++) {
  //     printf("%0.f ",building_info[i][j]);
  //   }
  //   printf("\n");
  // }

  float dist_min;
  float dist_max;
  int count_people;
  int max_people=0;

  for(int i=0; i<buildings-1; i++) {
    count_people=building_info[i][1];
    for(int j=i+1; j<buildings; j++) {
      if(building_info[j][0]-building_info[i][0] <= limit *2) {
        count_people+=building_info[j][1];
      }
      else break;
    }
    if(max_people<count_people) max_people = count_people;
  }
  if(building_info[buildings-1][1]>max_people) max_people=building_info[buildings-1][1];
  // for(float i=0; i<buildings; i++) {
  //   count_people=0;
  //   dist_min = (i - limit < min_value) ? min_value : i - limit;
  //   dist_max = (i + limit > max_value) ? max_value : i + limit;
  //   for(int j=0; j<buildings; j++) {
  //     if(dist_min<=building_info[j][0]) {
  //       if(building_info[j][0] <= dist_max) {
  //         count_people+=building_info[j][1];
  //       }
  //     }
  //   }
  //   if(max_people<count_people) max_people = count_people;
  // }
  printf("%d",max_people);

  for(int i=0; i<buildings; i++) {
    free(building_info[i]);
  }
  free(building_info);
}
