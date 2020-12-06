#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

int main() {
  int N, right=0, left=0, del=0, cnt;
  char word;
  cin >> N;
  string str;
  getline(cin, str);
  vector<char> sentence;
  stack<char> tmp;
  for(int i=0; i<N; i++) {
    getline(cin, str);
    cout<<"string : "<< str << ", size : " << str.size() << endl;
    for(int j=0; j<str.size(); j++) {
      if(str[j] == '-') {
        // 앞에꺼 erase
        printf("check1\n");
        sentence.pop_back();
      }
      else if(str[j] == '<') {
        printf("check2\n");
        if(right > 0) right--;
        else left++;
      }
      else if(str[j] == '>') {
        printf("check3\n");
        if(left > 0) left--;
        else right++;
      }
      // 문자일때.
      else {
        printf("check4\n");
        if(left > 0) {
          while(left != 0) {
            word = sentence.back();
            tmp.push(word);
            sentence.pop_back();
            left--;
          }
          sentence.push_back(str[j]);
          while(!tmp.empty()) {
            sentence.push_back(tmp.top());
            tmp.pop();
          }
        }
        else {
          sentence.push_back(str[j]);
          left =0;
          right =0;
        }
      }
      cout << "j : " << j << ", " << left << " " << right << ", sentence size : " << sentence.size() << endl;
    }

    for(int x=0; x<sentence.size(); x++) {
      cout << sentence[x];
    }
    cout << endl;

  }
}
