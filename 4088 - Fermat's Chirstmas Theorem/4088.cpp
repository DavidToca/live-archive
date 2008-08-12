/*
  Accepted
 */
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <math.h>
using namespace std;

const int MAXN = 1000001;

int primes[MAXN], special[MAXN];

bool isPrime(int n){
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  int raiz = int(sqrt(n));
  for (int i=3; i<=raiz+1; i += 2) if (n % i == 0) return false;
  return true;
}

int main(){
  primes[0] = primes[1] = 0;
  for (int i=2; i<MAXN; ++i){
    primes[i] = primes[i-1];
    special[i] = special[i-1];
    if (isPrime(i)){
      primes[i]++;
      special[i] += (i % 4 == 1 || i == 2);
    }
  }
  long long a, b, p, s;
  while (cin >> a >> b && (a != -1 || b != -1)){
    //(assert(a >= 0 && b >= 0);
    assert(a <= b && b < 1000000);
    p = s = -1;

    if (b <= 0){
      s = 0;
      p = 0;
    }else if (a <= 0 && b > 0){
      p = primes[b];x
      s = special[b];
    }

    if (a > 0){
      p = primes[b] - primes[a-1];
      s = special[b] - special[a-1];
    }
    assert(p != -1 && s != -1);
    cout << a << " " << b  << " " << p << " " << s << endl;
  }
  return 0;
}
