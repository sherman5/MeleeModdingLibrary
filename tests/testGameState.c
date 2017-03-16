#include <game_state.h>
#include <gctypes.h>
#include <string.h>
#include <system.h>
#include <unit_test.h>

#define DATA(p)    _gameState.playerData[p]
#define BLOCK(p)   _gameState.playerBlock[p]

#define UU8(a)   (*((u8*) (a)))
#define U16(a)   (*((u16*) (a)))
#define U32(a)   (*((u32*) (a)))
#define FLT(a)   (*((float*) (a)))
#define BLL(a)   (*((bool*) (a)))

UNIT_TEST;

static void displayPlayer(int id, u32 address)
{
    memset((void*) address, 0, 0x100);

    U32(address + 0x00) = CHAR_SELECT(id);
    U32(address + 0x04) = DATA(id)->actionState;
    FLT(address + 0x08) = DATA(id)->facingDirection;
    FLT(address + 0x0c) = DATA(id)->xSpeedSelfAir;

    FLT(address + 0x10) = DATA(id)->xSpeedSelfGround;
    FLT(address + 0x14) = DATA(id)->ySpeedSelf;
    FLT(address + 0x18) = DATA(id)->xSpeedAttack;
    FLT(address + 0x1c) = DATA(id)->ySpeedAttack;

    FLT(address + 0x20) = DATA(id)->coordinates.x;
    FLT(address + 0x24) = DATA(id)->coordinates.y;
    FLT(address + 0x28) = DATA(id)->deltaCoordinates.x;
    FLT(address + 0x2c) = DATA(id)->deltaCoordinates.y;

    BLL(address + 0x30) = DATA(id)->inAir;
    FLT(address + 0x34) = DATA(id)->jumpSquat;
    FLT(address + 0x38) = DATA(id)->numberOfJumps;
    FLT(address + 0x3c) = DATA(id)->weight;

    FLT(address + 0x40) = DATA(id)->normalLandingLag;
    FLT(address + 0x44) = DATA(id)->nairLandingLag;
    FLT(address + 0x48) = DATA(id)->bairLandingLag;
    FLT(address + 0x4c) = DATA(id)->dairLandingLag;

    FLT(address + 0x50) = DATA(id)->analogStickX;
    FLT(address + 0x54) = DATA(id)->analogStickY;
    FLT(address + 0x58) = DATA(id)->prevAnalogStickX;
    FLT(address + 0x5c) = DATA(id)->prevAnalogStickY;

    FLT(address + 0x60) = DATA(id)->lastPosition;
    UU8(address + 0x64) = DATA(id)->platformID;
    FLT(address + 0x68) = DATA(id)->actionFrame;
    FLT(address + 0x6c) = DATA(id)->percent;
        
    FLT(address + 0x70) = DATA(id)->hitlag;
    UU8(address + 0x74) = DATA(id)->jumpsUsed;
    FLT(address + 0x78) = DATA(id)->wallLocation;
    FLT(address + 0x7c) = DATA(id)->hitstun;

    U32(address + 0x80) = BLOCK(id)->playerCharacter;
    U32(address + 0x84) = BLOCK(id)->slotType;
    U16(address + 0x88) = BLOCK(id)->transformed;
    UU8(address + 0x8c) = BLOCK(id)->subcolorID;

    UU8(address + 0x90) = BLOCK(id)->playerID;
    U32(address + 0x94) = BLOCK(id)->deaths;
    U32(address + 0x98) = BLOCK(id)->p1Kills;
    U32(address + 0x9c) = BLOCK(id)->p2Kills;

}

