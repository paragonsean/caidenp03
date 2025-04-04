/*
 * directSolvers.h
 *
 *  Created on: Feb 6, 2015
 *      Author: erik
 */

#ifndef MATRIXSOLVERS_H_
#define MATRIXSOLVERS_H_

#include "Matrix.h"

/*
 *
 */

typedef Matrix matrix;


class matrixSolvers
{
public:

	static int findPivot(const matrix&, int);
	static void backsolve(matrix&, matrix&);
	static void LUbacksolve(matrix&, matrix&, const matrix&);
	static void forwardSolve(matrix&, matrix&, const matrix&);
	static void gaussianElimination(matrix&, matrix&, const matrix&);
	static void LUdecomposition(matrix&, matrix&, const matrix&);
	static void decomp(matrix&);
};

#endif /* DIRECTSOLVERS_H_ */
