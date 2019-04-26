#
# Created by gky on 19-4-26.
# Author:liuqingtong.dev@gmail.com
#

import numpy as np

import redis
import time
import base64


def ArrayToB64(Array):
    b64 = base64.b64encode(Array)
    return b64


def B64ToArray(b64):
    r = base64.b64decode(b64)
    return r


def ArrayListReturn():

    ArrList = [[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]], [[13, 14, 15], [16, 17, 18]]]

    Array_A  = np.asarray(ArrList, dtype='float')
    Array_B  = np.asarray(ArrList, dtype='double')

    return [Array_A, Array_B]


def PassListFromCToPython(List):

    PyList = List
    print (PyList)


def PassArrayFromCToPython(Array):

    r = redis.Redis(host='localhost', port=6379, decode_responses=True)

    b64 = ArrayToB64(Array)

    r.set('name', b64)

    print "Shape Of Array:", Array.shape

    print Array