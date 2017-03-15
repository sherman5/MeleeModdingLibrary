/**
 * @file matrix.h
 * @brief Support for matrix and vector operations
 */

#ifndef MML_MATRIX_H
#define MML_MATRIX_H

#include "gctypes.h"

/** @brief A vector of 32-bit floating-point values */
typedef struct
{
    float* data; /**< array of floating-point values */
    size_t size; /**< size of @c data */

} Vector;

/** @brief A matrix of 32-bit floating-point values */
typedef struct
{
    float** data; /**< two-dimensional array of floating-point values */
    size_t nRow; /**< number of rows in the matrix */
    size_t nCol; /**< number of columns in the matrix */

} Matrix;

/** Extract a row from @c mat as a @c Vector struct */
#define ROW_VECTOR(mat, ndx)   ((Vector) {mat.data[ndx], mat.nCol})

/**
 * @brief Initialize a Vector. 
 * @ingroup CallsMalloc
 *
 * @param vec - pointer to a Vector struct
 * @param size - number of values in the vector
 *
 * @return @c false if memory allocation fails, @c true otherwise
 */
bool initVector(Vector* vec, size_t size);

/**
 * @brief Initialize a matrix. 
 * @ingroup CallsMalloc
 *
 * @param mat - pointer to a Matrix struct
 * @param numRows - number of rows in the matrix 
 * @param numCols - number of columns in the matrix
 *
 * @return @c false if memory allocation fails, @c true otherwise
 */
bool initMatrix(Matrix* mat, size_t numRows, size_t numCols);

/**
 * @brief Populate the values in a vector
 *
 * This function populates each element in the vector
 * based on @c func. Element @c n will be equal to <tt> func(n) </tt>.
 *
 * @param vec - pointer to a Vector struct
 * @param func - pointer to a function of the form <tt> float foo(u32) </tt>
 *
 * @return None.
 */
void populateVec(Vector* vec, void* func);

/**
 * @brief Populate the values in a matrix
 *
 * This function populates each element in the matrix
 * based on @c func. The element at <tt> [row][col] </tt> will be equal
 * to <tt> func(row, col) </tt>.
 *
 * @param mat - pointer to a Matrix struct
 * @param func - pointer to a function of the form
 *  <tt> float foo(u32, u32) </tt>
 *
 * @return None.
 */
void populateMat(Matrix* mat, void* func);

void matrixVectorProduct(Vector* y, const Matrix* A, const Vector* x);
float vectorDotProd(const Vector* u, const Vector* v);

#endif
