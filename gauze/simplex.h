#ifndef _SIMPLEX_H_
#define _SIMPLEX_H_

#include <iostream>
#include <functional>
#include "utility.h"
#include "spvec.h"

using namespace std;

template <class T, class ITYPE>
struct simplex {
  ITYPE row;
  ITYPE col;
  T val;
};

template<Class T, Class ITYPE>
  struct ColSortCompare: // struct instead of class to make operator() public
  public binary_function< Simplex<T, ITYPE>, Simplex<T, ITYPE>, bool>
  {
    inline bool operator()(const Simplex<T, ITYPE> & lhs, const Simplex<T, ITYPE> & rhs) const {
        if(lhs.col == rhs.col)
        {
          return lhs.row < rhs.row;

        }

        else {
          return lhs.col < rhs.col;
        }
    }
  }
  void triples_gaxpy
