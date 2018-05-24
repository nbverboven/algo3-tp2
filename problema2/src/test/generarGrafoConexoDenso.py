#!/usr/bin/python
from __future__ import division
import random
import sys
import numpy as np

def main(n, m=None):
    # tenemos un teorema que asegura que m elegido asi hace que el grafo sea conexo
    if m is None:
        m = int((n-1)*(n-2)/2) + 1
    aristas = [(i, j, int(random.uniform(1, 60))) for i in xrange(n) for j in xrange(n) if i < j]
    grafo = random.sample(aristas, m)
    print '{} {}'.format(n, m)
    for costos in xrange(n):
        print '{}'.format(random.uniform(20,100))
    for arista in grafo:
        print '{} {} {}'.format(arista[0], arista[1], arista[2])


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print 'uso: {} cantidadVertices [cantidadAristas]'.format(sys.argv[0])
        sys.exit(1)
    n = int(sys.argv[1])
    m = None
    if len(sys.argv) == 3:
        m = int(sys.argv[2])
    main(n, m)
