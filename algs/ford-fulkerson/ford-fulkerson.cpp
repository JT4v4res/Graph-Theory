#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>
#include <cstring>
#include <queue>
#include <list>

using namespace std;
#define Vertices 6 // número de vértices

// FUNÇÕES

bool bfs(int rGraph[][Vertices], int origem, int destino, int pai[]){
    bool visitado[Vertices];
    memset(visitado, 0, sizeof(visitado));

    queue<int> fila;
    fila.push(origem);
    visitado[origem] = true;
    pai[origem] = -1;

    while (!fila.empty()){
        int u = fila.front();
        fila.pop();

        for (int v = 0; v < Vertices; v++) {
            if (visitado[v] == false && rGraph[u][v] > 0){
                if (v == destino){
                    pai[v] = u;
                    return true;
                }
                fila.push(v);
                pai[v] = u;
                visitado[v] = true;
            }
        }
    }

    return false;
}


int fordFulkerson(int graph[Vertices][Vertices], int origem, int destino)
{
    int u, v, rGraph[Vertices][Vertices];

    for (u = 0; u < Vertices; u++)
        for (v = 0; v < Vertices; v++)
            rGraph[u][v] = graph[u][v];

    int pai[Vertices];
    int flowMaximo = 0;

    while (bfs(rGraph, origem, destino, pai)){
        int caminhoFluxo = INT_MAX;
        for (v = destino; v != origem; v = pai[v]){
            u = pai[v];
            caminhoFluxo = min(caminhoFluxo, rGraph[u][v]);
        }

        for (v = destino; v != origem; v = pai[v]){
            u = pai[v];
            rGraph[u][v] -= caminhoFluxo;
            rGraph[v][u] += caminhoFluxo;
        }
        flowMaximo += caminhoFluxo;
    }
    return flowMaximo;
}

// MAIN
int main(int argc, char **argv){
    string linha, sub;
    stringstream aux;
    list<int> vertices;
    int V, E, G[Vertices][Vertices];
    int i = 0, origem = 0, destino = 0, peso = 0;

    for (int i = 0; i < Vertices; i++)
        for (int j = 0; j < Vertices; j++)
            G[i][j] = 0;

    fstream file;
    file.open(argv[1], ios::in);
    if(file.is_open()){
        getline(file, linha);
        for(int indiceLinha = 0; indiceLinha < linha.length(); indiceLinha++){
            if (linha[indiceLinha] != ' ')
                sub += linha[indiceLinha];
            else{
                aux << sub;
                aux >> V;
                sub.clear();
                aux.clear();
            }
        }
        aux << sub;
        aux >> E;
        sub.clear();

        while(getline(file, linha)){
            i = 0;
            sub.clear();
            for(int indiceLinha = 0; indiceLinha < linha.length(); indiceLinha++){
                if (linha[indiceLinha] != ' ')
                    sub += linha[indiceLinha];
                else{
                    if(i == 0){
                        aux << sub;
                        aux >> origem;
                        sub.clear();
                        aux.clear();
                    }else{
                        aux << sub;
                        aux >> destino;
                        sub.clear();
                        aux.clear();
                    }
                    i++;
                }
            }
            aux << sub;
            aux >> peso;
            sub.clear();
            aux.clear();

            bool verticeExiste = false;
            for(auto item : vertices){
                if (item == origem)
                    verticeExiste = true;
            }
            if(!verticeExiste)
                vertices.push_back(origem);

            verticeExiste = false;
            for(auto item : vertices){
                if (item == destino)
                    verticeExiste = true;
            }
            if(!verticeExiste)
                vertices.push_back(destino);

            G[origem][destino] = peso;

        }
        file.close();
    }

    int verticeOrigem, verticeDestino;
    cout << "Available Vertices:" << endl;

    for(int item : vertices)
        cout << item << " ";

    cout << endl << "Enter the source vertice: ";
    cin >> verticeOrigem;
    cout << "Enter the destiny vertice: ";
    cin >> verticeDestino;
    cout << endl << "The maximum possible flow is " << fordFulkerson(G, verticeOrigem, verticeDestino) << endl;

    return 0;
}