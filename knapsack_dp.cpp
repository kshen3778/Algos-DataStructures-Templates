#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int knapSack(int W, vector<int> wt, vector<int> val, int n){

  //create matrix K with size n+1,w+1 because we need enough room for all values from 0,0 (inclusive) all the way to n,W
  vector<vector<int>> K(n+1, vector<int>(W+1, 0));

  for(int i=0; i<=n; i++){
    for(int w=0; w <= W; w++){
      if (i==0 || w==0){
        K[i][w] = 0; //a bag with 0 items and 0 weights by default has value 0
      }
      else if (wt[i-1] <= w){
        //Note: val[i-1] accesses the value of the ith element
        //We select the max value between adding in the ith item (first param) OR not adding in the ith item (second param)
        K[i][w] = max (val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
      }
      else{
        //If adding in the ith item will exceed bag weight limit, then don't add it
        K[i][w] = K[i-1][w];
      }
    }
  }

  return K[n][W];
}

int main(){
  vector<int> val = {60, 100, 120};
  vector<int> wt = {10, 20, 30};
  int  W = 50;
  int n = 3;
  cout << knapSack(W, wt, val, n) << endl;

}
