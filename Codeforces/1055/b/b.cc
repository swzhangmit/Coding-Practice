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
