#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

// struct Edge{
//   int src;
//   int dest;
//   bool operator==( const Edge& e) const
//   {
//      if(src == r.src && dest == e.dest){
//        return true;
//      }
//      return false;
//   }
// };

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


    //recursive function for DFS
    //if reach end then check if visited is equal to number of nodes in graph
    void dfs_recurse(int node, vector<int> visited, int end){
      visited.emplace_back(node);

      //checks whether this current path is a hamiltonian path
      if(node == end && visited.size() == v){
        for (int i=0; i<visited.size(); i++){
          cout << visited[i] << " ";
        }
        cout << endl;
      }

      //get all adjacent nodes and recurse them
      for(int i = 0; i < v; i++) {
        //if connected and hasn't been visited
        if(adj[node][i] == 1 && (find(visited.begin(), visited.end(), i) == visited.end()) ) {
          dfs_recurse(i, visited, end);
        }
      }

    }

    //do dfs traversal
    void dfs(int start, int end){
      vector<int> visited;

      //call recursive function
      dfs_recurse(start, visited, end);
    }

    //Find all hamiltonian paths between 2 vertices
    //if it outputs nothing then no hamiltonian paths exist
    void hamiltonian(int start, int end){

      cout << "Hamiltonian Paths: " << endl;

      dfs(start, end);
    }

};

int main(){

  //Directed graph
  //Graph g(4);
  // g.addEdge(0, 1, true);
  // g.addEdge(1, 2, true);
  // g.addEdge(2, 3, true);
  // g.addEdge(3, 1, true);

  // g.addEdge(0, 1, false);
  // g.addEdge(0, 2, false);
  // g.addEdge(0, 0, false);
  // g.addEdge(1, 2, false);
  // g.addEdge(2, 0, false);
  // g.addEdge(2, 3, false);
  // g.addEdge(3, 3, false);

  Graph g(5);
  g.addEdge(0,1,true);
  g.addEdge(1,4,true);
  g.addEdge(0,4,true);
  g.addEdge(0,2,true);
  g.addEdge(2,4,true);
  g.addEdge(2,3,true);

  g.hamiltonian(1, 3);

}
