#!/usr/bin/python3
from sys import argv


def principal():
    print('{} argument'.format(len(argv) - 1), end='')
    if len(argv) == 1:
        print('s.')
    elif len(argv) == 2:
        print(':')
    else:
        print('s:')
    for i in range(1, len(argv)):
        print('{}: {}'.format(i, argv[i]))


if __name__ == "__main__":
    principal()
