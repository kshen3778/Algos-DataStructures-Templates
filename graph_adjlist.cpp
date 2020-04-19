#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {


  public:
    int v;
    vector<vector<int>> adj;
    Graph(int v){
      this->v = v;
      adj.resize(v);
    }
    //add edge to undirected graph
    void addEdge(int v, int w){

      adj[v].push_back(w);
      adj[w].push_back(v);
    }

    //Note: must use &visited reference because one visited array is shared amongst all dfs calls in connectedComponents
    void dfs(int node, vector<bool> &visited){
      visited[node] = true;

      cout << node << " ";

      //get adjacent of node and if not visited then dfs them
      for(int i=0; i<adj.size(); i++){
        if(count(adj[node].begin(),adj[node].end(), i) && (!visited[i])){
          dfs(i, visited);
        }
      }

      return;

    }

};

int main() {
    Graph g(5); // 5 vertices numbered from 0 to 4
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    vector<bool> visited(g.v, false);
    g.dfs(2, visited);
}
