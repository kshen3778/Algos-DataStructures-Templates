#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


class Graph {

  public:
    int v;
    map<pair<int,int>, vector<pair<int,int>>> adj;
    Graph(int v){
      this->v = v;

    }
    //add edge to undirected graph
    //(num1, num2) <---> (num3, num4)
    //can use "pair" instead too, just decided to be lazy
    void addEdge(int num1, int num2, int num3, int num4){

      adj[make_pair(num1, num2)].push_back(make_pair(num3, num4));
      adj[make_pair(num3, num4)].push_back(make_pair(num1, num2));
    }


    //Note: must use &visited reference because one visited array is shared amongst all dfs calls in connectedComponents
    void dfs(pair start, map<pair<int,int>, bool> &visited){
      //TODO: Complete

    }

    vector<pair<int,int>> connectedComponents(){
      //TODO:Define visited map

      for(/*loop through adj map*/){
        if(visited[i] == false){
          //TODO: Pass in a set to get all the numbers in this connected component
          dfs(i, visited, /*set*/);
          //TODO: Get min and max of set and that's the new interval: [min, max]
          //TODO: store all new intervals in a new vector
        }
      }

      //return new interval vector
    }

    //check whether two intervals overlap
    bool overlap(vector<int> p1, vector<int> p2){
      return (p1[0] <= p2[1]) && (p2[0] <= p1[1]);
    }

};

int main() {
    vector<vector<int>> intervals = {{1,5},{4,7},{6,10},{15,17},{16,20}};
    Graph g(intervals.size());

    //create graph
    for(int i=0; i<intervals.size(); i++){
      for(int j=0; j<intervals.size(); j++){
        if(g.overlap(intervals[i], intervals[j])){
          g.addEdge(intervals[i][0], intervals[i][1], intervals[j][0], intervals[j][1]);
        }
      }
    }

    //TODO: call connected components method

}
