#include <iostream>
#include <vector>

using namespace std;
int main() {
  int cnt, width, height, temp;
  // scanf("%d", cnt);
  // vector<int> puzzle[cnt+1];
  // int (*arr)[cnt+1];  // 배열들의 포인터 값을 저장함.
  vector <vector <int> > vec10;

  vector<int> vec1;
  vec1.push_back(1);
  vec1.push_back(0);
  vec1.push_back(0);
  vec1.push_back(0);
  vec10.push_back(vec1);
  vec1.clear();

  vec1.push_back(1);
  vec1.push_back(1);
  vec1.push_back(1);
  vec1.push_back(1);
  vec10.push_back(vec1);

  for(int i=0; i<vec10.size(); i++) {
    cout << "vec10[" << i << "]";
    for( int j=0; j<vec10[i].size(); j++) {
      cout << vec10[i][j] << " ";
    }
    cout << endl;
  }

  // for(int i =1; i<=cnt; i++) {
  //   scanf("%d %d",width, height);
  //   int array[width+1][height+1];
  //   for(int i =0; i<width*height; i++) {
  //     scanf("%d", temp);
  //
  //   }
  // }
}
