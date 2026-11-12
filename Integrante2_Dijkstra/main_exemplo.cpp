#include "Dijkstra.hpp"
#include <iostream>

int main() {
    Grafo grafo;

    // Exemplo didático. Os valores são fictícios e devem ser substituídos
    // pelos dados pesquisados pelo grupo e/ou carregados dos CSVs.
    int brasil = grafo.adicionarVertice("Brasil");
    int irlanda = grafo.adicionarVertice("Irlanda");
    int noruega = grafo.adicionarVertice("Noruega");
    int suica = grafo.adicionarVertice("Suica");
    int tchequia = grafo.adicionarVertice("Republica Tcheca");
    int italia = grafo.adicionarVertice("Italia");
    int grecia = grafo.adicionarVertice("Grecia");

    // custo (R$), distância (km), tempo (h)
    grafo.adicionarAresta(brasil, irlanda, 4200, 9500, 14);
    grafo.adicionarAresta(brasil, italia, 3900, 9200, 13);
    grafo.adicionarAresta(irlanda, noruega, 650, 1300, 2.5);
    grafo.adicionarAresta(irlanda, suica, 700, 1400, 2.5);
    grafo.adicionarAresta(irlanda, italia, 500, 1800, 3);
    grafo.adicionarAresta(noruega, suica, 550, 1450, 2.5);
    grafo.adicionarAresta(noruega, tchequia, 600, 1700, 3);
    grafo.adicionarAresta(suica, tchequia, 180, 650, 1);
    grafo.adicionarAresta(suica, grecia, 450, 1500, 2.5);
    grafo.adicionarAresta(tchequia, italia, 220, 800, 1.5);
    grafo.adicionarAresta(tchequia, grecia, 400, 1500, 2);
    grafo.adicionarAresta(italia, grecia, 160, 850, 1.5);

    // Exemplo de consulta: Brasil até Grécia.
    executarTresCriterios(grafo, brasil, grecia);

    return 0;
}
