#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <string>
#include <stdexcept>
#include <vector>

// Interface de exemplo esperada pelo Dijkstra.
// Se o Integrante 1 já tiver um Grafo.hpp, adapte os nomes dos campos
// deste arquivo ao grafo do grupo (ou substitua este arquivo).
struct Aresta {
    int destino;          // índice do vértice de destino
    double custo;         // custo em reais (R$)
    double distancia;     // distância em quilômetros (km)
    double tempo;         // tempo em horas (h)
};

class Grafo {
public:
    std::vector<std::string> vertices;
    std::vector<std::vector<Aresta>> adj;

    int adicionarVertice(const std::string& nome) {
        vertices.push_back(nome);
        adj.emplace_back();
        return static_cast<int>(vertices.size()) - 1;
    }

    void adicionarAresta(int origem, int destino,
                         double custo, double distancia, double tempo,
                         bool bidirecional = true) {
        if (origem < 0 || destino < 0 ||
            origem >= static_cast<int>(vertices.size()) ||
            destino >= static_cast<int>(vertices.size())) {
            throw std::out_of_range("Indice de vertice invalido.");
        }

        adj[origem].push_back({destino, custo, distancia, tempo});

        if (bidirecional) {
            adj[destino].push_back({origem, custo, distancia, tempo});
        }
    }

    int quantidadeVertices() const {
        return static_cast<int>(vertices.size());
    }
};

#endif
