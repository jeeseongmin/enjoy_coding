#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
inline void end_game() {cout<<0; }

bool front_compare(string a, string b) {
  if(a.front() == b.front()) {
    if(a.front() == a.back() && b.front() != b.back()) {
      return true;
    }
    else if(a.front() != a.back() && b.front() == b.back()) {
      return false;
    }
    else {
      return a < b;
    }
  }else {
    return a.front() < b.front();
  }
}

bool back_compare(string a, string b) {
  if(a.back() == b.back()) {
    return a < b;
  }else {
    return a.back() < b.back();
  }
}

int main() {
  int num, flag = 0;
  string str = "";
  cin >> num;
  vector<string> _front;
  vector<string> _back;
  vector<string> answer;
  vector<int> check(num, 0);

  for(int i=0; i<num; i++) {
    cin >> str;
    _front.push_back(str);
    _back.push_back(str);
  }

  for(int i=0; i<_front.size(); i++) {
    cout << _front[i] << endl;
  }
  cout << endl;
  sort(_front.begin(), _front.end(), front_compare);
  sort(_back.begin(), _back.end(), back_compare);
  cout << "front" << endl;
  for(int i=0; i<_front.size(); i++) {
    cout << _front[i] << endl;
  }
  cout << endl;
  cout << "back" << endl;
  for(int i=0; i<_back.size(); i++) {
    cout << _back[i] << endl;
  }
  cout << endl;

  for(int i=0; i<_back.size(); i++) {
    if(check[i] == 0) {
      if(answer.size() != 0 && answer.size() != num-1) {
        if(answer[answer.size()-1].back() != _front[i].front()) {
          cout<<"check1 - size : " << answer.size() << endl;
          end_game();
          break;
        }
      }
      answer.push_back(_back[i]);
      check[i] = 1;

      for(int j=0; j<_front.size(); j++) {
        printf("j : %d\n",j);
        printf("check[%d] : %d\n",j, check[j]);
        if(check[j] == 0) {
          cout<< endl;
          cout << answer[answer.size()-1] << endl;
          cout << endl;
          if(answer[answer.size()-1].back() == _front[j].front()) {
            check[j] = 1;
            answer.push_back(_front[j]);
            break;
          }
          else continue;
          cout<<"check2" << endl;
          end_game();
        }
      }
      if(answer.size() == num) break;

    }
  }



  // for(int i=0; i<_front.size()-1; i++) {
  //   if(check[i] == 0) {
  //     if(answer.size() != 0) {
  //       if(answer[answer.size()-1].back() != _front[i].front()) {
  //         end_game();
  //         break;
  //       }
  //     }
  //     answer.push_back(_front[i]);
  //     check[i] = 1;
  //     for(int j=i+1; j<_front.size(); j++) {
  //       if(answer[answer.size()-1].back() == _front[j].front()) {
  //         check[j] = 1;
  //         answer.push_back(_front[j]);
  //         break;
  //       }
  //       else continue;
  //       end_game();
  //     }
  //   }
  //   if(answer.size() == num) break;
  // }
  // cout << "size : " << _front.size() << endl;
  // for(int i=0; i<_front.size()-1; i++) {
  //   if(_front[i].back() != _front[i+1].front()) {
  //     end_game();
  //   }
  // }
  for(int i=0; i<answer.size(); i++) {
    cout << answer[i] << endl;
  }
}
