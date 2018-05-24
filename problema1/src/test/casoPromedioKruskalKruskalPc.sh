#!/bin/bash

OUTPUT_DIR=promedioKruskalKruskalPc
OUTPUT_FILE="$OUTPUT_DIR/tiemposN.csv"
# estos parametros se pueden variar para mostrar distintos rangos de n
MIN_N=10
MAX_N=70

mkdir -p $OUTPUT_DIR

# crea las columnas del csv
echo "vertices,aristas,tiempoKruskal,tiempoKruskalPc" > $OUTPUT_FILE

# para grafos con vertices de MIN_N a MAX_N
for n in $(seq $MIN_N 1 $MAX_N); do
    # para grafos con aristas en el rango que dice el tp
    for m in $(./generarRango.py $n); do
        INPUT_GRAPH="$OUTPUT_DIR/$n$m.txt"
        ./generarGrafoConexo.py $n $m > $INPUT_GRAPH
        kruskalTime=$(../main kruskal < $INPUT_GRAPH)
        kruskalPcTime=$(../main kruskalCompression < $INPUT_GRAPH)
        echo "$n,$m,$kruskalTime,$kruskalPcTime" >> $OUTPUT_FILE
        # por si acaso alguien corre esto en milagro,
        # para no superar la cuota de disco
        rm -f $INPUT_GRAPH
    done
done
