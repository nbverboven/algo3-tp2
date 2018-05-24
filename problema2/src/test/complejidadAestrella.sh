#!/usr/bin/env bash

OUTPUT_DIR=tiemposAestrella
OUTPUT_FILE="$OUTPUT_DIR/tiemposN.csv"
# estos parametros se pueden variar para mostrar distintos rangos de n
MIN_N=10
MAX_N=30
TRIES_COUNT=5

mkdir -p $OUTPUT_DIR

# crea las columnas del csv
echo "vertices,tiempo" > $OUTPUT_FILE

# para grafos con vertices de 10 a MAX_N
for n in $(seq $MIN_N 1 $MAX_N); do
    # corre TRIES_COUNT por cada valor de n
    for intento in $(seq 1 $TRIES_COUNT);do
        aEstrellaTime=$(./generarGrafoConexoDenso.py $n | ../main aEstrella)
        echo "$n,$aEstrellaTime" >> $OUTPUT_FILE
    done
done