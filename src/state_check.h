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
 *
 * @return Returns @c true if the player at @p port is offstage
 */
bool offstage(FunctionArg port);

/**
 * @brief Single 'coin flip' with given probability
 *
 * @param prob - <tt> floating-point value in [0,1] </tt>
 *
 * @return Returns true with probability @p prob
 */
bool chance(FunctionArg prob);

/**
 * @brief Checks if player (specified by @p port) is in hitstun
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player is in hitstun
 */
bool inHitstun(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) is in hitlag
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player is in hitlag
 */
bool inHitlag(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) is in hitstun
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player is in hitstun
 */
bool belowHeight(FunctionArg port, FunctionArg height);

/**
 * @brief Checks if player (specified by @p port) is in hitstun
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player is in hitstun
 */
bool inAir(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) is in hitstun
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player is in hitstun
 */
bool onGround(FunctionArg port);

/**
 * @brief Checks the players (specified by @p port) action state
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player's action state equals @p state
 */
bool actionStateEq(FunctionArg port, FunctionArg state);

/**
 * @brief Checks the players (specified by @p port) action state
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player's action state greater than @p state
 */
bool actionStateGeq(FunctionArg port, FunctionArg state);

/**
 * @brief Checks the players (specified by @p port) action state
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player's action state is less than @p state
 */
bool actionStateLeq(FunctionArg port, FunctionArg state);

/**
 * @brief Checks if player (specified by @p port) is in hitstun
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player is in hitstun
 */
bool nearSurface(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) is in hitstun
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player is in hitstun
 */
bool techSituation(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) is in hitstun
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player is in hitstun
 */
bool hitlagFrames(FunctionArg port, FunctionArg frames);

/**
 * @brief Checks if player (specified by @p port) is in hitstun
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player is in hitstun
 */
bool recoverySituation(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) is in hitstun
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player is in hitstun
 */
bool fallenDown(FunctionArg port);

/**
 * @brief Checks if player (specified by @p port) is in hitstun
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player is in hitstun
 */
bool hitlagFrame(FunctionArg port, FunctionArg frame);

/**
 * @brief Checks if player (specified by @p port) is in hitstun
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player is in hitstun
 */
bool breakoutFrame(FunctionArg port, FunctionArg frame);

/**
 * @brief Checks if player (specified by @p port) is in hitstun
 *
 * @param port - <tt> unsigned 32-bit integer </tt>
 *
 * @return Returns true if player is in hitstun
 */
bool pastFrame(FunctionArg frame);

#endif
