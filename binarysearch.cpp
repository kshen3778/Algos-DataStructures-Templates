#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

//returns location of x or -1 if not found
int binarySearch(vector<int> &vec, int l, int r, int x){
  if(r >= l){
    int mid = l + (r - l) / 2;

    //FOUND IT
    if(vec[mid] == x){
      return mid;
    }

    //x must be smaller than mid, so it's in the left part
    if(vec[mid] > x){
      return binarySearch(vec, l, mid - 1, x);
    }
    //otherwise it's gotta be in the right part
    else{
      return binarySearch(vec, mid + 1, r, x);
    }

  }

  //not found
  return -1;
}

int main(){
  vector<int> vec;
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(10);
  vec.push_back(40);
  int size = vec.size();

  int x = 10;
  cout << binarySearch(vec, 0, size-1, x) << endl;
  x = 12;
  cout << binarySearch(vec, 0, size-1, x) << endl;

  //vector<int>::iterator it = vec.begin();


}
