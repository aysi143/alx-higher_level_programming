#!/usr/bin/python3
def add_tuple(tuple_a=(), tuple_b=()):
    a, b = len(tuple_a), len(tuple_b)
    new_tuple = ((tuple_a[0] if a >= 1 else 0) + (tuple_b[0] if b >= 1 else 0),
                 (tuple_a[1] if a >= 2 else 0) + (tuple_b[1] if b >= 2 else 0))
    return new_tuple
