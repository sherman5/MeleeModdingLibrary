/**
 * @file math.h
 * @brief Useful math functions.
 *
 */

#ifndef MML_MATH_H
#define MML_MATH_H

#include "gctypes.h"

/** approximate value of pi */
#define M_PI        3.14159265358f
#define M_2PI       6.28318530718f   
#define M_HALF_PI   1.57079632679f

/** approximate value of pi / 180 */
#define DEG_TO_RAD(x) ((x) * 0.01745329251f)

/** approximate value of 180 / pi */
#define RAD_TO_DEG(x) ((x) * 57.2957795131f)

/** sign of value **/
#define SIGN(x) ((x) < 0 ? -1 : 1)

/**
 * @brief Struct containing the coordinates of a point 
 */
typedef struct
{
    float x; /**< X-coordinate of point */
    float y; /**< Y-coordinate of point */

} Point;

/** @cond */
extern float (*fabs)(float x);
extern float (*recipSqrt)(float x);

__inline__ __attribute__((always_inline)) float sqrt(float x)
    {return x == 0 ? 0 : 1 / recipSqrt(x);}

#if 0
/// @endcond

/**
 * @brief Absolute value of @p x.
 *
 * @param x - floating-point value
 *
 * @return The absolute value of @p x.
 */
float fabs(float x);

/**
 * @brief Square root of @p x
 *
 * @param x - floating-point value
 * 
 * @return the square root of @p x
 */
float sqrt(float x);

/**
 * @brief <tt> 1 / sqrt(x) </tt>
 *
 * @param x - floating-point value
 * 
 * @return the reciprical square root of @p x
 */
float recipSqrt(float x);

/** @cond */
#endif
/** @endcond */

/**
 * @brief Round down value
 *
 * Rounds @p x downward, returning the largest integral value that is
 * not greater than @ x
 *
 * @param x - floating-point value
 *
 * @return The value of @x rounded downward (as a floating-point value)
 *
 * @see http://www.cplusplus.com/reference/cmath/floor/
 */
float floor(float x);

/**
 * @brief Round up value
 *
 * Rounds @p x upward, returning the smallest integral value that is
 * not less than @ x
 *
 * @param x - floating-point value
 *
 * @return The value of @x rounded upward (as a floating-point value)
 *
 * @see http://www.cplusplus.com/reference/cmath/floor/
 */
float ceil(float x);

/**
 * @brief Maximum of two integers
 *
 * @param a - 32-bit @c signed @c int
 * @param b - 32-bit @c signed @c int
 * 
 * @return The larger value of @p a and @p b
 */
s32 imax(s32 a, s32 b);

/**
 * @brief Minimum of two integers
 *
 * @param a - 32-bit @c signed @c int
 * @param b - 32-bit @c signed @c int
 * 
 * @return The smaller value of @p a and @p b
 */
s32 imin(s32 a, s32 b);

/**
 * @brief Maximum of two floating-point values
 *
 * @param a - floating-point value
 * @param b - floating-point value
 * 
 * @return The larger value of @p a and @p b
 */
float fmax(float a, float b);

/**
 * @brief Minimum of two floating-point values
 *
 * @param a - floating-point value
 * @param b - floating-point value
 * 
 * @return The smaller value of @p a and @p b
 */
float fmin(float a, float b);

/**
 * @brief @p base raised to the power of @p exp
 *
 * @param base - 16-bit @c signed @c int
 * @param exp - 8-bit @c signed @c int
 * 
 * @return @p base raised to the power of @p exp
 */
s32 ipow(s16 base, u8 exp);

/**
 * @brief @p base raised to the power of @p exp
 *
 * @param base - floating-point value
 * @param exp - 8-bit @c signed @c int
 * 
 * @return @p base raised to the power of @p exp
 */
float fpow(float base, u8 exp);

/**
 * @brief Sine of @p x, expressed in degrees
 *
 * @param x - floating-point value in <tt> [0, 360) </tt>
 *
 * @return Sine of @p x
 */
float sin(float x);

/**
 * @brief Cosine of @p x, expressed in degrees
 *
 * @param x - floating-point value in <tt> [0, 360) </tt>
 *
 * @return Cosine of @p x
 */
float cos(float x);

/**
 * @brief Tangent of @p x, expressed in degrees
 *
 * @param x - floating-point value in <tt> [0, 360) </tt>
 *
 * @return Tangent of @p x
 */
float tan(float x);

/**
 * @brief Arc sine of @p x
 * 
 * @param x - floating-point value in <tt> [-1, +1] </tt>
 *
 * @return inverse sine of @x, expressed in degress in range
 * <tt> [0, 90] </tt> and <tt> [270, 360) </tt>
 */
float asin(float x);

/**
 * @brief Arc cosine of @p x
 * 
 * @param x - floating-point value in <tt> [-1, +1] </tt>
 *
 * @return inverse cosine of @x, expressed in degress in range 
 * <tt> [0, 180] </tt>
*/
float acos(float x);

/**
 * @brief Arc tangent of @p x
 * 
 * @param x - floating-point value in <tt> [0, inf) </tt>
 *
 * @return inverse tangent of @x, expressed in degress in range
 * <tt> [0, 90) </tt>
*/
float atan(float x);

/**
 * @brief Compute arc tangent with two parameters
 * 
 * Returns the arc tangent of @p y / @p x, expressed in degrees. To 
 * compute the value, the function takes into accout the sign of
 * both arguments in order to determine the quadrant. 
 *
 * @param y - floating-point value
 * @param x - floating-point value
 *
 * @return arc tangent of @p y / @p x, in interval [0, 360) degrees
 *
 * @see http://www.cplusplus.com/reference/cmath/atan2/
 * @see http://www.embedded.com/design/other/4216719/Performing-efficient-arctangent-approximation
 */
float atan2(float y, float x);

/**
 * @brief Magnitude of point
 *
 * @param pt - Point struct
 *
 * @return The distance of @p pt from (0,0)
 *
 * @note error is within 0.26 degrees
 */
float magnitude(Point pt);

/**
 * @brief Distance between two points
 *
 * @param a - Point struct
 * @param b - Point struct
 *
 * @return The distance between @p a and @p b
 */
float distance(Point a, Point b);

/**
 * @brief Angle between two points
 *
 * @param a - Point struct
 * @param b - Point struct
 *
 * @return The angle between @p a and @p b in <tt> [0, 360] </tt> degrees
 */
float angle(Point a, Point b);

#endif
