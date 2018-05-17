#include <getopt.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <chrono>

#include "Grafo.h"
#include "algoritmos/Dantzig.cpp"

using namespace std;

void printHelp(){
    cout <<
            "-a, --algoritmo <algoritmo>:  dijkstra|dijkstra-pq|a|bellmanFord|floydWarshall|dantzig\n"
            "-h, --help:                   Muestra ayuda\n";
    exit(1);
}

/**
 * Prosesa las opciones de entrada del ejecutable
 */
void processOptions(int argc, char* argv[]){

    const char* const short_opts = "e:f:h";
    const option long_opts[] = {
            {"algoritmo", 1, nullptr, 'a'},
            //{"file", 1, nullptr, 'f'},
            {"help", 0, nullptr, 'h'}
    };

    Grafo _grafo = Grafo::getInstanceFromInput();

    _grafo.print();

    string experimento;

    while (true) {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (-1 == opt){
            break;
        }

        switch (opt) {
            case 'e':
                    //experimento = std::string(optarg);
                    //runExperiment(experimento);
                    //exit(1);
                break;

            case 'f':
                    //input_file = std::string(optarg);
                    //std::cout << "Corriendo casos desde:" << input_file << std::endl;
                    //runAlgoritmsFromFile(input_file);
                    //exit(1);
                break;

            case 'h':
            default:
                printHelp();
                break;
        }
    }

}


int main(int argc, char* argv[]) {
    
    cout << "steady_clock" << endl;
    cout << chrono::steady_clock::period::num << endl;
    cout << chrono::steady_clock::period::den << endl; //1.000.000.000
    cout << "steady = " << boolalpha << chrono::steady_clock::is_steady << endl << endl;

    processOptions(argc, argv);

    return 1;
}

