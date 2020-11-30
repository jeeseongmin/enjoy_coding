#include <iostream>
#include <vector>
#include <map>
using namespace std;

int cnt, width, height, temp;
multimap<int, int, greater<int>> sort_size; // key:h+w, value:index
vector<pair<int, int>> size;  // h,w를 저장하는 pair vector
vector<int> test_vec; // 배열별 높이 길이, 배열별 너비 길이
vector <vector <int>> puzzle[5]; // cnt개의 2차원 배열
int real[4][4]={0,};
int mark[4] = {0,};
int empty[4][4] = {0,};

// 초기화하는 함수
void _init() {
  for(int i =0; i<0; i++) {
    for(int j =0; j<0; j++) {
      empty[i][j] = 0;
    }
  }
}

// 해당 퍼즐을 원하는 위치에 넣어보는 함수
int test(int turn, int x, int y, int height, int width, int prac[4][4]) {
  printf(" test_turn : %d\n",turn);
  int _h = 0;
  int _w = 0;
  // 넣는 방법.
  for(int i =x; i<x+height; i++) {
    for(int j=y; j<y+width; j++) {
      if(prac[i][j] * puzzle[turn][_h][_w] == 0) {
        printf("i:%d, j:%d\n",i,j);
        prac[i][j] += puzzle[turn][_h][_w];
        _w++;
      }
      else {
        _init();
        return -1;
      }
    }
    _w=0;
    _h++;
  }
  for(int i =0; i<4; i++) {
    for(int j=0; j<4; j++) {
      printf("%d ",prac[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return 1;
}

// 해당 퍼즐이 들어갈 수 있는 모든 곳에 넣어보는 함수.
// 만약 모든 곳을 돌아보고도 답이 안나오면 그냥 종료된다.
// 넣을 수 있는 곳에는 무조건 test 함수를 돌려보고, 들어간다면 다음 퍼즐을 맞춰본다.
// turn이 5가 된다면 모든 퍼즐을 맞춰봤다는 의미이기 때문에 종료한다.
void combi(int turn, int prac[4][4]) {
  if(turn == 5) {
    printf("final!\n");
    for(int i =0; i<4; i++) {
      for(int j=0; j<4; j++) {
        printf("%d ",prac[i][j]);
      }
      printf("\n");
    }
    exit(0);
  }
  printf("combi : %d!\n", turn);
  int check = 0;
  int combi_check = 0;
  int _height = size[turn].first;
  int _width = size[turn].second;
  printf("height : %d, width : %d\n",_height, _width);
  for(int i =0; i<4; i++) {
    for(int j=0; j<4; j++) {
      // 범위를 넘어가는지 확인한다.
      if(i+_height<=4 && j+_width <=4) {
        printf("thissssssssssss\n");
        printf("this turn : %d\n",turn);
        // printf("%d %d\n",i, j);
        // 퍼즐이 잘 들어가는지 테스트 하는 함수.
        check = test(turn, i, j, _height, _width, prac);
        // 실패
        // 실패한다면 다음으로 넘어간다.
        if(check == -1) {
          check = 0;
          _init();
        }
        // 성공
        // 성공한다면 다음 퍼즐을 도전한다.
        else if(check == 1) {
          combi(turn+1, prac);
          check = 0;
        }
      }
    }
  }
}

int main() {
  scanf("%d", &cnt);
  printf("%d\n",cnt);
  int prac[4][4]={0,};
  for(int x=0; x<cnt; x++) {
    printf("x = %d\n",x);
    scanf("%d %d",&height, &width);
    size.push_back(make_pair(height,width));
    sort_size.insert(make_pair(height+width, x));
    printf("%d %d\n",height, width);
    for(int i=0; i<height; i++) {
      for(int j=0; j<width; j++) {
        cin >> temp;
        if(temp == 1) temp = x+1;
        test_vec.push_back(temp);
        // cout << temp << " ";
      }
      puzzle[x].push_back(test_vec);
      // cout << endl;
      test_vec.clear();
    }
  }

  multimap<int, int>::iterator iter;
  cout << endl;
  // 퍼즐이 맞춰진다면 combi 함수 내에서 끝나야 함.
  combi(0, prac);
  printf("----------------------\n");

  for(int i =0; i<4; i++) {
    for(int j=0; j<4; j++) {
      printf("%d ",prac[i][j]);
    }
    printf("\n");
  }
  printf("Failed!!\n");
  return 0;


}
