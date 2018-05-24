#!/bin/bash

OUTPUT_DIR=primKruskalPcLineal
OUTPUT_FILE="$OUTPUT_DIR/tiemposN.csv"
# estos parametros se pueden variar para mostrar distintos rangos de n
MIN_N=10
MAX_N=70

mkdir -p $OUTPUT_DIR

# crea las columnas del csv
echo "vertices,aristas,tiempoPrim,tiempoKruskalPc" > $OUTPUT_FILE

# para grafos con vertices de MIN_N a MAX_N
for n in $(seq $MIN_N 1 $MAX_N); do
    m_max=$(expr $n + $n)
    # para grafos con aristas en el rango que dice el tp
    for m in $(seq $n $m_max); do
        INPUT_GRAPH="$OUTPUT_DIR/$n$m.txt"
        ./generarGrafoConexo.py $n $m > $INPUT_GRAPH
        primTime=$(../main prim < $INPUT_GRAPH)
        kruskalPcTime=$(../main kruskalCompression < $INPUT_GRAPH)
        echo "$n,$m,$primTime,$kruskalPcTime" >> $OUTPUT_FILE
        # por si acaso alguien corre esto en milagro,
        # para no superar la cuota de disco
        rm -f $INPUT_GRAPH
    done
done
