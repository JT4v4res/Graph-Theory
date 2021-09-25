#include <bits/stdc++.h>
#define MAX 99999

using namespace std;

bool verticesVisitados[MAX];
int x, y, pesos[MAX];
int total = 0;
vector<pair<int, int>> grafo[MAX];

// FUNÇÕES
int primAlgorithm(){
    for (int i = 0; i < x; i++) {
        pesos[i] = MAX;
    }

    pesos[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaDePrioridade;
    filaDePrioridade.push({pesos[0], 0});

    while(true){
        int atual = -1;
        while (!filaDePrioridade.empty()){
            int prox = filaDePrioridade.top().second;
            filaDePrioridade.pop();
            if (!verticesVisitados[prox]){
                atual = prox;
                break;
            }
        }
        if(atual == -1){
            break;
        }

        verticesVisitados[atual] = true;
        for (int i = 0; i < grafo[atual].size(); i++){
            int ant = grafo[atual][i].first;
            int prox = grafo[atual][i].second;

            if (pesos[prox] > ant && !verticesVisitados[prox]){
                pesos[prox] = ant;
                filaDePrioridade.push({pesos[prox], prox});
            }
        }
    }

    for (int i = 0; i < y; i++)
        total += pesos[i];
    return total;
}

int Prim(){
    cin >> x >> y;
    int u, v, peso;
    for (int i = 0; i < x; ++i){
        cin >> u >> v >> peso;
        grafo[u].push_back({peso, v});
        grafo[v].push_back({peso, u});
    }

    cout << "O total é " << primAlgorithm() << "\n";
    return 0;
}

//MAIN
int main(int argc, char const *argv[]){
    Prim();
}