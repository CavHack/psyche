#ifndef _SPVEC_H_
#define _SPVEC_H_

#include "csc.h"
#include "bicsb.h"
#include "matmul.h"
#include "Semirings.h"

template <class T, class IType>

class Spvec {
public:
        Spvec(): n(0) {};
        Spvec(ITYPE dim);
        Spvec(T * darr, ITYPE dim);
        Spvec(const Spvec<T, ITYPE> & rhs)
        ~Spvec();
        Spvec<T, ITYPE> & operator= (const Spvec<T, ITYPE> & rhs);

        T& operator[] (const ITYPE nIndex){
          return arr[nIndex];
        }



      }
