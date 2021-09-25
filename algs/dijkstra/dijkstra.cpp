#include <bits/stdc++.h>
#define MAX 1e8

using namespace std;

int shortest_path(int &n, vector<vector<pair<int,int>>> &a_list, vector<int> &distance, vector<bool> &checked, int source, int destiny){
    for(int i = 0; i < n; i++){
        distance[i] = MAX;
        checked[i] = false;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> queue;
    distance[source] = 0;
    queue.push({distance[source], source});

    while(!queue.empty()){
        int vertice = queue.top().second;
        queue.pop();

        if (!checked[vertice]){
            checked[vertice] = true;

            for(auto const &next : a_list[vertice]){
                int weight = next.first;
                int edge = next.second;

                if (distance[edge] > distance[vertice] + weight){
                    distance[edge] = distance[vertice] + weight;
                    queue.push({distance[edge], edge});
                }
            }
        }
    }
    return distance[destiny];
}

void add_edge(vector<vector<pair<int,int>>> &a_list, int edge, int vertice, int weight){
    a_list[edge].push_back({weight, vertice});
    a_list[vertice].push_back({weight, edge});
}

void mount_graph(int &n, int &x, vector<vector<pair<int,int>>> &a_list, vector<int> &distance, vector<bool> &checked){
    cin >> n >> x;

    a_list.resize(n);
    checked.resize(n);
    distance.resize(n);

    for (int i = 0; i < x; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(a_list, u, v, w);
    }
}

void dijkstra(){
    int n, x;

    vector<vector<pair<int,int>>> a_list;
    vector<int> distance;
    vector<bool> checked;

    mount_graph(n, x, a_list, distance, checked);

    int source, destiny;

    cin >> source >> destiny;

    int result = shortest_path(n, a_list, distance, checked, source, destiny);

    if (result != MAX){
        cout << "Shortest path between " << source << " and " << destiny << " = " << result << endl;
    }
    else{
        cout << "Theres no path between " << source << " and " << destiny << endl;
    }
}

int main(){
    dijkstra();
}