# B. Alice and Hairdresser

time limit per test: 1 second

memory limit per test: 256 megabytes

input: standard input

output: standard output

Alice's hair is growing by leaps and bounds. Maybe the cause of it is the excess of vitamins, or maybe it is some black magic...

To prevent this, Alice decided to go to the hairdresser. She wants for her hair length to be at most 𝑙 centimeters after haircut, where 𝑙 is her favorite number. Suppose, that the Alice's head is a straight line on which 𝑛 hairlines grow. Let's number them from 1 to 𝑛. With one swing of the scissors the hairdresser can shorten all hairlines on any segment to the length 𝑙, given that all hairlines on that segment had length strictly greater than 𝑙. The hairdresser wants to complete his job as fast as possible, so he will make the least possible number of swings of scissors, since each swing of scissors takes one second.

Alice hasn't decided yet when she would go to the hairdresser, so she asked you to calculate how much time the haircut would take depending on the time she would go to the hairdresser. In particular, you need to process queries of two types:

0 — Alice asks how much time the haircut would take if she would go to the hairdresser now.

1 𝑝 𝑑 — 𝑝-th hairline grows by 𝑑 centimeters.
Note, that in the request 0 Alice is interested in hypothetical scenario of taking a haircut now, so no hairlines change their length.

### Input
The first line contains three integers 𝑛, 𝑚 and 𝑙 (1≤𝑛,𝑚≤100000, 1≤𝑙≤109) — the number of hairlines, the number of requests and the favorite number of Alice.

The second line contains 𝑛 integers 𝑎𝑖 (1≤𝑎𝑖≤109) — the initial lengths of all hairlines of Alice.

Each of the following 𝑚 lines contains a request in the format described in the statement.

The request description starts with an integer 𝑡𝑖. If 𝑡𝑖=0, then you need to find the time the haircut would take. Otherwise, 𝑡𝑖=1 and in this moment one hairline grows. The rest of the line than contains two more integers: 𝑝𝑖 and 𝑑𝑖 (1≤𝑝𝑖≤𝑛, 1≤𝑑𝑖≤109) — the number of the hairline and the length it grows by.

### Output
For each query of type 0 print the time the haircut would take.

## Solution
```
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, l;
  cin >> n >> m >> l;
  vector<int> hairlines;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    hairlines.push_back(h);
  }


  int incut = 0;
  int count = 0;
  for (int j = 0; j < n; j++) {
    if (hairlines[j] > l) {
      if (!incut) {
        incut = 1;
        count++;
      }
    } else {
      if (incut) {
        incut = 0;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    int ti;
    cin >> ti; 
    if (ti == 0) {
      cout << count << endl;
    }

    else {
      int pi, di;
      cin >> pi >> di;
      if (hairlines[pi - 1] <= l && hairlines[pi - 1] + di > l) {
        int c = 1;
        if (pi - 1 > 0 && hairlines[pi - 2] > l) {
          c--;
        }
        if (pi - 1 < n - 1 && hairlines[pi] > l) {
          c--;
        }
        count+=c;
      }
      hairlines[pi - 1] = min(hairlines[pi - 1] + di, 1000000001);
    }
  }
  return 0;
}
```
