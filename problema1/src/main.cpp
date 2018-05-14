#include <iostream>
#include <memory>
#include "Parser.h"
#include "AgmMethodFactory.h"

int main(int argc, char const *argv[]) {

    if (argc != 2) {
        std::cout << "uso: " << argv[0] << " prim|kruskal|kruskal|kruskalCompression" << std::endl;
        return 1;
    }

    // parsea los parametros del problema
    Parser p;
    p.parseArguments();

    // calcula el arbol generador minimo con prim
    int n = p.getN();
    int m = p.getM();
    std::vector<Edge>& edges = p.getEdges();

    std::unique_ptr<AgmMethod> method(AgmMethodFactory::createAgmMethod(argv[1], n, m, edges));
    Agm agm = method->getAGM();
    double originalWeight = agm.getWeight();

    // para cada arista, verifico si esta en todos,
    // alguno o ninguno de los posibles AGMs
    for (Edge& e: edges) {
        int originalCost = e.getCost();
        // si aumentarle 1 el costo a la arista
        // aumenta 1 el peso del arbol, la
        // arista e esta en todos los AGMs
        e.setCost(originalCost+1);
        Agm biggerAgm = method->getAGM();
        double biggerWeight = biggerAgm.getWeight();
        if ((originalWeight+1) == biggerWeight) {
            std::cout << "toda" << std::endl;
        } else {
            // si restarle 1 al costo de la arista le saca
            // 1 al costo del arbol, la arista e esta en
            // alguno de los AGMs
            e.setCost(originalCost-1);
            Agm smallerAgm = method->getAGM();
            double smallerWeight = smallerAgm.getWeight();
            if ((originalWeight-1) == smallerWeight) {
                std::cout << "alguna" << std::endl;
            } else {
                // si ninguna se cumplio, e no esta en ningun AGM
                std::cout << "ninguna" << std::endl;
            }
        }
        // restauro el costo al original
        e.setCost(originalCost);
    }
    return 0;
}
