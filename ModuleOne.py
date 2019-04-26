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

    ArrList = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

    Array_A  = np.asarray(ArrList, dtype='float' )
    Array_B  = np.asarray(ArrList, dtype='double')

    return [Array_A, Array_B]

def IntegerListReturn():

    IntegerList = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

    return IntegerList

def FloatListReturn():

    FloatList = [[1.2, 2.3, 3.5], [0.5, 5.2, 6.5], [7.2, 8.8, 9.3]]

    return FloatList

def PassListFromCToPython(List):

    PyList = List
    print (PyList)

def PassArrayFromCToPython(Array):

    r = redis.Redis(host='localhost', port=6379, decode_responses=True)

    b64 = ArrayToB64(Array)

    r.set('name', b64)

    print "Shape Of Array:", Array.shape

    print Array