static void testPlayer(int id)
{
    /** test block **/
    void* pBlock = _gameState.playerBlock[id];

    REQUIRE(BLOCK(id)->playerState      ==  U32(pBlock + 0x00));
    REQUIRE(BLOCK(id)->playerCharacter  ==  U32(pBlock + 0x04));
    REQUIRE(BLOCK(id)->slotType         ==  U32(pBlock + 0x08));
    REQUIRE(BLOCK(id)->transformed      ==  U16(pBlock + 0x0c));
    REQUIRE(BLOCK(id)->costumeID        ==  UU8(pBlock + 0x44));
    REQUIRE(BLOCK(id)->controllerIndex  ==  UU8(pBlock + 0x45));
    REQUIRE(BLOCK(id)->subcolorID       ==  UU8(pBlock + 0x46));
    REQUIRE(BLOCK(id)->teamID           ==  UU8(pBlock + 0x47));
    REQUIRE(BLOCK(id)->playerID         ==  UU8(pBlock + 0x48));
    REQUIRE(BLOCK(id)->deaths           ==  U32(pBlock + 0x68));
    REQUIRE(BLOCK(id)->nanaDeaths       ==  U32(pBlock + 0x6c));
    REQUIRE(BLOCK(id)->p1Kills          ==  U32(pBlock + 0x70));
    REQUIRE(BLOCK(id)->p2Kills          ==  U32(pBlock + 0x74));
    REQUIRE(BLOCK(id)->p3Kills          ==  U32(pBlock + 0x78));
    REQUIRE(BLOCK(id)->p4Kills          ==  U32(pBlock + 0x7c));
    REQUIRE(BLOCK(id)->p5Kills          ==  U32(pBlock + 0x80));
    REQUIRE(BLOCK(id)->p6Kills          ==  U32(pBlock + 0x84));
    REQUIRE(BLOCK(id)->selfDeaths       ==  UU8(pBlock + 0x8d));
    REQUIRE(BLOCK(id)->stocks           ==  UU8(pBlock + 0x8e));

    /** test data **/
    void* pData = _gameState.playerData[id];

    REQUIRE(DATA(id)->actionState                   == U32(pData + 0x0010));
    REQUIRE(DATA(id)->facingDirection               == FLT(pData + 0x002c));
    REQUIRE(DATA(id)->xSpeedSelfAir                 == FLT(pData + 0x0080));
    REQUIRE(DATA(id)->ySpeedSelf                    == FLT(pData + 0x0084));
    REQUIRE(DATA(id)->zSpeedSelf                    == FLT(pData + 0x0088));
    REQUIRE(DATA(id)->xSpeedAttack                  == FLT(pData + 0x008c));
    REQUIRE(DATA(id)->ySpeedAttack                  == FLT(pData + 0x0090));
    REQUIRE(DATA(id)->zSpeedAttack                  == FLT(pData + 0x0094));
    REQUIRE(DATA(id)->coordinates.x                 == FLT(pData + 0x00b0));
    REQUIRE(DATA(id)->coordinates.y                 == FLT(pData + 0x00b4));
    REQUIRE(DATA(id)->zPosition                     == FLT(pData + 0x00b8));
    REQUIRE(DATA(id)->prevCoordinates.x             == FLT(pData + 0x00bc));
    REQUIRE(DATA(id)->prevCoordinates.y             == FLT(pData + 0x00c0));
    REQUIRE(DATA(id)->zPrevious                     == FLT(pData + 0x00c4));
    REQUIRE(DATA(id)->deltaCoordinates.x            == FLT(pData + 0x00c8));
    REQUIRE(DATA(id)->deltaCoordinates.y            == FLT(pData + 0x00cc));
    REQUIRE(DATA(id)->zDelta                        == FLT(pData + 0x00d0));
    REQUIRE(DATA(id)->inAir                         == BLL(pData + 0x00e0));
    REQUIRE(DATA(id)->xSpeedSelfGround              == FLT(pData + 0x00ec));
    REQUIRE(DATA(id)->walkInitialVelocity           == FLT(pData + 0x0110));
    REQUIRE(DATA(id)->walkAcceleration              == FLT(pData + 0x0114));
    REQUIRE(DATA(id)->walkMaximumVelocity           == FLT(pData + 0x0118));
    REQUIRE(DATA(id)->slowWalkMax                   == FLT(pData + 0x011c));
    REQUIRE(DATA(id)->midWalkPoint                  == FLT(pData + 0x0120));
    REQUIRE(DATA(id)->fastWalkMin                   == FLT(pData + 0x0124));
    REQUIRE(DATA(id)->groundFriction                == FLT(pData + 0x0128));
    REQUIRE(DATA(id)->dashInitialVelocity           == FLT(pData + 0x012c));
    REQUIRE(DATA(id)->dashAccelerationA             == FLT(pData + 0x0130));
    REQUIRE(DATA(id)->dashAcceleationB              == FLT(pData + 0x0134));
    REQUIRE(DATA(id)->dashTerminalVelocity          == FLT(pData + 0x0138));
    REQUIRE(DATA(id)->runAnimationScaling           == FLT(pData + 0x013c));
    REQUIRE(DATA(id)->runAcceleration               == FLT(pData + 0x0140));
    REQUIRE(DATA(id)->groundedMaxHorizontalVelocity == FLT(pData + 0x0144));
    REQUIRE(DATA(id)->jumpSquat                     == FLT(pData + 0x0148));
    REQUIRE(DATA(id)->jumpHorizontalInitialVelocity == FLT(pData + 0x014c));
    REQUIRE(DATA(id)->jumpVerticalInitialVelocity   == FLT(pData + 0x0150));
    REQUIRE(DATA(id)->groundToAirJumpMomentum       == FLT(pData + 0x0154));
    REQUIRE(DATA(id)->jumpHorizontalMaxVelocity     == FLT(pData + 0x0158));
    REQUIRE(DATA(id)->hopVerticalInitialVelocity    == FLT(pData + 0x015c));
    REQUIRE(DATA(id)->airJumpVerticalMultiplier     == FLT(pData + 0x0160));
    REQUIRE(DATA(id)->airJumpHorizontalMultiplier   == FLT(pData + 0x0164));
    REQUIRE(DATA(id)->numberOfJumps                 == FLT(pData + 0x0168));
    REQUIRE(DATA(id)->gravity                       == FLT(pData + 0x016c));
    REQUIRE(DATA(id)->terminalVelocity              == FLT(pData + 0x0170));
    REQUIRE(DATA(id)->airMobilityA                  == FLT(pData + 0x0174));
    REQUIRE(DATA(id)->airMobilityB                  == FLT(pData + 0x0178));
    REQUIRE(DATA(id)->maxHorizontalAirMobility      == FLT(pData + 0x017c));
    REQUIRE(DATA(id)->horizontalAirFriction         == FLT(pData + 0x0180));
    REQUIRE(DATA(id)->fastfallVelocity              == FLT(pData + 0x0184));
    REQUIRE(DATA(id)->jab2inputWindow               == FLT(pData + 0x018c));
    REQUIRE(DATA(id)->jab3inputWindow               == FLT(pData + 0x0190));
    REQUIRE(DATA(id)->framesToChangeDirection       == FLT(pData + 0x0194));
    REQUIRE(DATA(id)->weight                        == FLT(pData + 0x0198));
    REQUIRE(DATA(id)->modelScaling                  == FLT(pData + 0x019c));
    REQUIRE(DATA(id)->maxShieldSize                 == FLT(pData + 0x01a0));
    REQUIRE(DATA(id)->shieldBreakInitialVelocity    == FLT(pData + 0x01a4));
    REQUIRE(DATA(id)->rapidJabWindow                == FLT(pData + 0x01a8));
    REQUIRE(DATA(id)->normalLandingLag              == FLT(pData + 0x01f4));
    REQUIRE(DATA(id)->nairLandingLag                == FLT(pData + 0x01f8));
    REQUIRE(DATA(id)->fairLandingLag                == FLT(pData + 0x01fc));
    REQUIRE(DATA(id)->bairLandingLag                == FLT(pData + 0x0200));
    REQUIRE(DATA(id)->uairLandingLag                == FLT(pData + 0x0204));
    REQUIRE(DATA(id)->dairLandingLag                == FLT(pData + 0x0208));
    REQUIRE(DATA(id)->wallJumpHorizontalVelocity    == FLT(pData + 0x0214));
    REQUIRE(DATA(id)->wallJumpVerticalVelocity      == FLT(pData + 0x0218));
    REQUIRE(DATA(id)->analogStickX                  == FLT(pData + 0x0620));
    REQUIRE(DATA(id)->analogStickY                  == FLT(pData + 0x0624));
    REQUIRE(DATA(id)->prevAnalogStickX              == FLT(pData + 0x0628));
    REQUIRE(DATA(id)->prevAnalogStickY              == FLT(pData + 0x062c));
    REQUIRE(DATA(id)->cStickX                       == FLT(pData + 0x0638));
    REQUIRE(DATA(id)->cStickY                       == FLT(pData + 0x063c));
    REQUIRE(DATA(id)->analogTriggerData             == FLT(pData + 0x0650));
    REQUIRE(DATA(id)->digitalButtonData             == U32(pData + 0x065c));
    REQUIRE(DATA(id)->prevDigitalButtonData         == U32(pData + 0x0660));
    REQUIRE(DATA(id)->lastPosition                  == FLT(pData + 0x0830));
    REQUIRE(DATA(id)->platformID                    == UU8(pData + 0x083f));
    REQUIRE(DATA(id)->stageRelationID               == UU8(pData + 0x0842));
    REQUIRE(DATA(id)->stageTransformationID         == UU8(pData + 0x0843));
    REQUIRE(DATA(id)->actionFrame                   == FLT(pData + 0x0894));
    REQUIRE(DATA(id)->percent                       == FLT(pData + 0x1830));
    REQUIRE(DATA(id)->percentForDamageCalc          == FLT(pData + 0x1838));
    REQUIRE(DATA(id)->damageApplied                 == U32(pData + 0x183c));
    REQUIRE(DATA(id)->damageDirection               == FLT(pData + 0x1844));
    REQUIRE(DATA(id)->knockbackAngle                == U32(pData + 0x1848));
    REQUIRE(DATA(id)->forceApplied                  == FLT(pData + 0x1850));
    REQUIRE(DATA(id)->hitlag                        == FLT(pData + 0x195c));
    REQUIRE(DATA(id)->jumpsUsed                     == UU8(pData + 0x1968));
    REQUIRE(DATA(id)->bodyState                     == U32(pData + 0x198c));
    REQUIRE(DATA(id)->ledgeInvincibility            == FLT(pData + 0x1990));
    REQUIRE(DATA(id)->haloInvincinility             == FLT(pData + 0x1994));
    REQUIRE(DATA(id)->shieldSize                    == FLT(pData + 0x1998));
    REQUIRE(DATA(id)->lightshieldAmount             == FLT(pData + 0x199c));
    REQUIRE(DATA(id)->breakoutCountdown             == FLT(pData + 0x1a4c));
    REQUIRE(DATA(id)->aiType                        == UU8(pData + 0x1a97));
    REQUIRE(DATA(id)->aiLevel                       == UU8(pData + 0x1a9b));
    REQUIRE(DATA(id)->actionCounter                 == U32(pData + 0x206c));
    REQUIRE(DATA(id)->comboCount                    == U16(pData + 0x2090));
    REQUIRE(DATA(id)->wallrideCounter               == UU8(pData + 0x210c));
    REQUIRE(DATA(id)->wallLocation                  == FLT(pData + 0x2110));
    REQUIRE(DATA(id)->smashAttackState              == U32(pData + 0x2114));
    REQUIRE(DATA(id)->smashChargeFrame              == U32(pData + 0x2118));
    REQUIRE(DATA(id)->smashChargeFrameMax           == FLT(pData + 0x211c));
    REQUIRE(DATA(id)->smashChargeStrength           == FLT(pData + 0x2120));
    REQUIRE(DATA(id)->canWallJump                   == UU8(pData + 0x2224));
    REQUIRE(DATA(id)->hitstun                       == FLT(pData + 0x2340));
}

