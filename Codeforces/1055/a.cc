#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    a.push_back(ai);
  }
  for (int i = 0; i < n; i++) {
    int bi;
    cin >> bi;
    b.push_back(bi);
  }

  if (a[0] == 0) {
    cout << "NO" << endl;
    return 0;
  }
  int latest = 0;
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] == 1 && b[i] == 1) {
      latest = i;
      break;
    }
  }
  if (a[s - 1] == 1 || (latest >= s - 1 && b[s - 1] == 1)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  } 
  return 0;
}
