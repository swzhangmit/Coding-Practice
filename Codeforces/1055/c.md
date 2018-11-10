# C. Lucky Days

time limit per test: 1 second

memory limit per test: 256 megabytes

input: standard input

output: standard output

Bob and Alice are often participating in various programming competitions. Like many competitive programmers, Alice and Bob have good and bad days. They noticed, that their lucky and unlucky days are repeating with some period. For example, for Alice days [𝑙𝑎;𝑟𝑎] are lucky, then there are some unlucky days: [𝑟𝑎+1;𝑙𝑎+𝑡𝑎−1], and then there are lucky days again: [𝑙𝑎+𝑡𝑎;𝑟𝑎+𝑡𝑎] and so on. In other words, the day is lucky for Alice if it lies in the segment [𝑙𝑎+𝑘𝑡𝑎;𝑟𝑎+𝑘𝑡𝑎] for some non-negative integer 𝑘.

The Bob's lucky day have similar structure, however the parameters of his sequence are different: 𝑙𝑏, 𝑟𝑏, 𝑡𝑏. So a day is a lucky for Bob if it lies in a segment [𝑙𝑏+𝑘𝑡𝑏;𝑟𝑏+𝑘𝑡𝑏], for some non-negative integer 𝑘.

Alice and Bob want to participate in team competitions together and so they want to find out what is the largest possible number of consecutive days, which are lucky for both Alice and Bob.

### Input
The first line contains three integers 𝑙𝑎, 𝑟𝑎, 𝑡𝑎 (0≤𝑙𝑎≤𝑟𝑎≤𝑡𝑎−1,2≤𝑡𝑎≤109) and describes Alice's lucky days.

The second line contains three integers 𝑙𝑏, 𝑟𝑏, 𝑡𝑏 (0≤𝑙𝑏≤𝑟𝑏≤𝑡𝑏−1,2≤𝑡𝑏≤109) and describes Bob's lucky days.

It is guaranteed that both Alice and Bob have some unlucky days.

### Output
Print one integer: the maximum number of days in the row that are lucky for both Alice and Bob.

## Solution
```
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
```
