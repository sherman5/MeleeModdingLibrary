#include <unit_test.h>
#include <system.h>
#include <math.h>
#include <string.h>

UNIT_TEST;

static bool init = false;
static char heap[21000];

static int tests_run = 0;

void _init(void)
{
    initHeap(heap, heap + sizeof(heap));
}

void _main(void)
{
    if (!init) { _init(); init = true;}

    if (!tests_run)
    {
        /** TEST SIN **/
        REQUIRE_FLT_EQ(sin(DEG_TO_RAD(0.0)), 0.0, 0.001);
        REQUIRE_FLT_EQ(sin(DEG_TO_RAD(30.0)), 0.5, 0.001);
        REQUIRE_FLT_EQ(sin(DEG_TO_RAD(45.0)), 0.707, 0.001);
        REQUIRE_FLT_EQ(sin(DEG_TO_RAD(60.0)), 0.866, 0.001);
        REQUIRE_FLT_EQ(sin(DEG_TO_RAD(90.0)), 1.0, 0.001);
        REQUIRE_FLT_EQ(sin(DEG_TO_RAD(135.0)), 0.707, 0.001);
        REQUIRE_FLT_EQ(sin(DEG_TO_RAD(225.0)), -0.707, 0.001);
        REQUIRE_FLT_EQ(sin(DEG_TO_RAD(315.0)), -0.707, 0.001);
        REQUIRE_FLT_EQ(sin(DEG_TO_RAD(405.0)), 0.707, 0.001);
        REQUIRE_FLT_EQ(sin(DEG_TO_RAD(-45.0)), -0.707, 0.001);

        /** TEST COSINE **/
        REQUIRE_FLT_EQ(cos(DEG_TO_RAD(0.0)), 1.0, 0.001); 
        REQUIRE_FLT_EQ(cos(DEG_TO_RAD(30.0)), 0.866, 0.001);
        REQUIRE_FLT_EQ(cos(DEG_TO_RAD(45.0)), 0.707, 0.001);
        REQUIRE_FLT_EQ(cos(DEG_TO_RAD(60.0)), 0.5, 0.001);
        REQUIRE_FLT_EQ(cos(DEG_TO_RAD(90.0)), 0.0, 0.001);
        REQUIRE_FLT_EQ(cos(DEG_TO_RAD(225.0)), -0.707, 0.001); 
        REQUIRE_FLT_EQ(cos(DEG_TO_RAD(-135.0)), -0.707, 0.001);  

        /** TEST TANGENT **/
        REQUIRE_FLT_EQ(tan(DEG_TO_RAD(0.0)), 0.0, 0.001); 
        REQUIRE_FLT_EQ(tan(DEG_TO_RAD(30.0)), 0.577, 0.001);
        REQUIRE_FLT_EQ(tan(DEG_TO_RAD(45.0)), 1.0, 0.001);
        REQUIRE_FLT_EQ(tan(DEG_TO_RAD(60.0)), 1.732, 0.001);
        REQUIRE_FLT_EQ(tan(DEG_TO_RAD(225.0)), 1.0, 0.001);
        REQUIRE_FLT_EQ(tan(DEG_TO_RAD(-405.0)), -1.0, 0.001);

        /** TEST FABS **/
        REQUIRE_FLT_EQ(fabs(-5.5), 5.5, 0.0001);
        REQUIRE_FLT_EQ(fabs(17.2), 17.2, 0.0001);
        REQUIRE_FLT_EQ(fabs(0.0), 0.0, 0.0001);

        /** TEST FLOOR **/
        REQUIRE_FLT_EQ(floor(-5.5), -6.0, 0.0001);
        REQUIRE_FLT_EQ(floor(8.95), 8.0, 0.0001);
        REQUIRE_FLT_EQ(floor(-0.7), -1.0, 0.0001);
        REQUIRE_FLT_EQ(floor(0.02), 0.0, 0.0001);
        
        /** TEST CEIL **/
        REQUIRE_FLT_EQ(ceil(-5.5), -5.0, 0.0001);
        REQUIRE_FLT_EQ(ceil(8.95), 9.0, 0.0001);
        REQUIRE_FLT_EQ(ceil(-0.7), 0.0, 0.0001);
        REQUIRE_FLT_EQ(ceil(0.02), 1.0, 0.0001);

        /** TEST IMAX **/
        REQUIRE(imax(2, 2) == 2);
        REQUIRE(imax(0, 4) == 4);
        REQUIRE(imax(-3, 0) == 0);
        REQUIRE(imax(-1, 1) == 1);
        REQUIRE(imax(-4, -1) == -1);
        REQUIRE(imax(7, 23) == 23);

        /** TEST IMIN **/
        REQUIRE(imin(2, 2) == 2);
        REQUIRE(imin(0, 4) == 0);
        REQUIRE(imin(-3, 0) == -3);
        REQUIRE(imin(-1, 1) == -1);
        REQUIRE(imin(-4, -1) == -4);
        REQUIRE(imin(7, 23) == 7);

        /** TEST FMAX **/
        REQUIRE_FLT_EQ(fmax(2.3, 2.3), 2.3, 0.001);
        REQUIRE_FLT_EQ(fmax(0.0, 4.1), 4.1, 0.001);
        REQUIRE_FLT_EQ(fmax(-3.6, 0.0), 0.0, 0.001);
        REQUIRE_FLT_EQ(fmax(-1.4, 1.4), 1.4, 0.001);
        REQUIRE_FLT_EQ(fmax(-4.6, -1.7), -1.7, 0.001);
        REQUIRE_FLT_EQ(fmax(7.4, 23.4), 23.4, 0.001);

        /** TEST FMIN **/
        REQUIRE_FLT_EQ(fmin(2.3, 2.3), 2.3, 0.001);
        REQUIRE_FLT_EQ(fmin(0.0, 4.1), 0.0, 0.001);
        REQUIRE_FLT_EQ(fmin(-3.6, 0.0), -3.6, 0.001);
        REQUIRE_FLT_EQ(fmin(-1.4, 1.4), -1.4, 0.001);
        REQUIRE_FLT_EQ(fmin(-4.6, -1.7), -4.6, 0.001);
        REQUIRE_FLT_EQ(fmin(7.4, 23.4), 7.4, 0.001);

        /** TEST IPOW **/
        REQUIRE(ipow(0, 5) == 0);
        REQUIRE(ipow(1, 14) == 1);
        REQUIRE(ipow(2, 2) == 4);
        REQUIRE(ipow(3, 3) == 27);
        REQUIRE(ipow(25, 2) == 625);
        REQUIRE(ipow(-1, 3) == -1);
        REQUIRE(ipow(-2, 2) == 4);

        /** TEST FPOW **/
        REQUIRE_FLT_EQ(fpow(0.0, 2), 0.0, 0.001);
        REQUIRE_FLT_EQ(fpow(0.5, 2), 0.25, 0.001);
        REQUIRE_FLT_EQ(fpow(-1.3, 2), 1.69, 0.001);
        REQUIRE_FLT_EQ(fpow(-3.4, 3), -39.304, 0.001);
        REQUIRE_FLT_EQ(fpow(7.2, 4), 2687.3856, 0.001);
        REQUIRE_FLT_EQ(fpow(1.2, 2.3), 1.44, 0.001);

        /** TEST SQRT **/
        REQUIRE_FLT_EQ(sqrt(2.0), 1.414, 0.001);
        REQUIRE_FLT_EQ(sqrt(0.0), 0.0, 0.001);
        REQUIRE_FLT_EQ(sqrt(0.005), 0.0707, 0.001);
        REQUIRE_FLT_EQ(sqrt(88.0), 9.3808, 0.001);
        REQUIRE_FLT_EQ(sqrt(54610.0), 233.6878, 0.001);

        /** TEST ATAN2 **/
        REQUIRE_FLT_EQ(atan2(0, -2), DEG_TO_RAD(180.0), 0.01);
        REQUIRE_FLT_EQ(atan2(1, -sqrt(3)), DEG_TO_RAD(150.0), 0.01);
        REQUIRE_FLT_EQ(atan2(sqrt(2), -sqrt(2)), DEG_TO_RAD(135.0), 0.01);
        REQUIRE_FLT_EQ(atan2(sqrt(3), -1), DEG_TO_RAD(120.0), 0.01);
        REQUIRE_FLT_EQ(atan2(2, 0), DEG_TO_RAD(90.0), 0.01);
        REQUIRE_FLT_EQ(atan2(sqrt(3), 1), DEG_TO_RAD(60.0), 0.01);
        REQUIRE_FLT_EQ(atan2(sqrt(2), sqrt(2)), DEG_TO_RAD(45.0), 0.01);
        REQUIRE_FLT_EQ(atan2(sqrt(1), sqrt(3)), DEG_TO_RAD(30.0), 0.01);
        REQUIRE_FLT_EQ(atan2(0, 2), DEG_TO_RAD(0.0), 0.01);
        REQUIRE_FLT_EQ(atan2(-1, sqrt(3)), DEG_TO_RAD(-30.0), 0.01);
        REQUIRE_FLT_EQ(atan2(-sqrt(2), sqrt(2)), DEG_TO_RAD(-45.0), 0.01);
        REQUIRE_FLT_EQ(atan2(-sqrt(3), 1), DEG_TO_RAD(-60.0), 0.01);
        REQUIRE_FLT_EQ(atan2(-2, 0), DEG_TO_RAD(-90.0), 0.01);
        REQUIRE_FLT_EQ(atan2(-sqrt(3), -1), DEG_TO_RAD(-120.0), 0.01);
        REQUIRE_FLT_EQ(atan2(-sqrt(2),-sqrt(2)), DEG_TO_RAD(-135.0), 0.01);
        REQUIRE_FLT_EQ(atan2(-1, -sqrt(3)), DEG_TO_RAD(-150.0), 0.01);

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
        REQUIRE_FLT_EQ(angle(a, b), -(M_PI - .3805), 0.01);
        REQUIRE_FLT_EQ(angle(b, a), .3805, 0.01);

        /** TEST POINTS **/
        REQUIRE_FLT_EQ(a.x, 3.0, 0.001);
        REQUIRE_FLT_EQ(a.y, 4.0, 0.001);
        REQUIRE_FLT_EQ(b.x, -2.0, 0.001);
        REQUIRE_FLT_EQ(b.y, 2.0, 0.001);

        END_TEST;
        tests_run = 1;
    }
}


