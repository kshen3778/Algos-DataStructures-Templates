#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
  int v; //number of vertices
  //int e; //number of edges
  vector<vector<int> > adj;

  public:
    Graph(int v){
      this->v = v;
      //this->e = e;

      //creates empty adj matrix
      for(int row = 0; row < v; row++){
        vector<int> arr;
        for(int column = 0; column < v; column++){
          arr.push_back(0);
        }
        adj.push_back(arr);
      }
    }

    Graph(vector<vector<int> > adjMatrix){
      this->v = adjMatrix.size();
      this->adj = adjMatrix;
    }

    //Find minimum key node from un-included nodes
    int minKey(vector<int> key, vector<bool> mstSet){
      int min = INT_MAX;
      int min_index;

     //loop through all nodes
     //if haven't been visited and has smaller key value, it's the new min node
      for(int i=0; i < v; i++){
        if(mstSet[i] == false && key[i] < min){
          min = key[i];
          min_index = i;
        }
      }

      return min_index;
    }

    //print the MST
    //parent is an array ith index contains the parent of node i
    void printMST(vector<int> parent){
      cout << "Edge Weight" <<endl;
      //parent[0] is the root node
      for(int i=1; i < v; i++){
        cout << parent[i] << " - " << i << " " << adj[i][parent[i]] << endl;
      }
    }

    //will construct a parent array that represents the MST
    void primAlgo(){
      vector<int> parent(v, 0);
      vector<int> key(v, INT_MAX);
      vector<bool> mstSet(v, false);

      //1st node in MST is the root (node 0 by default)
      key[0] = 0;
      parent[0] = -1;

      //loop v-1 times since the MST will have exactly that many edges
      //alternatively: loop until all nodes have been put in mstSet or are visited (mstSet would need to be defined differently and not set size, would need to add nodes to it)
      for(int i=0; i< v-1; i++){
        //exatract minimum key
        int min_key = minKey(key, mstSet);
        mstSet[min_key] = true;

        //loop through adjacent nodes
        //update key values and parent index of adjacent nodes only if they are not included, and are smaller.
        for(int j = 0; j < v; j++){
          if(adj[min_key][j] && mstSet[j] == false && adj[min_key][j] < key[j]){
            parent[j] = min_key; //parent of adj is the current
            key[j] = adj[min_key][j]; //key value of adj node is the weight
          }
        }

      }

      printMST(parent);
    }

};
int main() {

  vector<vector<int> > adjM{{ 0, 2, 0, 6, 0 },{ 2, 0, 3, 8, 5 },  { 0, 3, 0, 0, 7 },{ 6, 8, 0, 0, 9 },  { 0, 5, 7, 9, 0 }};
  
  Graph g(adjM);
  g.primAlgo();
}
