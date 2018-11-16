#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;
void computeLPSArray(string pat, int M, int* lps); 
  
int KMPSearch(string pat, string txt) 
{ 
    int M = pat.length(); 
    int N = txt.length(); 
    int lps[M]; 
  
    computeLPSArray(pat, M, lps); 
  
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) {
            return i - j; 
            j = lps[j - 1]; 
        } 
  
        else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    }
    return -1; 
} 
  
void computeLPSArray(string pat, int M, int* lps) 
{ 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else { 
            if (len != 0) { 
                len = lps[len - 1]; 
  
            } 
            else { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 
  
int main() {
  int n;
  cin >> n;
  vector<string> w1;
  vector<string> w2;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    w1.push_back(s);
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    w2.push_back(s);
  }
  vector<string> diffs1;
  vector<string> diffs2;
  vector<int> startindices;
  vector<int> endindices;
  string find = " ";
  string replace = " ";
  for (int i = 0; i < n; i++) {
    if (w1[i] == w2[i]) {
      //sames.push_back(w1[i]);
    } else {
      diffs1.push_back(w1[i]);
      diffs2.push_back(w2[i]);
      int startix = -1;
      int endix = -1;
      for (int j = 0; j < w1[i].length(); j++) {
        if (w1[i][j] != w2[i][j]) {
          startix = j;
          startindices.push_back(startix);
          break;
        }
      }
      for (int j = w1[i].length() - 1; j >= 0; j--) {
        if (w1[i][j] != w2[i][j]) {
          endix = j + 1;
          endindices.push_back(endix);
          break;
        }
      }
      string start = w1[i].substr(startix, endix - startix);
      string end = w2[i].substr(startix, endix - startix);
      if (find == " ") {
        find = start;
        replace = end;
      } else if (find != start || replace != end) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  for (int i = 0; i < startindices.size(); i++) {
    for (int j = startindices[i]; j < ?; j++) {
      //finish later
    }
  }

  for (int i = 0; i < w1.size(); i++) {
    int search = KMPSearch(find, w1[i]);
    if (search != -1 && w2[i].substr(search, find.length()) != replace) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  cout << find << endl << replace << endl;

  return 0;
}
