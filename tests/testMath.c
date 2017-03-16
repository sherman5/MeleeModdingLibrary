#include <unit_test.h>
#include <system.h>
#include <math.h>
#include <string.h>

#define RA_SIZE(x) (sizeof(x) / sizeof(x[0]))

UNIT_TEST;

static bool init_run = false;
static bool tests_run = false;
static char heap[13000];

static float angles[16] = 
{
    0.f,
    30.f,
    45.f,
    60.f,
    90.f,
    120.f,
    135.f,
    150.f,
    180.f,
    210.f,
    225.f,
    240.f,
    270.f,
    300.f,
    315.f,
    330.f
};

/* unit circle (doubled) */
static Point pts[16] = 
{
    {2.f,     0.f},
    {1.732f,  1.f},
    {1.414f,  1.414f},
    {1.f,     1.732f},
    {0.f,     2.f},
    {-1.f,    1.732f},
    {-1.414f, 1.414f},
    {-1.732f, 1.f},
    {-2.f,    0.f},
    {-1.732f, -1.f},
    {-1.414f, -1.414f},
    {-1.f,    -1.732f},
    {0.f,     -2.f},
    {1.f,     -1.732f},
    {1.414f,  -1.414f},
    {1.732f,  -1.f},
};

static int tan_indices[14] = {0, 1, 2, 3, 5, 6, 7, 8, 9,
    10, 11, 13, 14, 15};
