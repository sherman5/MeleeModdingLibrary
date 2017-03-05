/**
 * @file state_check.h
 * @brief Check game states.
 *
 */

#ifndef MML_STATE_CHECK_H
#define MML_STATE_CHECK_H

#include "gctypes.h"
#include "logic.h"

/**
 * @brief Checks if player (specified by @p port) is offstage
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @return Returns @c true if the player at @p port is offstage
 */
bool offstage(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) is onstage
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @return Returns @c true if the player at @p port is onstage
 */
bool onstage(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) is in hitstun
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @return Returns true if player is in hitstun
 */
bool inHitstun(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) is in hitlag
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @return Returns true if player is in hitlag
 */
bool inHitlag(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) is below @p height
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @param height - <tt> floating-point value </tt>
 * @return Returns true if player is below @p height
 */
bool belowHeight(FunctionArg port, FunctionArg height);

/**
 * @brief Checks if player (specified by @p port) is above @p height
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @param height - <tt> floating-point value </tt>
 * @return Returns true if player is above @p height
 */
bool aboveHeight(FunctionArg port, FunctionArg height);

/**
 * @brief Checks if player (specified by @p port) is in the air
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @return Returns true if player is in in the air
 */
bool inAir(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) is in on the ground
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @return Returns true if player is on the ground
 */
bool onGround(FunctionArg port);

/**
 * @brief Checks the players (specified by @p port) action state
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @param state - <tt> unsigned 32-bit integer (ActionState) </tt>
 * @return Returns true if player's action state equals @p state
 */
bool actionStateEq(FunctionArg port, FunctionArg state);

/**
 * @brief Checks the players (specified by @p port) action state
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @param state - <tt> unsigned 32-bit integer (ActionState) </tt>
 * @return Returns true if player's action state greater than @p state
 */
bool actionStateGeq(FunctionArg port, FunctionArg state);

/**
 * @brief Checks the players (specified by @p port) action state
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @param state - <tt> unsigned 32-bit integer (ActionState) </tt>
 * @return Returns true if player's action state is less than @p state
 */
bool actionStateLeq(FunctionArg port, FunctionArg state);

/**
 * @brief Checks if player (specified by @p port) is near a surface
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @return Returns true if player is near a surface
 */
bool nearSurface(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) needs to tech
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player is in a tech situation
 */
bool techSituation(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) has exact number of 
 *  frames in hitlag remaining
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @param frame - <tt> unsigned 32-bit integer </tt>
 * @return Returns true if player has @p frames of hitlag left
 */
bool hitlagFrames(FunctionArg port, FunctionArg frame);

/**
 * @brief Checks if player (specified by @p port) has exact number of 
 *  frames in hitstun remaining
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @param frame - <tt> unsigned 32-bit integer </tt>
 * @return Returns true if player has @p frames of hitlag left
 */
bool hitstunFrames(FunctionArg port, FunctionArg frame);

/**
 * @brief Checks if player (specified by @p port) needs to recover
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @return Returns true if player needs to recover
 */
bool recoverySituation(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) has fallen down
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @return Returns true if player has fallen down
 */
bool fallenDown(FunctionArg port);

/**
 * @brief Checks how frames until player (specified by @p port) 
 *  breaks out of a grab
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 * @param frames - <tt> unsigned 32-bit integer </tt>
 * @return Returns true if player has @p frames left until breakout
 */
bool breakoutFrame(FunctionArg port, FunctionArg frames);

/**
 * @brief Checks if a certain frame has passed
 *
 * @param frame - <tt> unsigned 32-bit integer </tt>
 * @return Returns true if current frame is greater than @p frame
 */
bool pastFrame(FunctionArg frame);

#endif
