#include <iostream>
#include <vector>
#include <map>
using namespace std;

int cnt, width, height, temp;
int flag = 0;
vector<pair<int, int>> size;
vector<int> test_vec;
vector <vector <int>> puzzle[5];

int empty[4][4] = {0,};

void _init() {
  for(int i =0; i<0; i++) {
    for(int j =0; j<0; j++) {
      empty[i][j] = 0;
    }
  }
}

void _init_arr(int turn, int x, int y, int height, int width, int prac[4][4]) {
  int _h = 0;
  int _w = 0;
  for(int i =x; i<x+height; i++) {
    for(int j=y; j<y+width; j++) {
      if(prac[i][j] == turn+1) {
        prac[i][j] = 0;
        _w++;
      }
    }
    _w=0;
    _h++;
  }
}

int test(int turn, int x, int y, int height, int width, int prac[4][4]) {
  int _h = 0;
  int _w = 0;
  for(int i =x; i<x+height; i++) {
    for(int j=y; j<y+width; j++) {
      if(prac[i][j] * puzzle[turn][_h][_w] == 0) {
        prac[i][j] += puzzle[turn][_h][_w];
        _w++;
      }
      else {
        _init_arr(turn, i, j, height, width, prac);
        return -1;
      }
    }
    _w=0;
    _h++;
  }

  int cnt = 0;
  for(int i =0; i<4; i++) {
    for(int j=0; j<4; j++) {
      if(prac[i][j] != 0) cnt++;
      // printf("%d ",prac[i][j]);
    }
    // printf("\n");
  }
  // printf("\n");
  if(cnt == 16) {
    for(int i =0; i<4; i++) {
      for(int j=0; j<4; j++) {
        // if(prac[i][j] != 0) cnt++;
        printf("%d ",prac[i][j]);
      }
      if(i !=3) printf("\n");
    }
    exit(0);
  }
  else return 1;
}

void combi(int turn, int prac[4][4]) {
  int check = 0;
  int _height = size[turn].first;
  int _width = size[turn].second;
  for(int i =0; i<4; i++) {
    for(int j=0; j<4; j++) {
      if(i+_height<=4 && j+_width <=4) {
        check = test(turn, i, j, _height, _width, prac);
        if(check == -1) {
          _init_arr(turn, i, j, _height, _width, prac);
          check = 0;
        }
        else if(check == 1) {
          combi(turn+1, prac);
          if(flag == -1) {
            _init_arr(turn, i, j, _height, _width, prac);
            flag = 0;
            check = 0;
          }
        }
      }
    }
  }
  if(check == 0) {
    flag = -1;
  }
}

int main() {
  scanf("%d", &cnt);
  int prac[4][4]={0,};
  for(int x=0; x<cnt; x++) {
    scanf("%d %d",&height, &width);
    size.push_back(make_pair(height,width));
    for(int i=0; i<height; i++) {
      for(int j=0; j<width; j++) {
        cin >> temp;
        if(temp == 1) temp = x+1;
        test_vec.push_back(temp);
      }
      puzzle[x].push_back(test_vec);
      test_vec.clear();
    }
  }

  combi(0, prac);
  printf("No solution possible");
  return 0;

}