static int asin_indices[8] = {1, 2, 3, 4, 12, 13, 14, 15};
static int acos_indices[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
static int atan_indices[4] = {0, 1, 2, 3};

static void init(void)
{
    initHeap(heap, heap + sizeof(heap));
}

static void test_basic(void)
{
    /** TEST SIGN **/
    REQUIRE(SIGN(-1.5f) == -1);
    REQUIRE(SIGN(2.4f)  ==  1);
    REQUIRE(SIGN(-55)   == -1);
    REQUIRE(SIGN(32)    ==  1);

    /** TEST FABS **/
    REQUIRE(fabs(-5.5f) == 5.5f);
    REQUIRE(fabs(17.2f) == 17.2f);
    REQUIRE(fabs(0.f)   == 0.f);

    /** TEST FLOOR **/
    REQUIRE(floor(-5.5f) == -6.0f);
    REQUIRE(floor(8.95f) == 8.f);
    REQUIRE(floor(-0.7f) == -1.f);
    REQUIRE(floor(0.02f) == 0.f);
    
    /** TEST CEIL **/
    REQUIRE(ceil(-5.5f) == -5.f);
    REQUIRE(ceil(8.95f) == 9.f);
    REQUIRE(ceil(-0.7f) == 0.f);
    REQUIRE(ceil(0.02f) == 1.f);

    /** TEST IMAX **/
    REQUIRE(imax(2, 2)   ==  2);
    REQUIRE(imax(0, 4)   ==  4);
    REQUIRE(imax(-3, 0)  ==  0);
    REQUIRE(imax(-1, 1)  ==  1);
    REQUIRE(imax(-4, -1) == -1);
    REQUIRE(imax(7, 23)  ==  23);

    /** TEST IMIN **/
    REQUIRE(imin(2, 2)   ==  2);
    REQUIRE(imin(0, 4)   ==  0);
    REQUIRE(imin(-3, 0)  == -3);
    REQUIRE(imin(-1, 1)  == -1);
    REQUIRE(imin(-4, -1) == -4);
    REQUIRE(imin(7, 23)  ==  7);

    /** TEST FMAX **/
    REQUIRE(fmax(2.3f, 2.3f)   == 2.3f);
    REQUIRE(fmax(0.f, 4.1f)    == 4.1f);
    REQUIRE(fmax(7.4f, 23.4f)  == 23.4f);
    REQUIRE(fmax(-3.6f, 0.f)   == 0.f);
    REQUIRE(fmax(-1.4f, 1.4f)  == 1.4f);
    REQUIRE(fmax(-4.6f, -1.7f) == -1.7f);
    
    /** TEST FMIN **/
    REQUIRE(fmin(2.3f, 2.3f)   == 2.3f);
    REQUIRE(fmin(-4.6f, -1.7f) == -4.6f);
    REQUIRE(fmin(0.f, 4.1f)    == 0.f);
    REQUIRE(fmin(-3.6f, 0.f)   == -3.6f);
    REQUIRE(fmin(-1.4f, 1.4f)  == -1.4f);
    REQUIRE(fmin(7.4f, 23.4f)  == 7.4f);

    /** TEST IMOD **/
    REQUIRE(imod(7, 3)  == 1);
    REQUIRE(imod(5, 13) == 5);
    REQUIRE(imod(-7, 3) == 2);

    /** TEST FMOD **/
    REQUIRE(fmod(380.f, 360.f)  == 20.f);
    REQUIRE(fmod(200.f, 360.f)  == 200.f);
    REQUIRE(fmod(-45.f, 360.f)  == 315.f);
}

static void test_power(void)
{
    /** TEST SQRT (and recipSqrt) **/
    REQUIRE_FLT_EQ(sqrt(2.f),     1.414f,    0.001f);
    REQUIRE_FLT_EQ(sqrt(0.f),     0.f,       0.001f);
    REQUIRE_FLT_EQ(sqrt(0.005f),  0.0707f,   0.001f);
    REQUIRE_FLT_EQ(sqrt(88.f),    9.3808f,   0.001f);
    REQUIRE_FLT_EQ(sqrt(54610.f), 233.6878f, 0.001f);

    /** TEST IPOW **/
    REQUIRE(ipow(0, 5)   ==  0);
    REQUIRE(ipow(1, 14)  ==  1);
    REQUIRE(ipow(2, 2)   ==  4);
    REQUIRE(ipow(3, 3)   ==  27);
    REQUIRE(ipow(25, 2)  ==  625);
    REQUIRE(ipow(-1, 3)  == -1);
    REQUIRE(ipow(-2, 2)  ==  4);

    /** TEST FPOW **/
    REQUIRE_FLT_EQ(fpow(0.f, 2),     0.f,        0.001f);
    REQUIRE_FLT_EQ(fpow(0.5f, 2),    0.25f,      0.001f);
    REQUIRE_FLT_EQ(fpow(-1.3f, 2),   1.69f,      0.001f);
    REQUIRE_FLT_EQ(fpow(-3.4f, 3),  -39.304f,    0.001f);
    REQUIRE_FLT_EQ(fpow(7.2f, 4),    2687.3856f, 0.001f);
    REQUIRE_FLT_EQ(fpow(1.2f, 2.3f), 1.44f,      0.001f);

    /** TEST EXP **/
    REQUIRE_FLT_EQ(exp(1.f),    2.718f,     0.001f);
    REQUIRE_FLT_EQ(exp(0.f),    1.f,        0.001f);
    REQUIRE_FLT_EQ(exp(-5.f),   0.007f,     0.001f);
    REQUIRE_FLT_EQ(exp(9.f),    8103.084f,  0.001f);
    REQUIRE_FLT_EQ(exp(0.5f),   1.649f,     0.001f);

    /** TEST LOG **/
    REQUIRE_FLT_EQ(log(exp(1.f)),  1.f,     0.001f);
    REQUIRE_FLT_EQ(log(0.5f),     -0.693f,  0.001f);
    REQUIRE_FLT_EQ(log(2.3f),      0.833f,  0.001f);
    REQUIRE_FLT_EQ(log(80.5f),     4.388f,  0.001f);
    REQUIRE_FLT_EQ(log(272.f),     5.606f,  0.001f);
}

static void test_trig(void)
{
    /** TEST SIN **/
    float sinERR = 0.f;
    for (unsigned i = 0; i < RA_SIZE(angles); ++i)
    {
        sinERR = fmax(sinERR, fabs(sin(angles[i]) - pts[i].y / 2.f));
    }
    REQUIRE(sinERR < 0.01f);

    /** TEST COSINE **/
    float cosERR = 0.f;
    for (unsigned i = 0; i < RA_SIZE(angles); ++i)
    {
        cosERR = fmax(cosERR, fabs(cos(angles[i]) - pts[i].x / 2.f));
    }
    REQUIRE(cosERR < 0.01f);

    /** TEST TANGENT **/
    float tanERR = 0.f;
    for (unsigned i = 0; i < RA_SIZE(tan_indices); ++i)
    {
        int j = tan_indices[i];
        float val = pts[j].y / pts[j].x;
        tanERR = fmax(tanERR, fabs(tan(angles[j]) - val));
    }
    REQUIRE(tanERR < 0.01f);

    /** TEST ASIN **/
    float asinERR = 0.f;
    for (unsigned i = 0; i < RA_SIZE(asin_indices); ++i)
    {
        int j = asin_indices[i];
        asinERR = fmax(asinERR, fabs(asin(pts[j].y / 2.f) - angles[j]));
    }
    REQUIRE(asinERR < 0.01f);

    /** TEST ACOS **/
    float acosERR = 0.f;
    for (unsigned i = 0; i < RA_SIZE(acos_indices); ++i)
    {
        int j = acos_indices[i];
        acosERR = fmax(acosERR, fabs(acos(pts[j].x / 2.f) - angles[j]));
    }
    REQUIRE(acosERR < 0.01f);

    /** TEST ATAN **/
    float atanERR = 0.f;
    for (unsigned i = 0; i < RA_SIZE(atan_indices); ++i)
    {
        int j = atan_indices[i];
        float val = pts[j].y / pts[j].x;
        atanERR = fmax(atanERR, fabs(atan(val) - angles[j]));
    }
    REQUIRE(atanERR < 0.01f);

    /** TEST ATAN2 **/
    float atan2ERR = 0.f;
    for (unsigned i = 1; i < RA_SIZE(angles); ++i)
    {
        atan2ERR = fmax(atan2ERR,
            fabs(atan2(pts[i].y, pts[i].x) - angles[i]));
    }
    REQUIRE(atan2ERR < 0.01f);
}

static void test_points(void)
{
    /** TEST POINTS **/
    Point origin = {0.0, 0.0};
    Point a = {3.0, 4.0};
    Point b = {-2.0, 2.0};

    /** TEST MAGNITUDE **/
    REQUIRE_FLT_EQ(magnitude(a), 5.0, 0.001);
    REQUIRE_FLT_EQ(magnitude(b), sqrt(8), 0.001);

    /** TEST DISTANCE **/
    REQUIRE_FLT_EQ(distance(a, b), sqrt(29), 0.001);
    REQUIRE_FLT_EQ(distance(origin, b), magnitude(b), 0.001);

    /** TEST ANGLE **/
    REQUIRE_FLT_EQ(angle(a, b), 201.80, 0.01);
    REQUIRE_FLT_EQ(angle(b, a), 21.80, 0.01);
}

void _main(void)
{
    if (!init_run) { init(); init_run = true;}

    if (!tests_run)
    {
        test_basic();
        test_power();
        test_trig();
        test_points();
        tests_run = true;
        END_TEST;
    }
}


