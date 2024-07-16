#include<iostream>
#include<vector>
#include<queue>
const long long  INF = 1e18	;
using namespace std;
 
 
int main(){
    long long n, m;
    cin >> n >> m;
 
    // taking input of graph
    vector<vector<pair<long long , long long >>> graph(n + 1);
    for (long long  i = 0; i < m; i++) {
        long long  a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
 
    // initializing distances to all cities as infinity
    vector<long long > dist(n + 1, INF);
    dist[1] = 0; // Syrjälä is city 1
 
    // priority queue to store cities to be processed
    priority_queue<pair<long long , long long >, vector<pair<long long , long long >>, greater<pair<long long , long long >>> pq;
    pq.push({0, 1}); // start from Syrjälä
 
    // Dijkstra's algorithm with priority queue which is used to find the shortest path between 
//	2 nodes  of graph. Here, a and b as nodes and c as the weight on th egde between a and b 
    while (!pq.empty()) {
        long long  u = pq.top().second;
        long long  d = pq.top().first;
        pq.pop();
 
        if (d > dist[u]) continue;
 
        // processing all neighbors of city u
        for (auto edge : graph[u]) {
            long long  v = edge.first;
            long long  c = edge.second;
 
            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
            }
        }
    }
 
    // printing the shortest route lengths from Syrjälä to every city
    for (long long  i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
 
    return 0;
}