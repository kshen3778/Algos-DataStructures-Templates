#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

void printArray(vector<int> arr){
  int i;
  for (i = 0; i < arr.size(); i++){
    cout << arr[i] << " " << endl;
  }
  cout << endl;
}

//merges left and right subarrays that are in arr
void merge(vector<int> &arr, int l, int m, int r){
  int i,j,k;
  int n1 = m - l + 1; //length of left array
  int n2 = r - m; //length of right array

  //temp arrays
  vector<int> L(n1);
  vector<int> R(n2);

  //copy data to L and R (I can also not set initial vector size and use push_back)
  for(i = 0; i < n1; i++){
    L[i] = (arr[l + i]);
  }
  for(j = 0; j < n2; j++){
    R[j] = (arr[m + 1 + j]);
  }



  //merge temp arrays back into the master array
  i = 0;
  j = 0;
  k = l;
  while( i < n1 && j < n2){
    //basically whichever is bigger we put in
    if (L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    }
    else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  //if one of the temp is empty already just copy in all remaining elements of the other
  while (i < n1){
    arr[k] = L[i];
    i++;
    k++;
  }

  while(j < n2){
    arr[k] = R[j];
    j++;
    k++;
  }

}

void mergeSort(vector<int> &arr, int l, int r){
  if(l < r){
    int m = (l+r)/2;

    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr, l, m ,r);
  }
}


int main(){
  vector<int> arr{12, 11, 13, 5, 6, 7};
  printArray(arr);

  mergeSort(arr, 0, arr.size() - 1);

  printArray(arr);

}
