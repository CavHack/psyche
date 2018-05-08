#ifndef _CSC_H_
#define _CSC_H_

#include "simplex.h"

template <class T, class ITYPE>
struct simplex;

template <class T, class ITYPE>
  Csc<T, ITYPE> & operator=(const Csc<T, ITYPE> & rhs);// assignment operator
  Csc(Simplex<T, ITYPE> * simplex,  ITYPE size, ITYPE rows, ITYPE cols, bool isSym = false );
  Csc(ITYPE * ri, ITYPE * ci, T * val, ITYPE size, ITYPE rows, ITYPE cols, bool isSym =  false );

  ITYPE colsize() const { return n;}
	ITYPE rowsize() const { return m;}
	ITYPE * getjc() const { return jc;}
	ITYPE * getir() const { return ir;}
	T * getnum() const { return num;}
	ITYPE getlogicalnnz() const
	{
		return logicalnz;
	}
}

/* y = A*x+y */
template<typename T, typename ITYPE>
void csc_gaxpy (const Csc<T, ITYPE> & A, T * x, T * y){
  if(A.issym)
}
