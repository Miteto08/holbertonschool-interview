#!/usr/bin/python3

"""
Minimum Operations
"""


def countProcess(num):
    """ Return list of process until n H """
    con = 1
    p_list = []
    val = num
    while val != 1:
        con += 1
        if val % con == 0:
            while (val % con == 0 and val != 1):
                val /= con
                p_list.append(con)

    return p_list


def minOperations(n):
    """ Return sum of process until n H """
    if n < 2 or type(n) is not int:
        return 0
    values = countProcess(n)
    return sum(values)
