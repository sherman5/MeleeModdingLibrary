#include "matrix.h"
#include "gctypes.h"
#include "system.h"
#include "error.h"

bool initMatrix(Matrix* mat, size_t numRows, size_t numCols)
{
    mat->data = calloc(numRows, sizeof(float*));
    if (!mat->data)
    {
        ERROR_MSG("failed alloc");
        return false;
    }
    else 
    {
        for (unsigned i = 0; i < numRows; ++i)
        {
            mat->data[i] = calloc(numCols, sizeof(float));
            if (!mat->data[i])
            {
                ERROR_MSG("failed alloc");
                return false;
            }
        }
    }

    mat->nRow = numRows;
    mat->nCol = numCols;
    return true;    
}

bool initVector(Vector* vec, size_t size)
{
    vec->data = calloc(size, sizeof(float));

    if (!vec->data)
    {
        ERROR_MSG("failed alloc");
        return false;
    }
    else
    {
        vec->size = size;
        return true;
    }
}

void populateVec(Vector* vec, void* func)
{
    float (*getValue)(u32 index) = func;

    for (unsigned i = 0; i < vec->size; ++i)
    {
        vec->data[i] = getValue(i);
    }
}

void populateMat(Matrix* mat, void* func)
{
    float (*getValue)(u32 row, u32 col) = func;

    for (unsigned i = 0; i < mat->nRow; ++i)
    {
        float* row = mat->data[i];
        for (unsigned j = 0; j < mat->nCol; ++j)
        {
            row[j] = getValue(i, j);
        }
    }
}

#pragma GCC push_options
#pragma GCC optimize ("-O3")
static float fastDotProduct(const float* u, const float* v, size_t size)
{
    float sum = 0.f;
    unsigned i = 0;

    for (; i <= size - 4; i += 4)
    {
        /* taken from libogc - gu_psasm.S */
        register f32 result;
    	__asm__ __volatile__ (
		    "psq_l		2,0(%1),0,0\n"
		    "psq_l		4,0(%2),0,0\n"
		    "ps_mul		%0,2,4\n"
		    "psq_l		3,8(%1),0,0\n"
		    "psq_l		5,8(%2),0,0\n"
		    "ps_madd	%0,3,5,%0\n"
		    "ps_sum0	%0,%0,%0,%0\n"
		    : "=&f"(result)
		    : "b"(&u[i]),"b"(&v[i])
		    : "memory"
	    );

        sum += result;
    }

    for (; i < size; ++i)
    {
        sum += u[i] * v[i];
    }

    return sum;
}
 
void matrixVectorProduct(Vector* y, const Matrix* A, const Vector* x)
{
    for (unsigned i = 0; i < A->nCol; ++i)
    {
        y->data[i] = fastDotProduct(A->data[i], x->data, x->size); 
    }
}

float vectorDotProd(const Vector* u, const Vector* v)
{
    return fastDotProduct(u->data, v->data, u->size);
}
#pragma GCC pop_options