static bool initRun = false;
static char heap[15000];

static void init(void)
{
    initHeap(heap, heap + sizeof(heap));
}

void _main(void)
{
    if (!initRun) {init(); initRun = true;}

    updateGameState();

    memset((void*) 0x80001800, 0, 0x100);

    BLL(0x80001800) = inGame();
    U32(0x80001804) = CURRENT_FRAME;

    *((StageName*) 0x80001808) = _gameState.stage.name;
    FLT(0x8000180c) = _gameState.stage.ledge.x;
    FLT(0x80001810) = _gameState.stage.ledge.y;
    FLT(0x80001814) = _gameState.stage.side.left;
    FLT(0x80001818) = _gameState.stage.side.right;
    FLT(0x8000181c) = _gameState.stage.side.height;
    FLT(0x80001820) = _gameState.stage.top.left;
    FLT(0x80001824) = _gameState.stage.top.right;
    FLT(0x80001828) = _gameState.stage.top.height;

    U32(0x8000182c) = PLAYER_STATE(1);
    U32(0x80001830) = PLAYER_STATE(2);
    U32(0x80001834) = PLAYER_STATE(3);
    U32(0x80001838) = PLAYER_STATE(4);

    if (PLAYER_STATE(1) && _tests_passed)
    {
        testPlayer(1);
        displayPlayer(1, 0x80001900);
    }

    if (PLAYER_STATE(2) && _tests_passed)
    {
        testPlayer(2);
        displayPlayer(2, 0x80001a00);
    }

    if (PLAYER_STATE(3) && _tests_passed)
    {
        testPlayer(3);
        displayPlayer(3, 0x80001c00);
    }

    if (PLAYER_STATE(4) && _tests_passed)
    {
        testPlayer(4);
        displayPlayer(4, 0x80001e00);
    }

    END_TEST;
}


