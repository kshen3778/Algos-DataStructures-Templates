#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

//easier printing out of vectors
template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "{";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last)
            out << ", ";
    }
    out << "}";
    return out;
}

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

    //return nodes in [ ] format from an encoded X
    vector<int> getNodes(int x) {
        vector<int> v;

        // Converting the decimal number
        // into its binary equivalent.
        while (x > 0)
        {
            v.push_back(x % 2);
            x = x / 2;
        }

        vector<int> result;
        // Displaying the output when
        // the bit is '1' in binary
        // equivalent of number.
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 1)
            {
                result.emplace_back(i);

            }
        }

        return result;
    }

    //print out map values
    void printMap(map<pair<int, int>, vector<vector<int>>> myMap){
      for(auto it = myMap.cbegin(); it != myMap.cend(); ++it)
      {
          std::cout << getNodes(it->first.first) << " " << it->first.second << " " << it->second << "\n";
      }
    }

    //Find all hamiltonian paths between 2 vertices using modified Held Karp Algorithm
    void hamiltonian(int start, int end){


      int N = v; //number of nodes

      //DP table: dp[visited][last] = all paths from start to last node going through every node in visited
      //vector<vector<vector<int>>> dp(1<<(N-1), vector<vector<int>>(N, vector<int>()));

      map<pair<int, int>, vector<vector<int>> > dp;

      //populate dp table
      //each state is (visited nodes, last node)
      //Note: The last node isn't in the list of visited nodes

      //visited starts at 1 because at min 2^0=1
      for(int visited = 0; visited < (1<<(N-1)); visited++){
        for(int last = 0; last < N; last++){

          //make sure visited set does not contain the last node (second element in state pair)
          if(visited & 1<<last){
            continue;
          }

          //make sure visited set does not contain the start node
          if(visited & 1<<start){
            continue;
          }

          //make sure the last node isn't somehow the start node
          if(last == start){
            continue;
          }

          //make sure the end node isn't somehow visited
          if(visited & 1<<end){
            continue;
          }

          cout << "State: " << getNodes(visited) << ", " << last << endl;

          //check all nodes in visited that connect to last
          vector<int> nodes = getNodes(visited);
          //check if empty
          if(nodes.size() == 0){
            //if empty then the only path is start -> last
            if(adj[start][last] == 1){
              vector<int> initPath = {start, last};
              dp[make_pair(visited,last)].emplace_back(initPath);
            }
          }

          for(int i=0; i<nodes.size(); i++){
            if(adj[nodes[i]][last] == 1){
              cout << "Connection Found: " << nodes[i] << " to " << last << endl;
              //dp[visited][last] = all paths dp[visited minus nodes[i]][nodes[i]] + append last
              int other_nodes = visited - (1<<nodes[i]);

              //go through all paths in dp[visited minus nodes[i]][nodes[i]]
              for(int path = 0; path < dp[make_pair(other_nodes,nodes[i])].size(); path++){
                vector<int> new_path = dp[make_pair(other_nodes,nodes[i])][path];
                new_path.emplace_back(last);
                dp[make_pair(visited,last)].emplace_back(new_path);
              }



            }
          }
          cout << "DP Map: " << endl;
          printMap(dp);
          cout << endl;


        }
      }

      //get the state (every node in visited except start and end, last node)
      int encoded = 0;
      for(int i=0; i<N; i++){
        if(i != start && i != end){
          encoded += (1<<i);
        }
      }
      cout << "Hamiltonian Paths: " << endl;
      for(int i=0; i<dp[make_pair(encoded,end)].size(); i++){
        for(int j=0; j<dp[make_pair(encoded,end)][i].size(); j++){
          cout << dp[make_pair(encoded,end)][i][j] << " ";
        }
        cout << endl;
      }

    }

};

int main(){

  // //No Hamil Paths
  // Graph g(4);
  // g.addEdge(0, 1, true);
  // g.addEdge(1, 2, true);
  // g.addEdge(3, 1, true);
  // g.hamiltonian(0,3);

  //Two Hamil Paths
  Graph g(4);
  g.addEdge(0,1, true);
  g.addEdge(0,2, true);
  g.addEdge(0,3, true);
  g.addEdge(1,2, true);
  g.addEdge(1,3, true);
  g.addEdge(2,3, true);
  g.hamiltonian(0, 3);

}
