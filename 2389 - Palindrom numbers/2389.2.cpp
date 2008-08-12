/*
  Accepted
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

bool isPali(int n, const int &base){
  string s="", t="";
  while (n){
    int r = n % base;
    n /= base;
    if (r <= 9){
      s = s + (char)('0' + r);
      t = (char)('0' + r) + t;
    }else{
      r -= 10;
      s = s + (char)('a' + r);
      t = (char)('a' + r) + t;
    }
  }
  return (s == t);
}

int main(){
  int n;
  while (cin >> n && n){
    vector<int> p;
    for (int i=2; i<=16; ++i){
      if (isPali(n, i)){
        p.push_back(i);
      }
    }
    cout << "Number " << n << " is ";
    if (p.size() == 0){
      cout << "not palindrom" << endl;
    }else{
      cout << "palindrom in basis ";
      copy(p.begin(), p.end()-1, ostream_iterator<int>(cout, " "));
      cout << p.back() << endl;
    }
  }
  return 0;
}
