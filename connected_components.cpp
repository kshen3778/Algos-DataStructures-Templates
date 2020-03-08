#include <iostream>
#include <vector>
using namespace std;

class Graph {
  int v;
  vector<vector<int> > adj;

  public:
  Graph(int v){
    this->v = v;
    
    //creates empty adj matrix
    for(int row = 0; row < v; row++){
      vector<int> arr;
      for(int column = 0; column < v; column++){
        arr.push_back(0);
      }
      adj.push_back(arr);
    }
  }
  //add edge to undirected graph
  void addEdge(int v, int w){
    adj[v][w] = 1;
    adj[w][v] = 1;

  }

  //Note: must use &visited reference because one visited array is shared amongst all dfs calls in connectedComponents
  void dfs(int node, vector<bool> &visited){
    visited[node] = true;

    cout << node << " ";

    //get adjacent of node and if not visited then dfs them
    for(int i=0; i<adj.size(); i++){
      if((adj[node][i] == 1) && (!visited[i])){
        dfs(i, visited);
      }
    }

    return;

  }

  void connectedComponents(){
    //vector<bool>* visited = new vector<bool>(v, false);
    vector<bool> visited(v, false);

    for(int i=0; i<adj.size();i++){
      if(visited[i] == false){
        dfs(i, visited);
        cout << endl;
      }
    }
  }
};


int main() {
    Graph g(5); // 5 vertices numbered from 0 to 4 
    g.addEdge(1, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
    g.connectedComponents();
}
