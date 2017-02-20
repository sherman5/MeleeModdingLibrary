/**
 * @file math.h
 * @brief Useful math functions.
 *
 */

#ifndef MML_MATH_H
#define MML_MATH_H

#include "gctypes.h"

/** approximate value of pi */
#define M_PI 3.14159265359f

/** approximate value of pi / 180 */
#define DEG_TO_RAD(x) ((x) * 0.01745329251f)

/** approximate value of 180 / pi */
#define RAD_TO_DEG(x) ((x) * 57.2957795131f)

/** returns 1 or -1 depending on the sign of x */
#define SIGN(x) (((x) >= 0) - ((x) < 0))

/** @cond */
extern float (*sin)(float x);
extern float (*cos)(float x);
extern float (*tan)(float x);
extern float (*fabs)(float x);
extern float (*recipSqrt)(float x);

__inline__ __attribute__((always_inline)) float sqrt(float x)
    {return x == 0 ? 0 : 1 / recipSqrt(x);}

#if 0
/// @endcond

/**
 * @brief Returns the sine @p x radians.
 *
 * @param x - An angle expressed in radians.
 *
 * @return Sine of @p x radians.
 */
float sin(float x);

/**
 * @brief Returns the cosine @p x radians.
 *
 * @param x - An angle expressed in radians.
 *
 * @return Cosine of @p x radians.
 */
float cos(float x);

/**
 * @brief Returns the tangent @p x radians.
 *
 * @param x - An angle expressed in radians.
 *
 * @return Tangent of @p x radians.
 */
float tan(float x);

/**
 * @brief Returns the absolute value of @p x.
 *
 * @param x - A floating point number.
 *
 * @return The absolute value of @p x.
 */
float fabs(float x);

/**
 * @brief Returns the square root of @p x
 *
 * @param x - a floating point number
 * 
 * @return the square root of @p x
 */
float sqrt(float x);

/** @cond */
#endif
/** @endcond */

/**
 * @brief Round down value
 *
 * Rounds @p x downward, returning the largest integral value that is
 * not greater than @ x
 *
 * @param x - Value to round down
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
 * @param x - Value to round up
 *
 * @return The value of @x rounded upward (as a floating-point value)
 *
 * @see http://www.cplusplus.com/reference/cmath/floor/
 */
float ceil(float x);

/**
 * @brief Returns the maximum of two numbers.
 *
 * @param a - 32-bit @c signed @c int
 * @param b - 32-bit @c signed @c int
 * 
 * @return The larger value of @p a and @p b.
 */
s32 imax(s32 a, s32 b);

/**
 * @brief Returns the minimum of two numbers.
 *
 * @param a - 32-bit @c signed @c int
 * @param b - 32-bit @c signed @c int
 * 
 * @return The smaller value of @p a and @p b.
 */
s32 imin(s32 a, s32 b);

/**
 * @brief Returns the maximum of two numbers.
 *
 * @param a - a floating point number
 * @param b - a floating point number
 * 
 * @return The larger value of @p a and @p b.
 */
float fmax(float a, float b);

/**
 * @brief Returns the minimum of two numbers.
 *
 * @param a - a floating point number
 * @param b - a floating point number
 * 
 * @return The smaller value of @p a and @p b.
 */
float fmin(float a, float b);

/**
 * @brief Returns @p base raised to the power of @p exp
 *
 * @param base - a 16-bit @c signed @c int
 * @param exp - an 8-bit @c signed @c int
 * 
 * @return @p base raised to the power of @p exp
 */
s32 ipow(s16 base, u8 exp);

/**
 * @brief Returns @p base raised to the power of @p exp
 *
 * @param base - a floating point number
 * @param exp - an 8-bit @c signed @c int
 * 
 * @return @p base raised to the power of @p exp
 */
float fpow(float base, u8 exp);

/**
 * @brief Struct containing the coordinates of a point 
 */
typedef struct
{
    float x; /**< X-coordinate of point */
    float y; /**< Y-coordinate of point */

} Point;

/**
 * @brief Compute arc tangent with two parameters 
 * 
 * Returns the arc tangent of @p y / @p x, expressed in radians. To 
 * compute the value, the function takes into accout the sign of
 * both arguments in order to determine the quadrant. 
 *
 * @param y - Y-coordinate relative to (0,0)
 * @param x - X-coordinate relative to (0,0)
 *
 * @return arc tangent of @p y / @p x, in interval (-pi, +pi] radians
 *
 * @see http://www.cplusplus.com/reference/cmath/atan2/
 * @see http://www.embedded.com/design/other/4216719/Performing-efficient-arctangent-approximation
 */
float atan2(float y, float x);

/**
 * @brief Returns the magnitude of @p pt (i.e. distance from (0,0)
 *
 * @param pt - A Point struct
 *
 * @return The distance of @p pt from (0,0)
 *
 * @note error is within 0.26 degrees or 0.0045 radians
 */
float magnitude(Point pt);

/**
 * @brief Returns the distance between two points.
 *
 * @param a - A Point struct
 * @param b - A Point struct
 *
 * @return The distance between @p a and @p b
 */
float distance(Point a, Point b);

/**
 * @brief Returns the angle between two points.
 *
 * @param a - A Point struct
 * @param b - A Point struct
 *
 * @return The angle between @p a and @p b in interval (-pi, +pi] radians
 */
float angle(Point a, Point b);

#endif
