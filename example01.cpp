//
// Created by gky on 19-4-26.
// Author:liuqingtong.dev@gmail.com
//

#include <iostream>
#include <Python.h>
#include <numpy/arrayobject.h>
using namespace std;

void init_numpy(){

    import_array();
}
int main()
{

    Py_Initialize();
    init_numpy();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/gky/Temp/GKY-SR-API_Debug_v1.0.0')");
//    PyRun_SimpleString("sys.path.append('./')");

    PyObject *pModule  = nullptr;
    PyObject *pDict    = nullptr;

    pModule  = PyImport_ImportModule("CorrespondingModule");
    pDict    = PyModule_GetDict(pModule);

    /*Return the List which contains Numpy Array*/
    PyObject *pFuncOne    = PyDict_GetItemString(pDict, "ArrayListReturn");

    PyObject *FuncOneBack = PyObject_CallObject(pFuncOne, nullptr);

    int Index_i = 0, Index_k = 0, Index_m = 0, Index_n = 0, Channel_m = 0;
    if(PyList_Check(FuncOneBack)){

        int SizeOfList = PyList_Size(FuncOneBack);

        for(Index_i = 0; Index_i < SizeOfList; Index_i++){

            PyArrayObject *ListItem = (PyArrayObject *)PyList_GetItem(FuncOneBack, Index_i);

            int Channels = ListItem->dimensions[0], Rows = ListItem->dimensions[1], columns = ListItem->dimensions[2];
            cout<<"The "<<Index_i<<"th Array is:"<<endl;
            for(Channel_m = 0; Channel_m < Channels; Channel_m++){

                cout<<"Channel "<<Channel_m<<":"<<endl;
                for(Index_m = 0; Index_m < Rows; Index_m++){

                    for(Index_n = 0; Index_n < columns; Index_n++){

                        cout<<*(double *)(ListItem->data + Index_m * ListItem->strides[1] + Index_n * ListItem->strides[2] + Channel_m * ListItem->strides[0])<<" ";
                    }
                    cout<<" Row "<<Index_m;
                    cout<<endl;
                }
            }

            Py_DECREF(ListItem);
        }
    }else{

        cout<<"Not a List"<<endl;
    }


    /*Pass by Python Array: Transform an C Array to Python Array*/

    double CArrays[3][2][3] = {{{1, 2, 3}, {4, 5, 6}}, {{7, 8, 9},{10, 11, 12}}, {{13, 14, 15}, {16, 17, 18}}};

    npy_intp Dims[3] = {3, 2, 3};

    PyObject *PyArray  = PyArray_SimpleNewFromData(3, Dims, NPY_DOUBLE, CArrays);
    PyObject *ArgArray = PyTuple_New(1);
    PyTuple_SetItem(ArgArray, 0, PyArray);

    PyObject *pFuncFive = PyDict_GetItemString(pDict, "PassArrayFromCToPython");
    PyObject_CallObject(pFuncFive, ArgArray);



    //Release

    Py_DECREF(pModule);
    Py_DECREF(pDict);
    Py_DECREF(FuncOneBack);
    Py_DECREF(PyArray);
    Py_DECREF(ArgArray);
    return 0;
}