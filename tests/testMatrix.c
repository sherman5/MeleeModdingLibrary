#include <system.h>
#include <matrix.h>
#include <gctypes.h>
#include <unit_test.h>
#include <profile.h>
#include <print.h>

#define DIM 300
#define DOT_PROD(row)  (DIM * (DIM - 1) * (3 * (row) + 2 * DIM - 1) / 6)

UNIT_TEST;

static bool initRun = false;
static bool testRun = false;
static bool allocSuccess = true;

static Vector vec = {NULL, 0};
static Vector result = {NULL, 0};
static Matrix mat = {NULL, 0, 0};

void boot(void)
{
    limitGameMemory((void*) 0x81780000);
}

float popVecFunc(u32 index)
{
    return index;
}

float popMatFunc(u32 row, u32 col)
{
    return row + col;
}

static void init(void)
{
    initHeap((void*) 0x81780000, (void*) 0x817f8ab0);

    allocSuccess = initVector(&vec, DIM) && allocSuccess;
    allocSuccess = initVector(&result, DIM) && allocSuccess;
    allocSuccess = initMatrix(&mat, DIM, DIM) && allocSuccess;

    if (!allocSuccess) {return;}

    populateVec(&vec, &popVecFunc);
    populateMat(&mat, &popMatFunc);
}

static void testAccuracy(void)
{
    /* test initialization */
    REQUIRE(vec.size == DIM);
    REQUIRE(result.size == DIM);
    REQUIRE(mat.nRow == DIM);
    REQUIRE(mat.nCol == DIM);

    REQUIRE(mat.data[0][0] == 0.f);
    REQUIRE(mat.data[1][1] == 2.f);
    REQUIRE(mat.data[DIM - 1][DIM - 1] == (float) (DIM + DIM - 2));

    REQUIRE(vec.data[0] == 0.f);
    REQUIRE(vec.data[DIM - 1] == (float) DIM - 1.f);
    
    /* test sum prod */
    for (unsigned i = 0; i < DIM; ++i)
    {
        Vector v = ROW_VECTOR(mat, i);
        REQUIRE(vectorDotProd(&vec, &v) == DOT_PROD(i));
    }

    /* test matrix multiplication */
    matrixVectorProduct(&result, &mat, &vec);

    for (unsigned i = 0; i < DIM; ++i)
    {
        REQUIRE(result.data[i] == DOT_PROD(i));
    }
}

static Profile matrixVectorProfile = DEFAULT_PROFILE;
static void testSpeed()
{
    startTrial(&matrixVectorProfile);
    matrixVectorProduct(&result, &mat, &vec);
    endTrial(&matrixVectorProfile);

    clear();
    printProfile(&matrixVectorProfile);
}

/* RESULTS for 300x300 * 300x1

-O0, standard C - 121430
-O1, standard C - 41755
-O2, standard C - 41630
-O3, standard C - 41630
-O0, PS instructions - 52105
-O1, PS instructions - 26755
-O2, PS instructions - 26755
-O3, PS instructions - 26755
*/

void _main(void)
{
    if (!initRun) { init(); initRun = true;}

    if (allocSuccess && !testRun)
    {
        testAccuracy();
        testRun = true;
        END_TEST;
    }

    if (allocSuccess && _tests_passed)
    {
        testSpeed();
    }
}



