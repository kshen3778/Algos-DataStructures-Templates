#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Graph {
  int v; //number of vertices
  //int e; //number of edges
  vector<vector<int>> adj;

  public:
    Graph(int v){
      this->v = v;
      //this->e = e;

      //creates empty adj matrix
      for(int row = 0; row < v; row++){
        vector<int> arr;
        for(int column = 0; column < v; column++){
          arr.emplace_back(0);
        }
        adj.emplace_back(arr);
      }
    }

    Graph(vector<vector<int>> adjMatrix){
      this->v = adjMatrix.size();
      this->adj = adjMatrix;
    }

    //add an edge and speciy if its bidirectional
    void addEdge(int start, int end, bool bi){
      adj[start][end] = 1;

      if(bi){
        adj[end][start] = 1;
      }
    }

    //do a bfs traversal
    void bfs(int start){
      //keep track of visited array
      vector<bool> visited(v, false); //at the beginning every node is unsivited
      queue<int> q;
      q.push(start);

      visited[start] = true;

      int cur;
      while(!q.empty()){
        cur = q.front();
        cout << cur << " ";
        q.pop();
        //get all adjancent nodes
        for(int i = 0; i < v; i++) {
          //if connected and hasn't been visited
          if(adj[cur][i] == 1 && (!visited[i])) {
            q.push(i);

            visited[i] = true;
          }
        }

      }
    }

    //recursive function for DFS
    void dfs_recurse(int node, vector<bool> visited){
      visited[node] = true;
      cout << node << " ";

      //get all adjacent nodes and recurse them
      for(int i = 0; i < v; i++) {
        //if connected and hasn't been visited
        if(adj[node][i] == 1 && (!visited[i])) {
          dfs_recurse(i, visited);
        }
      }

    }

    //do dfs traversal
    void dfs(int start){
      vector<bool> visited(v, false);

      //call recursive function
      dfs_recurse(start, visited);
    }

};

int main(){
  Graph* graph = new Graph(5);
  graph->addEdge(0, 2, true);
  graph->addEdge(1, 3, true);
  graph->addEdge(0, 1, true);
  graph->bfs(0);
  cout << endl;

  //alternatively Graph graph(v,e) also works so its on Stack
  Graph g(4);
  g.addEdge(0, 1, false);
  g.addEdge(0, 2, false);
  g.addEdge(1, 2, false);
  g.addEdge(2, 0, false);
  g.addEdge(2, 3, false);
  g.addEdge(3, 3, false);
  g.dfs(2);

}
