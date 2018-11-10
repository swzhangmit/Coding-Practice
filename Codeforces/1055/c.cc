#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int GCD(int u, int v) {
    while ( v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}


int main() {
  int la, ra, ta;
  int lb, rb, tb;
  cin >> la >> ra >> ta;
  cin >> lb >> rb >> tb;
  int gcd = GCD(ta, tb);

  if (la > lb) {
    int shift = (la-lb) / gcd;
    lb += shift * gcd;
    rb += shift * gcd;
    cout << max(0, max(min(ra, rb) - max(la, lb) + 1, min(ra, rb + gcd) - max(la, lb + gcd) + 1)) << endl; 
  }
  else { 
    int shift = (lb-la) / gcd;
    la += shift * gcd;
    ra += shift * gcd;
    cout << max(0, max(min(ra, rb) - max(la, lb) + 1, min(rb, ra + gcd) - max(lb, la + gcd) + 1)) << endl; 
  }

  return 0;
}
