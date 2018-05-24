#!/usr/bin/python
from __future__ import division
from numpy import linspace
import random
import sys


def main(n):
    values = [int(v) for v in linspace(n-1, n*(n-1)/2., 10)]
    for v in values:
        print v

# (n-1)(n-2)/2, n(n-1)/2

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print 'uso: {} n'.format(sys.argv[0])
    n = int(sys.argv[1])
    main(n)
