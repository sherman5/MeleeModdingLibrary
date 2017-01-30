#include <math.h>
#include <melee.h>
#include <string.h>

static char stream[250];

void _main()
{
    memset(stream, 0, sizeof(stream));
    initStream(stream, 100);
    print("this is a test sentence to see how many characters fit");
    print("this is a test of multiple calls to print");
}

#if 0   

enum comparsion
{
    float_eq,
    float_neq,
    float_less,
    int_eq,
    int_neq,
    int_less
};

START_TEST
{
    /** TEST SIN **/
    REQUIRE(sin(DEG_TO_RAD(0.0)), 0.0, float_eq);


    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(30.0)), 0.5);
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(45.0)), 0.707);
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(60.0)), 0.866);
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(90.0)), 1.0); //1814
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(135.0)), 0.707);
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(225.0)), -0.707);
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(315.0)), -0.707);
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(405.0)), 0.707); //1824
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(-45.0)), -0.707);

    /** TEST COSINE **/
    REQUIRE_FLT_EQ(cos(DEG_TO_RAD(0.0)), 1.0); 
    REQUIRE_FLT_EQ(cos(DEG_TO_RAD(30.0)), 0.866);
    REQUIRE_FLT_EQ(cos(DEG_TO_RAD(45.0)), 0.707); //1834
    REQUIRE_FLT_EQ(cos(DEG_TO_RAD(60.0)), 0.5);
    REQUIRE_FLT_EQ(cos(DEG_TO_RAD(90.0)), 0); 

    /** TEST TANGENT **/
    REQUIRE_FLT_EQ(tan(DEG_TO_RAD(0.0)), 0.0); 
    REQUIRE_FLT_EQ(tan(DEG_TO_RAD(30.0)), 0.577); //1844 
    REQUIRE_FLT_EQ(tan(DEG_TO_RAD(45.0)), 1.0);
    REQUIRE_FLT_EQ(tan(DEG_TO_RAD(60.0)), 1.732);

    /** TEST FABS **/

    /** TEST IMAX **/

    /** TEST IMIN **/
    
    /** TEST FMAX **/
    
    /** TEST FMIN **/

    /** TEST IPOW **/

    /** TEST FPOW **/

    /** TEST SQRT **/
    REQUIRE_FLT_EQ(sqrt(2.0), 1.414); //1850
    REQUIRE_FLT_EQ(sqrt(0.0), 0.0);
    REQUIRE_FLT_EQ(sqrt(0.005), 0.0707);
    REQUIRE_FLT_EQ(sqrt(88.0), 9.3808);
    REQUIRE_FLT_EQ(sqrt(54610.0), 233.6878); //1860

    /** TEST ATAN2 **/

    /** TEST MAGNITUDE **/

    /** TEST DISTANCE **/

    /** TEST ANGLE **/
}
END_TEST

#endif
