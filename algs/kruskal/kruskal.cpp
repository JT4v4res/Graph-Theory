#include <bits/stdc++.h>

using namespace std;

struct k_ed{
    int edge;
    int vertice;
    int weight;
};

int ffind(vector<int> &p, int vertice){
    if (p[vertice] == vertice){
        return vertice;
    }
    else{
        return ffind(p, p[vertice]);
    }
}

bool uunion(vector<int> &p, int a, int b){
    int pa = ffind(p, a);
    int pb = ffind(p, b);

    if (pa == pb){
        return false;
    }
    p[pa] = pb;
    return true;
}

bool weight_comp(k_ed j, k_ed i){
    if (j.weight < i.weight){
        return true;
    }
    else{
        return false;
    }
}

vector<k_ed> minimal_spanning_tree(vector<k_ed> &e, vector<int> &p, int &s){
    sort(e.begin(), e.end(), weight_comp);

    vector<k_ed> found;

    for (auto const &i: e){
        int v = i.vertice;
        int e = i.edge;
        int w = i.weight;

        if (ffind(p, v) != ffind(p, e)){
            uunion(p, e, v);
            s += w;
            found.push_back({e, v, w});
        }
    }
    return found;
}

void kruskal_init(int n, vector<int> &p){
    p.resize(n);

    for (int i = 0; i < n; i++){
        p[i] = i;
    }
}

void add(vector<k_ed> &e, int edge, int vertice, int weight){
    e.push_back({edge, vertice, weight});
}

void mount_graph(int &n, int &x, vector<k_ed> &e){
    cin >> n >> x;
    e.resize(n);
    int i;

    for (i = 0; i < x; i++){
        int edge, vertice, weight;
        cin >> edge >> vertice >> weight;
        add(e, edge, vertice, weight);
    }
}

void kruskal(){
    int n, x, s = 0;

    vector<k_ed> e;
    vector<int> p;

    mount_graph(n, x, e);
    kruskal_init(n, p);

    vector<k_ed> found;
    found = minimal_spanning_tree(e, p, s);

    cout << "These are the edges of Minimal Spanning Tree" << endl;

    n = found.size();
    int c = 0;
    while(c <= n - 1){
        cout << found[c].edge << ", " << found[c].vertice << ", weight: " << found[c].weight << endl;

        c++;
    }
    cout << "Total weight: " << s << endl;
}

int main(){
    kruskal();
}