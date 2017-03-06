#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include "seqLinearList.hpp"
using namespace std;

template<class Item>
void readFrom(string prefix, string suffix, LinearList<Item> &A) {
    string fileName = prefix + "_" + suffix + ".in";
    int size, temp = 0;
    size = (suffix[0] - '0') * pow(10, suffix.length() - 1);
    A.resize(size);
    ifstream fp;
    fp.open(fileName.c_str());
    fp >> temp;
    for (int i = 0; i < size; ++i)
    {
        fp >> temp;
        A.push_back(temp);
        //cout << A.returnListElement(i) << "\n";
    }
}

#endif