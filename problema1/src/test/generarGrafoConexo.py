#!/usr/bin/python
from __future__ import division
from numpy import linspace
import random
import sys


def main(n, m):
    todasLasAristas = [(i, j) for i in xrange(n) for j in xrange(n) if i < j]
    vertices = [0]
    grafo = []
    for i in xrange(1, n):
        previous = random.choice(vertices)
        vertices.append(i)
        todasLasAristas.remove((previous, i))
        grafo.append((previous, i, int(random.uniform(1, 100))))
    elResto = random.sample(todasLasAristas, m-n+1)
    for arista in elResto:
        grafo.append((arista[0], arista[1], int(random.uniform(1, 100))))
    print '{} {}'.format(n, m)
    for arista in grafo:
        print '{} {} {}'.format(arista[0], arista[1], arista[2])


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print 'uso: {} cantidadVertices cantidadAristas'.format(sys.argv[0])
    n = int(sys.argv[1])
    m = int(sys.argv[2])
    main(n, m)
