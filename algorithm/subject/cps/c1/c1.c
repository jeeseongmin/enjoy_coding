#include <stdio.h>
#include <stdlib.h>

int marine;
int min_rel;
int total_rel;
int **adj_matrix;
int *count_friends;

int main() {
  scanf("%d %d %d",&marine, &min_rel, &total_rel);
  getchar();

  adj_matrix = malloc(sizeof(int *) * marine+1);
  count_friends = malloc(sizeof(int *) * marine+1);

  for(int i=0; i<marine+1; i++) {
    adj_matrix[i] = malloc(sizeof(int) * marine+1);
    count_friends[i] = 0;
    for(int j=0; j<marine+1; j++) {
      adj_matrix[i][j] = 0;
    }
  }

  int temp_x, temp_y;
  for(int i=0; i<total_rel; i++) {
    scanf("%d %d", &temp_x, &temp_y);
    getchar();
    adj_matrix[temp_x][temp_y] = 1;
    adj_matrix[temp_y][temp_x] = 1;
    count_friends[temp_x]++;
    count_friends[temp_y]++;
  }

  int restart=0;
  for(int i=1; i<marine+1; i++) {
    if(restart==1) {
      i=1;
      restart=0;
    }
    if(0<count_friends[i] && count_friends[i] < min_rel) {
      for(int j=1; j<marine+1; j++) {
        if(adj_matrix[i][j]==1) {
          restart=1;
          count_friends[i]--;
          count_friends[j]--;
          adj_matrix[i][j]=0;
          adj_matrix[j][i]=0;
        }
      }
    }
  }

  int max_cnt = 0;
  for(int i=1;i<marine+1; i++) {
    if(count_friends[i] >= min_rel) {
      max_cnt++;
    }
  }

  free(count_friends);
  for(int i =0; i<marine+1; i++) {
    free(adj_matrix[i]);
  }
  free(adj_matrix);
  printf("%d",max_cnt);
  return 0;
}
