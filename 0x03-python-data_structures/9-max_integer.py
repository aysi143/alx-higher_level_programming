#!/usr/bin/python3
def max_integer(my_list=[]):
    if my_list:
        max = my_list[0]
        for elm in my_list:
            if elm > max:
                max = elm
        return max
    return None
