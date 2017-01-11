#include "testing.h"
#include <math.h>

void runTest(int numTests)
{
    /** TEST SIN **/
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(0.0)), 0); //1800
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(30.0)), 0.5);
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(45.0)), 0.707);
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(60.0)), 0.866);
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(90.0)), 1.0); //1810
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(135.0)), 0.707);
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(225.0)), -0.707);
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(315.0)), -0.707);
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(405.0)), 0.707);//1820
    REQUIRE_FLT_EQ(sin(DEG_TO_RAD(-45.0)), -0.707);

    /** TEST COSINE **/
    REQUIRE_FLT_EQ(cos(DEG_TO_RAD(0.0)), 1.0); 
    REQUIRE_FLT_EQ(cos(DEG_TO_RAD(30.0)), 0.866);
    REQUIRE_FLT_EQ(cos(DEG_TO_RAD(45.0)), 0.707); //1830
    REQUIRE_FLT_EQ(cos(DEG_TO_RAD(60.0)), 0.5);
    REQUIRE_FLT_EQ(cos(DEG_TO_RAD(90.0)), 0); 

    /** TEST TANGENT **/
    REQUIRE_FLT_EQ(tan(DEG_TO_RAD(0.0)), 0.0); 
    REQUIRE_FLT_EQ(tan(DEG_TO_RAD(30.0)), 0.577); //1840
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

    /** TEST ATAN2 **/

    /** TEST MAGNITUDE **/

    /** TEST DISTANCE **/

    /** TEST ANGLE **/
}

END_TEST
