PARTE DO INTEGRANTE 2 - ALGORITMO DE DIJKSTRA
================================================

Arquivos:
- Dijkstra.hpp: declarações, enum de critérios e estrutura de resultado.
- Dijkstra.cpp: implementação do algoritmo e impressão das rotas.
- Grafo.hpp: interface de grafo de exemplo usada para compilar este pacote.
- main_exemplo.cpp: exemplo executável com valores FICTÍCIOS.

COMO COMPILAR (g++):
g++ -std=c++17 -Wall -Wextra -pedantic main_exemplo.cpp Dijkstra.cpp -o exemplo

No Windows com MinGW:
g++ -std=c++17 -Wall -Wextra -pedantic main_exemplo.cpp Dijkstra.cpp -o exemplo.exe

IMPORTANTE PARA INTEGRAR AO PROJETO DO GRUPO:
O Integrante 1 ainda precisa fornecer a estrutura real do Grafo e os dados CSV.
Este pacote usa a seguinte interface:
  grafo.vertices             -> vector<string> com nomes dos vértices
  grafo.adj                  -> lista de adjacência
  grafo.adj[u]               -> arestas que saem do vértice u
  Aresta.destino              -> índice do vértice vizinho
  Aresta.custo                -> peso monetário
  Aresta.distancia            -> peso em quilômetros
  Aresta.tempo                -> peso em horas
  grafo.quantidadeVertices()  -> quantidade de vértices

Se o Grafo.hpp do grupo tiver nomes ou tipos diferentes, Dijkstra.cpp precisará
ser ajustado para usar a interface real. Não substitua o arquivo do Integrante 1
sem combinar com ele.

COMO USAR:
  ResultadoDijkstra r = dijkstra(grafo, origem, destino, Criterio::CUSTO);
  executarTresCriterios(grafo, origem, destino);

Dijkstra encontra caminhos mínimos com pesos NÃO NEGATIVOS. O grafo pode ser
não direcionado (arestas nos dois sentidos) ou direcionado, conforme a modelagem.

Os valores no main_exemplo.cpp são apenas ilustrativos, não são pesquisa real
de passagens nem resultados definitivos do trabalho. O grupo deve trocar esses
valores pelos dados reais coletados e pelo ponto de partida/destino definidos.
