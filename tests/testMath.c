#include <math.h>
#include <melee.h>
//801a5054 bl 803761c0 - display happens in here
/*80376078 - function creates display
8000b028 - calls OSTicksToCalenderTime before title screen loads
801692e8 - calls 8000b028
801a165c - calls 801692e8 (at 801a17d4)*/

//8022d640 bl 801a4b60 MenuController_ChangeScreen()

/*
801b13a0 bl 801a42e8 MenuController_WriteToPendingMajor(int)
                        writes sub menu choice from vs mode (e.g. debug)
                        80479d30 = 10600000 for debug

801a45d8 lbz r0, 0 (r30)  r30 = 80479d30 (next access)


*/

void _main()
{
    if (IN_GAME)    
{
#if 0
    void (*save)(int, //r3
                 char**, //r4 
                 uint32_t*, //r5
                 char**, //r6
                 uint32_t*, //r7
                 uint32_t*, //r8
                 uint32_t*, //r9
                 uint32_t) //r10
    = (void*) 0x8001BE30;

    char* gameTitle = "TestOutput";
    uint32_t data = 0;
    char* saveTitle = "sample save file";
    //char* content = "sample test output";
    //save(0, &title, 0, &content, 0, 0, 0, 0x8001CC30, 0);
  //  printf("mml_test");
    save(0,
        &gameTitle,
        &data,
        &saveTitle,
        &data,
        &data,
        &data,
        0x8001cc30);
#endif

//    void (*message)(char*) = (void*) 0x8032baa8; //__DVDPrintFatalMessage
//    void (*message)(char*) = (void*) 0x80302d4c; //DevelopMode_Text_Display
//    void (*message)(int) = (void*) 0x801aee6c; //MessageBox_Display
//    void (*printf)(char*, uint32_t) = (void*) 0x80335f78; //DBprintf
//    void (*printf)(char*, uint32_t) = (void*) 0x8033620c; //__DSP_debug_printf
//    void (*printf)(char*, uint32_t) = (void*) 0x80323eb4; //printf
//    void (*printf)(char*, uint32_t) = (void*) 0x80323eb0; //vprintf
    void (*printf)(char*) = (void*) 0x803456a8; //OSReport
    char* str = "test string blblblb";
//    uint32_t num = 1;
//    printf(str);
//    message(str);

}
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
