#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <limits.h>
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
    void addEdge(int start, int end, int weight, bool bi){
      adj[start][end] = weight;

      if(bi){
        adj[end][start] = weight;
      }
    }

    //gets the node with the min distance value that's not already in set
    int minDistance (vector<int> dist, set<int> sptSet){
      int min = INT_MAX;
      int min_index;

      for(int i = 0; i < v; i++){
        if(!sptSet.count(i) && dist[i] <= min){
          min = dist[i];
          min_index = i;
        }
      }

      return min_index;
    }

    void printDistances (vector<int> dist){
      cout << "Node distances from source: " << endl;
      for(int i = 0; i<v; i++){
        cout << "Node: " << i << " Distance: " << dist[i] << endl;
      }
    }

    void dijkstra(int src){
      vector<int> dist(v, 0); //holds shortest distance from src to i
      set<int> sptSet;

      //start with all distances as infnite
      for(int i=0; i<v; i++){
        dist[i] = INT_MAX;
      }

      //dist from src to src is 0
      dist[src] = 0;
      //keep going until sptSET is full (contains all the node)
      while(sptSet.size() != v){
        //get min distance node
        int u = minDistance(dist, sptSet);

        sptSet.insert(u);

        //update distance values of adjacent nodes
        for(int i = 0; i < v; i++){

          //update dist[i] only if not in set
          //and dist[i] is not infinite (hasn't been seen before)
          //^ABOVE two conditions should always return the same though
          //and if there's an edge connecting the two nodes share an edge
          //and if the new path being calculated is less than the current value of dist[i]
          if(!sptSet.count(i) && adj[u][i] && dist[u] != INT_MAX && (dist[u] + adj[u][i]) < dist[i]){
            dist[i] = dist[u] + adj[u][i];
          }
        }
      }

      printDistances(dist);

    }



};

int main(){
  //You can create a graph using a prebuilt adjacency matrix or create it yourself
  vector<vector<int>> adj { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
  Graph graph(adj);
  graph.dijkstra(0);

  // Graph g(4);
  // g.addEdge(0, 1, false);
  // g.addEdge(0, 2, false);
  // g.addEdge(1, 2, false);
  // g.addEdge(2, 0, false);
  // g.addEdge(2, 3, false);
  // g.addEdge(3, 3, false);
  // g.dfs(2);

}
