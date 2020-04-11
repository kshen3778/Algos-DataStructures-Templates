#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

//https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/
//Count all palindrome substrings: We will count all unique palindromes of any lengths (1 or above)

int countPS(string s){
  int n = s.length();
  set<string> palindromes; //stores all palindromes since we don't want duplicates

  //vector<vector<int>> dp(n, vector<int>(n, 0)); //dp[i][j] contains the # of palindromes for substring string[i....j]
  vector<vector<bool>> P(n, vector<bool>(n, false)); //p[i][j] is true if string[i.....j] is a palindrome

  //You need to atleast fill the DP table to have palindromes of lengths 1 and 2 for the indexing to work

  //get all palindromes of length 1
  for(int i=0; i<n; i++){
    P[i][i] = true;
    //dp[i][i] += 1;
    palindromes.insert(s.substr(i, 1));
  }

  //get all palindromes of length 2
  for(int i=0; i<n-1; i++){
    if(s[i] == s[i+1]){
      P[i][i+1] = true;
      //dp[i][i+1] += 1;
      palindromes.insert(s.substr(i, 2));
    }
  }

  //fill the rest of the DP table
  for(int gap=2; gap<n; gap++){ //starting at gap=2 means substrings of length 3
    for(int start=0; start<n-gap; start++){ //start index of substring
      int end = start + gap; //end index of substring

      //check if substring is palindrome
      //check if start and end are same character and the content in between is a palindrome
      if(s[start] == s[end] && P[start+1][end-1]){
        P[start][end] = true;
        palindromes.insert(s.substr(start, gap));
      }

      //increment DP table
      // if(P[start][end] == true){
      //   //if it was a palindrome: "baab" -> palins("baa") + palins("aab") + 1 - palins("aa")
      //   //duplicates must be removed since its double counted in palins("baa"),palins("aab")
      //   //+1 is for "baab" entire string
      //   dp[start][end] = dp[start][end - 1] + dp[start + 1][end] - dp[start + 1][end - 1] + 1;
      // } else {
      //   //if it wasn't a palindrome: "baac" -> palins("baa") + palins("aac") - palins("aa")
      //   //duplicates are once again removed ("aa" part)
      //   //there is no +1 because "baac" is not a palindrome
      //   dp[start][end] = dp[start][end - 1] + dp[start + 1][end] - dp[start + 1][end - 1];
      // }

    }

  }

  //normally you'd return dp[0][n-1] but we want all the unique palindromes
  //get the size of the set
  cout << "All Palindromes: " << endl;
  for (auto it=palindromes.begin(); it != palindromes.end(); ++it)
    cout << *it << " ";
  cout << endl;
  return palindromes.size();

}

int main(){
  string s = "mokkori";
  cout << countPS(s) << endl;
}
