#pragma once
#include <Windows.h>
#include <process.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <functional>
#include <Shlwapi.h>

//DirectX
#include "../DirectX/d3d9.h"
#include "../DirectX/d3dx9.h"

//new hooks
#include "../memwrapper/memwrapper.h"

//WinSock
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "WS2_32.lib")

//raknet
//#include "samp_auth.h"
#include "samp_netencr.h"
#include "RakNet/PacketEnumerations.h"
#include "RakNet/SHA1.h"
#include "RakNet/RakNetworkFactory.h"
#include "RakNet/RakClientInterface.h"
#include "RakNet/NetworkTypes.h"
#include "RakNet/BitStream.h"
#include "RakNet/StringCompressor.h"
using namespace RakNet;

//samp api
#include "API/AimStuff.h"
#include "API/Animation.h"
#include "API/CActor.h"
#include "API/CActorPool.h"
#include "API/CAudio.h"
#include "API/CAudioStream.h"
#include "API/CCamera.h"
#include "API/CChat.h"
#include "API/CConfig.h"
#include "API/CDeathWindow.h"
#include "API/CDialog.h"
#include "API/CEntity.h"
#include "API/CFonts.h"
#include "API/CGame.h"
#include "API/CGangZonePool.h"
#include "API/CHttpClient.h"
#include "API/CInput.h"
#include "API/CLabel.h"
#include "API/CLabelPool.h"
#include "API/CLicensePlate.h"
#include "API/CLocalPlayer.h"
#include "API/CMatrix.h"
#include "API/CMenu.h"
#include "API/CMenuPool.h"
#include "API/CNetGame.h"
#include "API/CNetStats.h"
#include "API/CObject.h"
#include "API/CObjectPool.h"
#include "API/CObjectSelection.h"
#include "API/CPed.h"
#include "API/CPickupPool.h"
#include "API/CPlayerInfo.h"
#include "API/CPlayerPool.h"
#include "API/CPlayerTags.h"
#include "API/CRect.h"
#include "API/CRemotePlayer.h"
#include "API/CScoreboard.h"
#include "API/CSpawnScreen.h"
#include "API/CTextDraw.h"
#include "API/CTextDrawPool.h"
#include "API/CTextDrawSelection.h"
#include "API/CVector.h"
#include "API/CVehicle.h"
#include "API/CVehiclePool.h"
#include "API/Commands.h"
#include "API/ControllerState.h"
#include "API/Debug.h"
#include "API/DebugScript.h"
#include "API/Exception.h"
#include "API/GUI.h"
#include "API/InputHandler.h"
#include "API/KeyStuff.h"
#include "API/RPC.h"
#include "API/Scripting.h"
#include "API/Settings.h"
#include "API/SpecialAction.h"
#include "API/VehicleSelection.h"

//plugin sdk
#pragma comment(lib, "plugin.lib")
#include "plugin.h"

#include "CPed.h"
#include "CWorld.h"
#include "CPopulation.h"
#include "CCivilianPed.h"
#include "CStats.h"
#include "CClothes.h"
#include "CCamera.h"
#include "CAnimManager.h"
#include "CStreaming.h"
#include "CRunningScript.h"
#include "CPlayerPed.h"
#include "CModelInfo.h"
#include "CDraw.h"
#include "CMenuManager.h"
#include "CClock.h"
#include "CWeather.h"
#include "CTaskSimpleRunNamedAnim.h"
#include "CTrailer.h"
#include "CGame.h"
#include "CCam.h"
#include "CTrailer.h"
#include "C3dMarker.h"
#include "C3dMarkers.h"
#include "CCheckpoint.h"
#include "CCheckpoints.h"
#include "CTaskSimpleJump.h"
#include "CMessages.h"
#include "ePedBones.h"
#include "extensions/ScriptCommands.h"

const float fWeaponDamage[55] =
{
	1.0f, // 0 - Fist
	1.0f, // 1 - Brass knuckles
	1.0f, // 2 - Golf club
	1.0f, // 3 - Nitestick
	1.0f, // 4 - Knife
	1.0f, // 5 - Bat
	1.0f, // 6 - Shovel
	1.0f, // 7 - Pool cue
	1.0f, // 8 - Katana
	1.0f, // 9 - Chainsaw
	1.0f, // 10 - Dildo
	1.0f, // 11 - Dildo 2
	1.0f, // 12 - Vibrator
	1.0f, // 13 - Vibrator 2
	1.0f, // 14 - Flowers
	1.0f, // 15 - Cane
	82.5f, // 16 - Grenade
	0.0f, // 17 - Teargas
	1.0f, // 18 - Molotov
	9.9f, // 19 - Vehicle M4 (custom)
	46.2f, // 20 - Vehicle minigun (custom)
	0.0f, // 21
	8.25f, // 22 - Colt 45
	13.200001f, // 23 - Silenced
	46.200001f, // 24 - Deagle
	49.500004f,//3.3, // 25 - Shotgun
	49.500004f,//3.3, // 26 - Sawed-off
	39.600002f,//4.95, // 27 - Spas
	6.6f, // 28 - UZI
	8.25f, // 29 - MP5
	9.900001f, // 30 - AK47
	9.900001f, // 31 - M4
	6.6f, // 32 - Tec9
	24.750002f, // 33 - Cuntgun
	41.25f, // 34 - Sniper
	82.5, // 35 - Rocket launcher
	82.5, // 36 - Heatseeker
	1.0, // 37 - Flamethrower
	46.200001f, // 38 - Minigun
	82.5f, // 39 - Satchel
	0.0f, // 40 - Detonator
	0.33f, // 41 - Spraycan
	0.33f, // 42 - Fire extinguisher
	0.0f, // 43 - Camera
	0.0f, // 44 - Night vision
	0.0f, // 45 - Infrared
	0.0f, // 46 - Parachute
	0.0f, // 47 - Fake pistol
	2.64f, // 48 - Pistol whip (custom)
	9.9f, // 49 - Vehicle
	330.0f, // 50 - Helicopter blades
	82.5f, // 51 - Explosion
	1.0f, // 52 - Car park (custom)
	1.0f, // 53 - Drowning
	165.0f // 54 - Splat
};
const float fWeaponRange[39] =
{
	0.0f, // 0 - Fist
	0.0f, // 1 - Brass knuckles
	0.0f, // 2 - Golf club
	0.0f, // 3 - Nitestick
	0.0f, // 4 - Knife
	0.0f, // 5 - Bat
	0.0f, // 6 - Shovel
	0.0f, // 7 - Pool cue
	0.0f, // 8 - Katana
	0.0f, // 9 - Chainsaw
	0.0f, // 10 - Dildo
	0.0f, // 11 - Dildo 2
	0.0f, // 12 - Vibrator
	0.0f, // 13 - Vibrator 2
	0.0f, // 14 - Flowers
	0.0f, // 15 - Cane
	0.0f, // 16 - Grenade
	0.0f, // 17 - Teargas
	0.0f, // 18 - Molotov
	90.0f, // 19 - Vehicle M4 (custom)
	75.0f, // 20 - Vehicle minigun (custom)
	0.0f, // 21
	35.0f, // 22 - Colt 45
	35.0f, // 23 - Silenced
	35.0f, // 24 - Deagle
	40.0f, // 25 - Shotgun
	35.0f, // 26 - Sawed-off
	40.0f, // 27 - Spas
	35.0f, // 28 - UZI
	45.0f, // 29 - MP5
	70.0f, // 30 - AK47
	90.0f, // 31 - M4
	35.0f, // 32 - Tec9
	100.0f, // 33 - Cuntgun
	320.0f, // 34 - Sniper
	0.0f, // 35 - Rocket launcher
	0.0f, // 36 - Heatseeker
	0.0f, // 37 - Flamethrower
	75.0f  // 38 - Minigun
};

enum
{
	SAMP_MAX_ACTORS = 1000,
	SAMP_MAX_PLAYERS = 1004,
	SAMP_MAX_VEHICLES = 2000,
	SAMP_MAX_PICKUPS = 4096,
	SAMP_MAX_OBJECTS = 1000,
	SAMP_MAX_GANGZONES = 1024,
	SAMP_MAX_3DTEXTS = 2048,
	SAMP_MAX_TEXTDRAWS = 2048,
	SAMP_MAX_PLAYERTEXTDRAWS = 256,
	SAMP_MAX_CLIENTCMDS = 144,
	SAMP_MAX_MENUS = 128,
	SAMP_MAX_PLAYER_NAME = 24,
	SAMP_ALLOWED_PLAYER_NAME_LENGTH = 20,
};
enum
{
	DIALOG_STYLE_MSGBOX = 0,
	DIALOG_STYLE_INPUT = 1,
	DIALOG_STYLE_LIST = 2,
	DIALOG_STYLE_PASSWORD = 3,
	DIALOG_STYLE_TABLIST = 4,
	DIALOG_STYLE_TABLIST_HEADERS = 5
};
enum
{
	SPECIAL_ACTION_NONE,
	SPECIAL_ACTION_DUCK,
	SPECIAL_ACTION_USEJETPACK,
	SPECIAL_ACTION_ENTER_VEHICLE,
	SPECIAL_ACTION_EXIT_VEHICLE,
	SPECIAL_ACTION_DANCE1,
	SPECIAL_ACTION_DANCE2,
	SPECIAL_ACTION_DANCE3,
	SPECIAL_ACTION_DANCE4,
	SPECIAL_ACTION_HANDSUP,
	SPECIAL_ACTION_USECELLPHONE,
	SPECIAL_ACTION_SITTING,
	SPECIAL_ACTION_STOPUSECELLPHONE,
	SPECIAL_ACTION_DRINK_BEER = 20,
	SPECIAL_ACTION_SMOKE_CIGGY,
	SPECIAL_ACTION_DRINK_WINE,
	SPECIAL_ACTION_DRINK_SPRUNK,
	SPECIAL_ACTION_CUFFED,
	SPECIAL_ACTION_CARRY,
};



#pragma pack(push, 1)
struct stSAMPKeys
{
	unsigned __int8 keys_primaryFire : 1;
	unsigned __int8 keys_horn__crouch : 1;
	unsigned __int8 keys_secondaryFire__shoot : 1;
	unsigned __int8 keys_accel__zoomOut : 1;
	unsigned __int8 keys_enterExitCar : 1;
	unsigned __int8 keys_decel__jump : 1;			// on foot: jump or zoom in
	unsigned __int8 keys_circleRight : 1;
	unsigned __int8 keys_aim : 1;					// hydra auto aim or on foot aim
	unsigned __int8 keys_circleLeft : 1;
	unsigned __int8 keys_landingGear__lookback : 1;
	unsigned __int8 keys_unknown__walkSlow : 1;
	unsigned __int8 keys_specialCtrlUp : 1;
	unsigned __int8 keys_specialCtrlDown : 1;
	unsigned __int8 keys_specialCtrlLeft : 1;
	unsigned __int8 keys_specialCtrlRight : 1;
	unsigned __int8 keys__unused : 1;
};
struct stOnFootData
{
	unsigned __int16 sLeftRightKeys;
	unsigned __int16 sUpDownKeys;
	union
	{
		unsigned __int16 sKeys;
		struct stSAMPKeys stSampKeys;
	};
	float fPosition[3];
	float fQuaternion[4];
	unsigned __int8 byteHealth;
	unsigned __int8 byteArmor;
	unsigned __int8 byteCurrentWeapon;
	unsigned __int8 byteSpecialAction;
	float fMoveSpeed[3];
	float fSurfingOffsets[3];
	unsigned __int16 sSurfingVehicleID;
	short sCurrentAnimationID;
	short sAnimFlags;
};
struct stInCarData
{
	unsigned __int16 sVehicleID;
	unsigned __int16 sLeftRightKeys;
	unsigned __int16 sUpDownKeys;
	union
	{
		unsigned __int16 sKeys;
		struct stSAMPKeys stSampKeys;
	};
	float fQuaternion[4];
	float fPosition[3];
	float fMoveSpeed[3];
	float fVehicleHealth;
	unsigned __int8 bytePlayerHealth;
	unsigned __int8 byteArmor;
	unsigned __int8 byteCurrentWeapon;
	unsigned __int8 byteSiren;
	unsigned __int8 byteLandingGearState;
	unsigned __int16 sTrailerID;
	union
	{
		unsigned __int16 HydraThrustAngle[2];	//nearly same value
		float fTrainSpeed;
	};
};
struct stAimData
{
	unsigned __int8	byteCamMode;
	float vecAimf1[3];
	float vecAimPos[3];
	float fAimZ;
	unsigned __int8	byteCamExtZoom : 6;		// 0-63 normalized
	unsigned __int8	byteWeaponState : 2;	// see eWeaponState
	unsigned __int8	byteAspectRatio;
};
struct stTrailerData
{
	unsigned __int16 sTrailerID;
	float fPosition[3];
	float fQuaternion[4];
	float fSpeed[3];
	float fAngularSpeed[3];
};
struct stPassengerData
{
	unsigned __int16 sVehicleID;
	unsigned __int8	 byteSeatID;
	unsigned __int8 byteCurrentWeapon;
	unsigned __int8 byteHealth;
	unsigned __int8 byteArmor;
	unsigned __int16 sLeftRightKeys;
	unsigned __int16 sUpDownKeys;
	union
	{
		unsigned __int16 sKeys;
		struct stSAMPKeys stSampKeys;
	};
	float fPosition[3];
};
struct stUnoccupiedData
{
	__int16 sVehicleID;
	unsigned __int8 byteSeatID;
	float fRoll[3];
	float fDirection[3];
	float fPosition[3];
	float fMoveSpeed[3];
	float fTurnSpeed[3];
	float fHealth;
};
struct stBulletData
{
	unsigned __int8	 byteType;
	unsigned __int16 sTargetID;
	float fOrigin[3];
	float fTarget[3];
	float fCenter[3];
	unsigned __int8 byteWeaponID;
};
struct stSpectatorData
{
	unsigned __int16 sLeftRightKeys;
	unsigned __int16 sUpDownKeys;
	union
	{
		unsigned __int16 sKeys;
		struct stSAMPKeys stSampKeys;
	};
	float fPosition[3];
};
struct stDamageData
{
	uint16_t	sVehicleID_lastDamageProcessed;
	int			iBumperDamage;
	int			iDoorDamage;
	uint8_t		byteLightDamage;
	uint8_t		byteWheelDamage;
};
struct stStreamedOutPlayerInfo
{
	int		iPlayerID[SAMP_MAX_PLAYERS];
	float	fPlayerPos[SAMP_MAX_PLAYERS][3];
};
#pragma pack(pop)

enum RPCEnumeration
{
	RPC_ClickPlayer = 23,
	RPC_ClientJoin = 25,
	RPC_EnterVehicle = 26,
	RPC_EnterEditObject = 27,
	RPC_ScriptCash = 31,
	RPC_ServerCommand = 50,
	RPC_Spawn = 52,
	RPC_Death = 53,
	RPC_NPCJoin = 54,
	RPC_DialogResponse = 62,
	RPC_ClickTextDraw = 83,
	RPC_ScmEvent = 96,
	RPC_WeaponPickupDestroy = 97,
	RPC_Chat = 101,
	RPC_SrvNetStats = 102,
	RPC_ClientCheck = 103,
	RPC_DamageVehicle = 106,
	RPC_GiveTakeDamage = 115,
	RPC_EditAttachedObject = 116,
	RPC_EditObject = 117,
	RPC_SetInteriorId = 118,
	RPC_MapMarker = 119,
	RPC_RequestClass = 128,
	RPC_RequestSpawn = 129,
	RPC_PickedUpPickup = 131,
	RPC_MenuSelect = 132,
	RPC_VehicleDestroyed = 136,
	RPC_MenuQuit = 140,
	RPC_ExitVehicle = 154,
	RPC_UpdateScoresPingsIPs = 155
};
enum ScriptRPCEnumeration
{
	RPC_ScrSetPlayerName = 11,
	RPC_ScrSetPlayerPos = 12,
	RPC_ScrSetPlayerPosFindZ = 13,
	RPC_ScrSetPlayerHealth = 14,
	RPC_ScrTogglePlayerControllable = 15,
	RPC_ScrPlaySound = 16,
	RPC_ScrSetPlayerWorldBounds = 17,
	RPC_ScrGivePlayerMoney = 18,
	RPC_ScrSetPlayerFacingAngle = 19,
	RPC_ScrResetPlayerMoney = 20,
	RPC_ScrResetPlayerWeapons = 21,
	RPC_ScrGivePlayerWeapon = 22,
	RPC_ScrSetVehicleParamsEx = 24,
	RPC_ScrCancelEdit = 28,
	RPC_ScrSetPlayerTime = 29,
	RPC_ScrToggleClock = 30,
	RPC_ScrWorldPlayerAdd = 32,
	RPC_ScrSetPlayerShopName = 33,
	RPC_ScrSetPlayerSkillLevel = 34,
	RPC_ScrSetPlayerDrunkLevel = 35,
	RPC_ScrCreate3DTextLabel = 36,
	RPC_ScrDisableCheckpoint = 37,
	RPC_ScrSetRaceCheckpoint = 38,
	RPC_ScrDisableRaceCheckpoint = 39,
	RPC_ScrGameModeRestart = 40,
	RPC_ScrPlayAudioStream = 41,
	RPC_ScrStopAudioStream = 42,
	RPC_ScrRemoveBuildingForPlayer = 43,
	RPC_ScrCreateObject = 44,
	RPC_ScrSetObjectPos = 45,
	RPC_ScrSetObjectRot = 46,
	RPC_ScrDestroyObject = 47,
	RPC_ScrDeathMessage = 55,
	RPC_ScrSetPlayerMapIcon = 56,
	RPC_ScrRemoveVehicleComponent = 57,
	RPC_ScrUpdate3DTextLabel = 58,
	RPC_ScrChatBubble = 59,
	RPC_ScrSomeupdate = 60,
	RPC_ScrShowDialog = 61,
	RPC_ScrDestroyPickup = 63,
	RPC_ScrLinkVehicleToInterior = 65,
	RPC_ScrSetPlayerArmour = 66,
	RPC_ScrSetPlayerArmedWeapon = 67,
	RPC_ScrSetSpawnInfo = 68,
	RPC_ScrSetPlayerTeam = 69,
	RPC_ScrPutPlayerInVehicle = 70,
	RPC_ScrRemovePlayerFromVehicle = 71,
	RPC_ScrSetPlayerColor = 72,
	RPC_ScrDisplayGameText = 73,
	RPC_ScrForceClassSelection = 74,
	RPC_ScrAttachObjectToPlayer = 75,
	RPC_ScrInitMenu = 76,
	RPC_ScrShowMenu = 77,
	RPC_ScrHideMenu = 78,
	RPC_ScrCreateExplosion = 79,
	RPC_ScrShowPlayerNameTagForPlayer = 80,
	RPC_ScrAttachCameraToObject = 81,
	RPC_ScrInterpolateCamera = 82,
	RPC_ScrSetObjectMaterial = 84,
	RPC_ScrGangZoneStopFlash = 85,
	RPC_ScrApplyAnimation = 86,
	RPC_ScrClearAnimations = 87,
	RPC_ScrSetPlayerSpecialAction = 88,
	RPC_ScrSetPlayerFightingStyle = 89,
	RPC_ScrSetPlayerVelocity = 90,
	RPC_ScrSetVehicleVelocity = 91,
	RPC_ScrClientMessage = 93,
	RPC_ScrSetWorldTime = 94,
	RPC_ScrCreatePickup = 95,
	RPC_ScrMoveObject = 99,
	RPC_ScrEnableStuntBonusForPlayer = 104,
	RPC_ScrTextDrawSetString = 105,
	RPC_ScrSetCheckpoint = 107,
	RPC_ScrGangZoneCreate = 108,
	RPC_ScrPlayCrimeReport = 112,
	RPC_ScrSetPlayerAttachedObject = 113,
	RPC_ScrGangZoneDestroy = 120,
	RPC_ScrGangZoneFlash = 121,
	RPC_ScrStopObject = 122,
	RPC_ScrSetNumberPlate = 123,
	RPC_ScrTogglePlayerSpectating = 124,
	RPC_ScrPlayerSpectatePlayer = 126,
	RPC_ScrPlayerSpectateVehicle = 127,
	RPC_ScrSetPlayerWantedLevel = 133,
	RPC_ScrShowTextDraw = 134,
	RPC_ScrTextDrawHideForPlayer = 135,
	RPC_ScrServerJoin = 137,
	RPC_ScrServerQuit = 138,
	RPC_ScrInitGame = 139,
	RPC_ScrRemovePlayerMapIcon = 144,
	RPC_ScrSetPlayerAmmo = 145,
	RPC_ScrSetGravity = 146,
	RPC_ScrSetVehicleHealth = 147,
	RPC_ScrAttachTrailerToVehicle = 148,
	RPC_ScrDetachTrailerFromVehicle = 149,
	RPC_ScrSetWeather = 152,
	RPC_ScrSetPlayerSkin = 153,
	RPC_ScrSetPlayerInterior = 156,
	RPC_ScrSetPlayerCameraPos = 157,
	RPC_ScrSetPlayerCameraLookAt = 158,
	RPC_ScrSetVehiclePos = 159,
	RPC_ScrSetVehicleZAngle = 160,
	RPC_ScrSetVehicleParamsForPlayer = 161,
	RPC_ScrSetCameraBehindPlayer = 162,
	RPC_ScrWorldPlayerRemove = 163,
	RPC_ScrWorldVehicleAdd = 164,
	RPC_ScrWorldVehicleRemove = 165,
	RPC_ScrWorldPlayerDeath = 166
};

namespace SAMP
{
	enum class samp_ver {
		unknown = -1,

		v037r1 = 0,
		v037r2,
		v037r31,
		v037r4,
		v037r51,
		v03dlr1
	};
	std::map<samp_ver, std::string> str_samp_ver
	{
		{ samp_ver::unknown , "unknown" },
		{ samp_ver::v037r1 , "0.3.7-R1" },
		{ samp_ver::v037r2 , "0.3.7-R2" },
		{ samp_ver::v037r31 , "0.3.7-R3-1" },
		{ samp_ver::v037r4 , "0.3.7-R4-2" },
		{ samp_ver::v037r51 , "0.3.7-R5-1" },
		{ samp_ver::v03dlr1 , "0.3DL-R1" }
	};
	samp_ver ver;
	samp_ver GetSAMPVer() {
		static bool     init = false;
		static samp_ver v = samp_ver::unknown;
		if (!init) {
			std::uintptr_t base = API::GetBase();
			auto* ntheader = reinterpret_cast<IMAGE_NT_HEADERS*>(base + reinterpret_cast<IMAGE_DOS_HEADER*>(base)->e_lfanew);
			std::uintptr_t ep = ntheader->OptionalHeader.AddressOfEntryPoint;
			switch (ep) {
			case 0x31DF13: v = samp_ver::v037r1; break;
			case 0x3195DD: v = samp_ver::v037r2; break;
			case 0xCC4D0:  v = samp_ver::v037r31; break;
			case 0xCBCB0:  v = samp_ver::v037r4; break;
			case 0xCBC90:  v = samp_ver::v037r51; break;
			case 0xFDB60:  v = samp_ver::v03dlr1; break;
			default: break;
			}
			init = true;
		}
		return v;
	}

	namespace CallBacks {

		namespace HookedStructs {
			struct stWndProcParams {
				HWND hWnd;
				UINT uMsg;
				WPARAM wParam;
				LPARAM lParam;
			};
			struct stPresentParams {
				IDirect3DDevice9* pDevice;
				CONST RECT* pSrcRect;
				CONST RECT* pDestRect;
				HWND hDestWindow;
				CONST RGNDATA* pDirtyRegion;
			};
			struct stResetParams {
				IDirect3DDevice9* pDevice;
				D3DPRESENT_PARAMETERS* pPresentParams;
			};
			struct stRakClientSend {
				RakClientInterface* _this;
				BitStream* bitStream;
				PacketPriority priority;
				PacketReliability reliability;
				char orderingChannel;
			};
			struct stRakClientRPC {
				RakClientInterface* _this;
				int* uniqueID;
				BitStream* bitStream;
				PacketPriority priority;
				PacketReliability reliability;
				char orderingChannel;
				bool shiftTimestamp;
			};
			struct stRakClientRPCRecv {
				unsigned __int32 rpc_id;
				BitStream* bitStream;
				//std::shared_ptr<RakNet::BitStream> bitStream;
			};
			struct stRakClientRecv {
				unsigned __int8 pktID;
				BitStream* bitStream;
				unsigned __int32 lenght;
			};
		}

		class CCallbackRegister {
		private:
#pragma pack(push, 1)
			struct PlayerID__
			{
				unsigned int binaryAddress;
				unsigned short port;
				PlayerID__& operator = (const PlayerID__& input)
				{
					binaryAddress = input.binaryAddress;
					port = input.port;
					return *this;
				}
				bool operator==(const PlayerID__& right) const;
				bool operator!=(const PlayerID__& right) const;
				bool operator > (const PlayerID__& right) const;
				bool operator < (const PlayerID__& right) const;
			};
			struct NetworkID__
			{
				bool peerToPeer;
				PlayerID__ playerId;
				unsigned short localSystemId;
			};
			struct Packet__
			{
				unsigned __int16 playerIndex;
				PlayerID__ playerId;
				unsigned int length;
				unsigned int bitSize;
				unsigned char* data;
				bool deleteData;
			};
#pragma pack(pop)

			using GameLoop_t = void(__cdecl*)();
			using WndProc_t = LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM);

			using D3DPresent_t = HRESULT(__stdcall*)(IDirect3DDevice9*, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);
			using D3DReset_t = HRESULT(__stdcall*)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);

			using RakClientSend_t = bool(__thiscall*)(RakClientInterface*, BitStream*, PacketPriority, PacketReliability, char);
			using RakClientRPCSend_t = bool(__thiscall*)(RakClientInterface*, int*, BitStream*, PacketPriority, PacketReliability, char, bool);
			using RakPeerHandleRPCPacket_t = bool(__thiscall*)(RakPeerInterface*, const char*, int, PlayerID__);
			using RakPeerReceive_t = Packet__ * (__thiscall*)(RakPeerInterface*);

			//callbacks
			using tWndProc = std::function<LRESULT __stdcall(HookedStructs::stWndProcParams*)>;
			using tGameLoop = std::function<void __stdcall()>;
			using tPresent_ = std::function<HRESULT __stdcall(HookedStructs::stPresentParams*)>;
			using tReset_ = std::function<HRESULT __stdcall(HookedStructs::stResetParams*)>;
			using tRakClientSend_ = std::function<LRESULT __stdcall(HookedStructs::stRakClientSend*)>;
			using tRakClientRPC_ = std::function<LRESULT __stdcall(HookedStructs::stRakClientRPC*)>;
			using tRakClientRPCRecv_ = std::function<LRESULT __stdcall(HookedStructs::stRakClientRPCRecv*)>;
			using tRakPeerRecv_ = std::function<LRESULT __stdcall(HookedStructs::stRakClientRecv*)>;
		public:

			CCallbackRegister(DWORD base) {
				sampBase = base;

				std::uintptr_t samp_rakclient_send_addr{};
				std::uintptr_t samp_rakclient_rpc_send_addr{};
				std::uintptr_t samp_rakpeer_handle_rpc_packet_addr{};
				std::uintptr_t samp_rakpeer_receive{};

				switch (ver)
				{
					case SAMP::samp_ver::v037r1:
					{
						samp_rakclient_send_addr =				0x00307F0U;
						samp_rakclient_rpc_send_addr =			0x0030B30U;
						samp_rakpeer_handle_rpc_packet_addr =	0x00372F0U;
						samp_rakpeer_receive =					0x0031180U;
						break;
					}
					case SAMP::samp_ver::v037r31:
					{
						samp_rakclient_send_addr =				0x0033BA0U;
						samp_rakclient_rpc_send_addr =			0x0033EE0U;
						samp_rakpeer_handle_rpc_packet_addr =	0x003A6A0U;
						samp_rakpeer_receive =					0x0034530U;
						break;
					}
					case SAMP::samp_ver::v037r51:
					{
						samp_rakclient_send_addr =				0x00342E0U;
						samp_rakclient_rpc_send_addr =			0x0034620U;
						samp_rakpeer_handle_rpc_packet_addr =	0x003ADE0U;
						samp_rakpeer_receive =					0x0034C70U;
						break;
					}
				}

				pWndProcHook = std::make_unique<memwrapper::memhook<WndProc_t>>(0x00747EB0U, WndProc_HOOKED);
				pGameLoopHook = std::make_unique<memwrapper::memhook<GameLoop_t>>(0x00748DA3U, GameLoop_HOOKED);
				pD3DPresentHook = std::make_unique<memwrapper::memhook<D3DPresent_t>>(GetDeviceAddress(17), D3DPresent_HOOKED);
				pD3DResetHook = std::make_unique<memwrapper::memhook<D3DReset_t>>(GetDeviceAddress(16), D3DReset_HOOKED);
				pRakClientSendHook = std::make_unique<memwrapper::memhook<RakClientSend_t>>(sampBase + samp_rakclient_send_addr, RakClientSend_HOOKED);
				pRakClientRPCSendHook = std::make_unique<memwrapper::memhook<RakClientRPCSend_t>>(sampBase + samp_rakclient_rpc_send_addr, RakClientRPCSend_HOOKED);
				pRakPeerHandleRPCPacketHook = std::make_unique<memwrapper::memhook<RakPeerHandleRPCPacket_t>>(sampBase + samp_rakpeer_handle_rpc_packet_addr, RakPeerHandleRPCPacketHook_HOOKED);
				pRakPeerReceiveHook = std::make_unique<memwrapper::memhook<RakPeerReceive_t>>(sampBase + samp_rakpeer_receive, RakPeerReceive_HOOKED);

				pWndProcHook->install();
				pGameLoopHook->install();
				pD3DPresentHook->install();
				pD3DResetHook->install();
				pRakClientSendHook->install();
				pRakPeerReceiveHook->install();
				pRakClientRPCSendHook->install();
				pRakPeerHandleRPCPacketHook->install();
			}

			~CCallbackRegister() {
				pWndProcHook->remove();
				pGameLoopHook->remove();
				pD3DPresentHook->remove();
				pD3DResetHook->remove();
				pRakClientSendHook->remove();
				pRakPeerReceiveHook->remove();
				pRakClientRPCSendHook->remove();
				pRakPeerHandleRPCPacketHook->remove();
			}

			auto inline operator+=(tWndProc func) -> void {
				vecWndProcCallback.push_back(func);
			};
			auto inline operator+=(tGameLoop func) -> void {
				vecGameLoopCallback.push_back(func);
			};
			auto inline operator+=(tPresent_ func) -> void {
				vecPresentCallback.push_back(func);
			};
			auto inline operator+=(tReset_ func) -> void {
				vecResetCallback.push_back(func);
			};
			auto inline operator+=(tRakClientSend_ func) -> void {
				vecRakClientSendCallback.push_back(func);
			};
			auto inline operator+=(tRakClientRPC_ func) -> void {
				vecRakClientRPCCallback.push_back(func);
			};
			auto inline operator+=(tRakClientRPCRecv_ func) -> void {
				vecRakClientRPCRecvCallback.push_back(func);
			};
			auto inline operator+=(tRakPeerRecv_ func) -> void {
				vecRakPeerRecvCallback.push_back(func);
			};

			void inline RegisterWndProcCallback(tWndProc func) { vecWndProcCallback.push_back(func); };
			void inline RegisterGameLoopCallback(tGameLoop func) { vecGameLoopCallback.push_back(func); };

			void inline RegisterD3DCallback(tPresent_ func) { vecPresentCallback.push_back(func); };
			void inline RegisterD3DCallback(tReset_ func) { vecResetCallback.push_back(func); };

			void inline RegisterRakClientCallback(tRakClientSend_ func) { vecRakClientSendCallback.push_back(func); };
			void inline RegisterRakClientCallback(tRakClientRPC_ func) { vecRakClientRPCCallback.push_back(func); };
			void inline RegisterRakClientCallback(tRakClientRPCRecv_ func) { vecRakClientRPCRecvCallback.push_back(func); };
			void inline RegisterRakClientCallback(tRakPeerRecv_ func) { vecRakPeerRecvCallback.push_back(func); };

			IDirect3DDevice9 inline* GetIDirect3DDevice9(void) { return pD3DDevice; };

			auto inline GetHookObject(void) {
				return pRakPeerHandleRPCPacketHook.get();
			}
		private:
			std::unique_ptr<memwrapper::memhook<GameLoop_t>> pGameLoopHook = 0;
			std::unique_ptr<memwrapper::memhook<WndProc_t>> pWndProcHook = 0;

			std::unique_ptr<memwrapper::memhook<D3DPresent_t>> pD3DPresentHook = 0;
			std::unique_ptr<memwrapper::memhook<D3DReset_t>> pD3DResetHook = 0;

			std::unique_ptr<memwrapper::memhook<RakClientSend_t>> pRakClientSendHook = 0;
			std::unique_ptr<memwrapper::memhook<RakClientRPCSend_t>> pRakClientRPCSendHook = 0;
			std::unique_ptr<memwrapper::memhook<RakPeerHandleRPCPacket_t>> pRakPeerHandleRPCPacketHook = 0;
			std::unique_ptr<memwrapper::memhook<RakPeerReceive_t>> pRakPeerReceiveHook = 0;

			IDirect3DDevice9* pD3DDevice = nullptr;
			bool isD3DHookInit = false;

			DWORD sampBase = 0;

			std::vector<tWndProc> vecWndProcCallback;
			std::vector<tGameLoop> vecGameLoopCallback;
			std::vector<tPresent_> vecPresentCallback;
			std::vector<tReset_> vecResetCallback;
			std::vector<tRakClientSend_> vecRakClientSendCallback;
			std::vector<tRakClientRPC_> vecRakClientRPCCallback;
			std::vector<tRakClientRPCRecv_> vecRakClientRPCRecvCallback;
			std::vector<tRakPeerRecv_> vecRakPeerRecvCallback;

			static LRESULT __stdcall WndProc_HOOKED(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
			static void __cdecl GameLoop_HOOKED();
			static HRESULT __stdcall D3DPresent_HOOKED(IDirect3DDevice9* pDevice, CONST RECT* pSrcRect, CONST RECT* pDestRect, HWND hDestWindow, CONST RGNDATA* pDirtyRegion);
			static HRESULT __stdcall D3DReset_HOOKED(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentParams);
			static bool __fastcall RakClientSend_HOOKED(RakClientInterface* _this, void* Unknown, BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel);
			static bool __fastcall RakClientRPCSend_HOOKED(RakClientInterface* _this, void* Unknown, int* uniqueID, BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, bool shiftTimestamp);
			static bool __fastcall RakPeerHandleRPCPacketHook_HOOKED(RakPeerInterface* _this, void* Unknown, const char* data, int length, SAMP::CallBacks::CCallbackRegister::PlayerID__ playerid);
			static SAMP::CallBacks::CCallbackRegister::Packet__* __fastcall RakPeerReceive_HOOKED(RakPeerInterface* _this, void* Unknown);

			template<typename result, typename source>
			result pointer_cast(source* v)
			{
				return static_cast<result>(static_cast<void*>(v));
			}
			template<typename result, typename source>
			result pointer_cast(const source* v)
			{
				return static_cast<result>(static_cast<const void*>(v));
			}

			DWORD FindDevice(DWORD dwLen)
			{
				DWORD dwObjBase = 0;
				char infoBuf[MAX_PATH];
				GetSystemDirectoryA(infoBuf, MAX_PATH);
				strcat_s(infoBuf, MAX_PATH, "\\d3d9.dll");
				dwObjBase = (DWORD)LoadLibraryA(infoBuf);
				while (dwObjBase++ < dwObjBase + dwLen)
				{
					if (
						(*(WORD*)(dwObjBase + 0x00)) == 0x06C7 &&
						(*(WORD*)(dwObjBase + 0x06)) == 0x8689 &&
						(*(WORD*)(dwObjBase + 0x0C)) == 0x8689
						)
					{
						dwObjBase += 2; break;
					}
				}
				return(dwObjBase);
			};
			DWORD GetDeviceAddress(int VTableIndex)
			{
				PDWORD VTable;
				*(DWORD*)&VTable = *(DWORD*)FindDevice(0x128000);
				return VTable[VTableIndex];
			};
		};

		CCallbackRegister* pCallBackRegister = nullptr;
	}

	class CRakNet
	{
	private:
		RakClientInterface* pRakClientInterface = nullptr;
		RakPeerInterface* pRakPeerInterface = nullptr;
#pragma pack(push, 1)
		struct PlayerID__
		{
			unsigned int binaryAddress;
			unsigned short port;
			PlayerID__& operator = (const PlayerID__& input)
			{
				binaryAddress = input.binaryAddress;
				port = input.port;
				return *this;
			}
			bool operator==(const PlayerID__& right) const;
			bool operator!=(const PlayerID__& right) const;
			bool operator > (const PlayerID__& right) const;
			bool operator < (const PlayerID__& right) const;
		};
		struct NetworkID__
		{
			bool peerToPeer;
			PlayerID__ playerId;
			unsigned short localSystemId;
		};
		struct Packet__
		{
			unsigned __int16 playerIndex;
			PlayerID__ playerId;
			unsigned int length;
			unsigned int bitSize;
			unsigned char* data;
			bool deleteData;
		};
#pragma pack(pop)
		unsigned __int32 sampBase = 0;
		RakPeerInterface* pRakPeerInterface1;
		PlayerID__ plID1;
	public:

		CRakNet(RakClientInterface* _interface, RakPeerInterface* _rinterface) {
			this->pRakClientInterface = _interface;
			this->pRakPeerInterface = _rinterface;
			sampBase = API::GetBase();
		}
		~CRakNet() {
			this->pRakClientInterface = nullptr;
			this->pRakPeerInterface = nullptr;
			this->pRakPeerInterface1 = nullptr;
		}
		//DONT CALL THIS FUNCTION!!!
		void InitAPIRakNet(RakPeerInterface* pRak, void* plID) {
			pRakPeerInterface1 = pRak;
			plID1 = *(PlayerID__*)plID;
		};
		RakClientInterface* GetRakClientInterface(void) {
			return this->pRakClientInterface;
		}
		RakPeerInterface* GetRakPeerInterface(void) {
			return this->pRakPeerInterface;
		}
		bool Send(RakNet::BitStream* bitStream, PacketPriority priority = HIGH_PRIORITY, PacketReliability reliability = PacketReliability::RELIABLE_ORDERED, char orderingChannel = '\0') {
			return this->pRakClientInterface->Send(bitStream, priority, reliability, orderingChannel);
		};
		bool Send(const char* data, const int length, PacketPriority priority = HIGH_PRIORITY, PacketReliability reliability = PacketReliability::RELIABLE_ORDERED, char orderingChannel = '\0') {
			return this->pRakClientInterface->Send(data, length, priority, reliability, orderingChannel);
		};
		bool SendRPC(int RPC_ID, RakNet::BitStream* bitStream, PacketPriority priority = HIGH_PRIORITY, PacketReliability reliability = PacketReliability::RELIABLE_ORDERED, char orderingChannel = '\0', bool shiftTimestamp = false, NetworkID networkID = UNASSIGNED_NETWORK_ID, RakNet::BitStream* replyFromTarget = 0) {
			return this->pRakClientInterface->RPC(&RPC_ID, bitStream, priority, reliability, orderingChannel, shiftTimestamp, networkID, replyFromTarget);
		}
		bool SendRPC(int RPC_ID, const char* data, unsigned int bitLength, PacketPriority priority = HIGH_PRIORITY, PacketReliability reliability = PacketReliability::RELIABLE_ORDERED, char orderingChannel = '\0', bool shiftTimestamp = false, NetworkID networkID = UNASSIGNED_NETWORK_ID, RakNet::BitStream* replyFromTarget = 0) {
			return this->pRakClientInterface->RPC(&RPC_ID, data, bitLength, priority, reliability, orderingChannel, shiftTimestamp, networkID, replyFromTarget);
		};
		bool EmulRPC(unsigned __int8 rpcID, RakNet::BitStream* bitStream) {
			RakNet::BitStream bs_;
			bs_.Write<unsigned char>(ID_RPC);
			bs_.Write(rpcID);
			bs_.WriteCompressed<unsigned int>(BYTES_TO_BITS(bitStream->GetNumberOfBytesUsed()));
			bs_.WriteBits(bitStream->GetData(), BYTES_TO_BITS(bitStream->GetNumberOfBytesUsed()), false);

			return SAMP::CallBacks::pCallBackRegister->GetHookObject()->call<RakPeerInterface*, const char*, int, PlayerID__>(pRakPeerInterface1, reinterpret_cast<char*>(bs_.GetData()), bs_.GetNumberOfBytesUsed(), plID1);
		};
		bool EmulPacket(RakNet::BitStream* bitStream) {
			std::uintptr_t alloc_packet_addr{};
			std::uintptr_t write_lock_addr{};
			std::uintptr_t write_unlock_addr{};

			if (alloc_packet_addr == 0) 
			{
				switch (ver)
				{
					case SAMP::samp_ver::v037r1:
					{
						alloc_packet_addr =		0x347E0;
						write_lock_addr =		0x35B10;
						write_unlock_addr =		0x35B50;
						break;
					}
					case SAMP::samp_ver::v037r31:
					{
						alloc_packet_addr =		0x37B90;
						write_lock_addr =		0x38EC0;
						write_unlock_addr =		0x38F00;
						break;
					}
					case SAMP::samp_ver::v037r51:
					{
						alloc_packet_addr =		0x382D0;
						write_lock_addr =		0x39600;
						write_unlock_addr =		0x39640;
						break;
					}
				}
			}

			Packet__* send_packet = reinterpret_cast<Packet__ * (*)(size_t)>(sampBase + alloc_packet_addr)(bitStream->GetNumberOfBytesUsed());
			memcpy(send_packet->data, bitStream->GetData(), send_packet->length);

			// RakPeer::AddPacketToProducer
			char* packets = reinterpret_cast<char*>(pRakPeerInterface) + 0xdb6;
			auto write_lock = reinterpret_cast<Packet__ * *(__thiscall*)(void*)>(sampBase + write_lock_addr);
			auto write_unlock = reinterpret_cast<void(__thiscall*)(void*)>(sampBase + write_unlock_addr);

			*write_lock(packets) = send_packet;
			write_unlock(packets);

			return true;
		};
	};

	class CSAMP {
	public:
		bool LoadAPI(void) {//init api
			switch (ver)
			{
				case SAMP::samp_ver::v037r1:
				{
					if (API::v037r1::RefChat() == nullptr)
						return false;

					if (API::v037r1::RefDeathWindow() == nullptr)
						return false;

					if (API::v037r1::RefDialog() == nullptr)
						return false;

					if (API::v037r1::RefGame() == nullptr)
						return false;

					if (API::v037r1::RefInputBox() == nullptr)
						return false;

					if (API::v037r1::RefNetGame() == nullptr)
						return false;

					if (API::v037r1::RefScoreboard() == nullptr)
						return false;

					if (API::v037r1::RefNetGame()->m_pRakClient == nullptr)
						return false;

					g_RakNet = new CRakNet(API::v037r1::RefNetGame()->m_pRakClient, (RakPeerInterface*)API::v037r1::RefNetGame()->pad_0[0]);

					break;
				}
				case SAMP::samp_ver::v037r31:
				{
					if (API::v037r3::RefChat() == nullptr)
						return false;

					if (API::v037r3::RefDeathWindow() == nullptr)
						return false;

					if (API::v037r3::RefDialog() == nullptr)
						return false;

					if (API::v037r3::RefGame() == nullptr)
						return false;

					if (API::v037r3::RefInputBox() == nullptr)
						return false;

					if (API::v037r3::RefNetGame() == nullptr)
						return false;

					if (API::v037r3::RefScoreboard() == nullptr)
						return false;

					if (API::v037r3::RefNetGame()->m_pRakClient == nullptr)
						return false;

					g_RakNet = new CRakNet(API::v037r3::RefNetGame()->m_pRakClient, (RakPeerInterface*)API::v037r3::RefNetGame()->pad_0[0]);

					break;
				}
				case SAMP::samp_ver::v037r51:
				{
					if (API::v037r5::RefChat() == nullptr)
						return false;

					if (API::v037r5::RefDeathWindow() == nullptr)
						return false;

					if (API::v037r5::RefDialog() == nullptr)
						return false;

					if (API::v037r5::RefGame() == nullptr)
						return false;

					if (API::v037r5::RefInputBox() == nullptr)
						return false;

					if (API::v037r5::RefNetGame() == nullptr)
						return false;

					if (API::v037r5::RefScoreboard() == nullptr)
						return false;

					if (API::v037r5::RefNetGame()->m_pRakClient == nullptr)
						return false;

					g_RakNet = new CRakNet(API::v037r5::RefNetGame()->m_pRakClient, (RakPeerInterface*)((char*)API::v037r5::RefNetGame()->m_pRakClient - 0xDDE));

					break;
				}
			}
			return true;
		};

		auto getPlayers(void) { return g_pAPIPlayerPool; };
		auto getVehicles(void) { return g_pAPIVehiclePool; };
		auto getStreamedOutPlayerInfo(void) { return g_StreamedOutPlayerInfo; };
		auto getMisc(void) { return g_pMisc; };

		CRakNet* getRakNet(void) { return g_RakNet; };

		void addMessageToChat(D3DCOLOR cColor, char* szMsg, ...) {
			if (szMsg == NULL)
				return;

			va_list ap;
			char tmp[512];
			memset(tmp, 0, 512);
			va_start(ap, szMsg);
			vsnprintf(tmp, sizeof(tmp) - 1, szMsg, ap);
			va_end(ap);

			switch (ver)
			{
			case SAMP::samp_ver::v037r1:
				API::v037r1::RefChat()->AddEntry(8, tmp, NULL, cColor, 0x00);
				break;
			case SAMP::samp_ver::v037r31:
				API::v037r3::RefChat()->AddEntry(8, tmp, NULL, cColor, 0x00);
				break;
			case SAMP::samp_ver::v037r51:
				API::v037r5::RefChat()->AddEntry(8, tmp, NULL, cColor, 0x00);
				break;
			}
		};
		void addClientCommand(char* szCmd, API::CMDPROC pFunc)
		{
			if (szCmd == NULL)
				return;

			switch (ver)
			{
			case SAMP::samp_ver::v037r1:
				API::v037r1::RefInputBox()->AddCommand(szCmd, pFunc);
				break;
			case SAMP::samp_ver::v037r31:
				API::v037r3::RefInputBox()->AddCommand(szCmd, pFunc);
				break;
			case SAMP::samp_ver::v037r51:
				API::v037r5::RefInputBox()->AddCommand(szCmd, pFunc);
				break;
			}
		}
		void unregisterChatCommand(void* func) {

			switch (ver)
			{
				case SAMP::samp_ver::v037r1:
				{
					for (int i = 0; i < 144; i++) {
						if (API::v037r1::RefInputBox()->m_pCommandProc[i] == func) {
							memset(&API::v037r1::RefInputBox()->m_pCommandProc[i], 0, 4);
							memset(API::v037r1::RefInputBox()->m_szCommandName[i], 0, 33);
							memset(&API::v037r1::RefInputBox()->m_szCommandName[i], 0, 4);
						}
					}
					break;
				}
				case SAMP::samp_ver::v037r31:
				{
					for (int i = 0; i < 144; i++) {
						if (API::v037r3::RefInputBox()->m_commandProc[i] == func) {
							memset(&API::v037r3::RefInputBox()->m_commandProc[i], 0, 4);
							memset(API::v037r3::RefInputBox()->m_szCommandName[i], 0, 33);
							memset(&API::v037r3::RefInputBox()->m_szCommandName[i], 0, 4);
						}
					}
					break;
				}
				case SAMP::samp_ver::v037r51:
				{
					for (int i = 0; i < 144; i++) {
						if (API::v037r5::RefInputBox()->m_commandProc[i] == func) {
							memset(&API::v037r5::RefInputBox()->m_commandProc[i], 0, 4);
							memset(API::v037r5::RefInputBox()->m_szCommandName[i], 0, 33);
							memset(&API::v037r5::RefInputBox()->m_szCommandName[i], 0, 4);
						}
					}
					break;
				}
			}
		}

		~CSAMP() {
			delete g_StreamedOutPlayerInfo;
			g_StreamedOutPlayerInfo = nullptr;
			delete g_RakNet;
			g_RakNet = nullptr;
			delete g_pAPIPlayerPool;
			g_pAPIPlayerPool = nullptr;
			delete g_pAPIVehiclePool;
			g_pAPIVehiclePool = nullptr;
			delete g_pMisc;
			g_pMisc = nullptr;
		};
		CSAMP(std::uintptr_t base)
		{ 
			sampAddr = base; 
			g_StreamedOutPlayerInfo = new stStreamedOutPlayerInfo;
			g_pAPIPlayerPool = new stAPIPlayerPool;
			g_pAPIVehiclePool = new stAPIVehiclePool;
			g_pMisc = new stMISC;
		};
		std::uintptr_t GetBase() { return sampAddr; };
	private:
		struct stMISC
		{
			void EnableCursor() {
				switch (SAMP::ver)
				{
					case SAMP::samp_ver::v037r1: {
						SAMP::API::v037r1::RefInputBox()->EnableCursor();
						break;
					}
					case SAMP::samp_ver::v037r31: {
						SAMP::API::v037r3::RefInputBox()->EnableCursor();
						break;
					}
					case SAMP::samp_ver::v037r51: {
						SAMP::API::v037r5::RefInputBox()->EnableCursor();
						break;
					}
				}
			};
			void SetCursorMode(int nMode, SAMP::API::BOOL bImmediatelyHideCursor) {
				switch (SAMP::ver)
				{
					case SAMP::samp_ver::v037r1:
					{
						SAMP::API::v037r1::RefGame()->SetCursorMode(nMode, bImmediatelyHideCursor);
						break;
					}
					case SAMP::samp_ver::v037r31:
					{
						SAMP::API::v037r3::RefGame()->SetCursorMode(nMode, bImmediatelyHideCursor);
						break;
					}
					case SAMP::samp_ver::v037r51:
					{
						SAMP::API::v037r5::RefGame()->SetCursorMode(nMode, bImmediatelyHideCursor);
						break;
					}
				}
			};
			
			
		} *g_pMisc;
		struct stAPIPlayerPool {
			CPed* GetCPedFromSAMPPlayerID(std::uint16_t playerID) {
				if (playerID > SAMP_MAX_PLAYERS)
					return nullptr;

				switch (SAMP::ver)
				{
					case SAMP::samp_ver::v037r1: 
					{
						if (playerID == SAMP::API::v037r1::RefNetGame()->m_pPools->m_pPlayer->m_localInfo.m_nId)
							return SAMP::API::v037r1::RefNetGame()->m_pPools->m_pPlayer->m_localInfo.m_pObject->m_pPed->m_pGamePed;
						else 
							return SAMP::API::v037r1::RefNetGame()->m_pPools->m_pPlayer->m_pObject[playerID]->m_pPlayer->m_pPed->m_pGamePed;
					}
					case SAMP::samp_ver::v037r31: 
					{
						if (playerID == SAMP::API::v037r3::RefNetGame()->m_pPools->m_pPlayer->m_localInfo.m_nId)
							return SAMP::API::v037r3::RefNetGame()->m_pPools->m_pPlayer->m_localInfo.m_pObject->m_pPed->m_pGamePed;
						else 
							return SAMP::API::v037r3::RefNetGame()->m_pPools->m_pPlayer->m_pObject[playerID]->m_pPlayer->m_pPed->m_pGamePed;
					}
					case SAMP::samp_ver::v037r51: 
					{
						if (playerID == SAMP::API::v037r5::RefNetGame()->m_pPools->m_pPlayer->m_localInfo.m_nId)
							return SAMP::API::v037r5::RefNetGame()->m_pPools->m_pPlayer->m_localInfo.m_pObject->m_pPed->m_pGamePed;
						else 
							return SAMP::API::v037r5::RefNetGame()->m_pPools->m_pPlayer->m_pObject[playerID]->m_pPlayer->m_pPed->m_pGamePed;
					}
				}
				return nullptr;
			}
			std::uint16_t GetSAMPPlayerIDFromCPed(CPed* pPed) {
				if (pPed == nullptr)
					return -1;

				switch (SAMP::ver)
				{
					case SAMP::samp_ver::v037r1:
					{
						return SAMP::API::v037r1::RefNetGame()->m_pPools->m_pPlayer->Find(pPed);
					}
					case SAMP::samp_ver::v037r31:
					{
						return SAMP::API::v037r3::RefNetGame()->m_pPools->m_pPlayer->Find(pPed);
					}
					case SAMP::samp_ver::v037r51:
					{
						return SAMP::API::v037r5::RefNetGame()->m_pPools->m_pPlayer->Find(pPed);
					}
				}

				return -1;
			}
			bool IsPlayerStreamed(std::uint16_t playerID) {
				switch (SAMP::ver)
				{
					case SAMP::samp_ver::v037r1: 
					{
						auto pPlayer = SAMP::API::v037r1::RefNetGame()->m_pPools->m_pPlayer;

						if (pPlayer == NULL)
							return false;
						if (pPlayer->m_pObject[playerID] == NULL)
							return false;
						if (pPlayer->m_pObject[playerID]->m_pPlayer == NULL)
							return false;
						if (pPlayer->m_pObject[playerID]->m_pPlayer->m_pPed == NULL)
							return false;

						return true;
					}
					case SAMP::samp_ver::v037r31: {
						auto pPlayer = SAMP::API::v037r3::RefNetGame()->m_pPools->m_pPlayer;

						if (pPlayer == NULL)
							return false;
						if (pPlayer->m_pObject[playerID] == NULL)
							return false;
						if (pPlayer->m_pObject[playerID]->m_pPlayer == NULL)
							return false;
						if (pPlayer->m_pObject[playerID]->m_pPlayer->m_pPed == NULL)
							return false;

						return true;
					}
					case SAMP::samp_ver::v037r51: {
						auto pPlayer = SAMP::API::v037r5::RefNetGame()->m_pPools->m_pPlayer;

						if (pPlayer == NULL)
							return false;
						if (pPlayer->m_pObject[playerID] == NULL)
							return false;
						if (pPlayer->m_pObject[playerID]->m_pPlayer == NULL)
							return false;
						if (pPlayer->m_pObject[playerID]->m_pPlayer->m_pPed == NULL)
							return false;

						return true;
					}
				}
				return false;
			}
			D3DCOLOR GetPlayerColor(std::uint16_t playerID) {
				switch (SAMP::GetSAMPVer())
				{
					case SAMP::samp_ver::v037r1: {
						auto color = SAMP::API::v037r1::RefNetGame()->m_pPools->m_pPlayer->m_pObject[playerID]->m_pPlayer->GetColorAsRGBA();
						return D3DCOLOR_RGBA(color >> 8, color >> 16, color >> 24, 255);
					}
					case SAMP::samp_ver::v037r31: {
						auto color = SAMP::API::v037r3::RefNetGame()->m_pPools->m_pPlayer->m_pObject[playerID]->m_pPlayer->GetColorAsRGBA();
						return D3DCOLOR_RGBA(color >> 8, color >> 16, color >> 24, 255);
					}
					case SAMP::samp_ver::v037r51: {
						auto color = SAMP::API::v037r5::RefNetGame()->m_pPools->m_pPlayer->m_pObject[playerID]->m_pPlayer->GetColorAsRGBA();
						return D3DCOLOR_RGBA(color >> 8, color >> 16, color >> 24, 255);
					}
				}
				return 0;
			}
			const char* GetPlayerName(std::uint16_t playerID)
			{
				if (playerID > SAMP_MAX_PLAYERS)
					return nullptr;

				switch (SAMP::GetSAMPVer())
				{
					case SAMP::samp_ver::v037r1: {
						return SAMP::API::v037r1::RefNetGame()->m_pPools->m_pPlayer->GetName(playerID);
					}
					case SAMP::samp_ver::v037r31: {
						return SAMP::API::v037r3::RefNetGame()->m_pPools->m_pPlayer->GetName(playerID);
					}
					case SAMP::samp_ver::v037r51: {
						return SAMP::API::v037r5::RefNetGame()->m_pPools->m_pPlayer->GetName(playerID);
					}
				}
				return nullptr;
			}
		} *g_pAPIPlayerPool;
		struct stAPIVehiclePool {
			CVehicle* GetCVehicleFromSAMPVehicleID(std::uint16_t vehicleID) {
				if (vehicleID > SAMP_MAX_VEHICLES)
					return nullptr;

				switch (SAMP::ver)
				{
					case SAMP::samp_ver::v037r1: {
						return SAMP::API::v037r1::RefNetGame()->m_pPools->m_pVehicle->m_pGameObject[vehicleID];
						break;
					}
					case SAMP::samp_ver::v037r31: {
						return SAMP::API::v037r3::RefNetGame()->m_pPools->m_pVehicle->m_pGameObject[vehicleID];
						break;
					}
					case SAMP::samp_ver::v037r51: {
						return SAMP::API::v037r5::RefNetGame()->m_pPools->m_pVehicle->m_pGameObject[vehicleID];
						break;
					}
				}

				return nullptr;
			};
			std::uint16_t GetSAMPVehicleIDFromCVehicle(CVehicle* pVeh) {
				if (pVeh == nullptr)
					return -1;

				switch (SAMP::ver)
				{
					case SAMP::samp_ver::v037r1:
					{
						return SAMP::API::v037r1::RefNetGame()->m_pPools->m_pVehicle->Find(pVeh);
					}
					case SAMP::samp_ver::v037r31:
					{
						return SAMP::API::v037r3::RefNetGame()->m_pPools->m_pVehicle->Find(pVeh);
					}
					case SAMP::samp_ver::v037r51:
					{
						return SAMP::API::v037r5::RefNetGame()->m_pPools->m_pVehicle->Find(pVeh);
					}
				}

				return -1;
			};
			bool IsVehicleStreamed(std::uint16_t vehicleID) {
				switch (SAMP::GetSAMPVer())
				{
					case SAMP::samp_ver::v037r1: {
						auto pVehicle = SAMP::API::v037r1::RefNetGame()->m_pPools->m_pVehicle;

						if (pVehicle->m_bNotEmpty[vehicleID] != 1)
							return false;
						if (pVehicle->m_pObject[vehicleID] == NULL)
							return false;
						if (pVehicle->m_pObject[vehicleID]->m_pGameVehicle == NULL)
							return false;

						return true;
					}
					case SAMP::samp_ver::v037r31: {
						auto pVehicle = SAMP::API::v037r3::RefNetGame()->m_pPools->m_pVehicle;

						if (pVehicle->m_bNotEmpty[vehicleID] != 1)
							return false;
						if (pVehicle->m_pObject[vehicleID] == NULL)
							return false;
						if (pVehicle->m_pObject[vehicleID]->m_pGameVehicle == NULL)
							return false;
						
						return true;
					}
					case SAMP::samp_ver::v037r51: {
						auto pVehicle = SAMP::API::v037r5::RefNetGame()->m_pPools->m_pVehicle;

						if (pVehicle->m_bNotEmpty[vehicleID] != 1)
							return false;
						if (pVehicle->m_pObject[vehicleID] == NULL)
							return false;
						if (pVehicle->m_pObject[vehicleID]->m_pGameVehicle == NULL)
							return false;
						
						return true;
					}
				}
				return false;
			};
		} *g_pAPIVehiclePool;

		std::uintptr_t sampAddr = 0;
		struct stStreamedOutPlayerInfo* g_StreamedOutPlayerInfo = 0;
		class CRakNet* g_RakNet = 0;

	};

	CSAMP* pSAMP = nullptr;

	void ShutDown(void) {
		delete SAMP::CallBacks::pCallBackRegister;
		delete SAMP::pSAMP;
		SAMP::CallBacks::pCallBackRegister = nullptr;
		SAMP::pSAMP = nullptr;
	}

	void Init(void) {
		ver = GetSAMPVer();
		DWORD base = API::GetBase();
		SAMP::pSAMP = new SAMP::CSAMP(base);
		SAMP::CallBacks::pCallBackRegister = new SAMP::CallBacks::CCallbackRegister(base);
	}

	bool bKeyTable[256];
#pragma warning(disable:6282)
	bool isKeyDown(uint8_t key) {
		return bKeyTable[key];
	}
	bool isKeyPressed(uint8_t key) {
		static bool bPressed[0xFF];
		if (bKeyTable[key]) {
			if (!bPressed[key])
				return bPressed[key] = true;
		}
		else bPressed[key] = false;

		return false;
	}
	bool isKeyReleased(uint8_t vkey) {
		static bool bPressed[0xFF];
		if (!bKeyTable[vkey]) {
			if (bPressed[vkey])
				return !(bPressed[vkey] = false);
		}
		else bPressed[vkey] = true;

		return false;
	}
#pragma warning(default:6282)
}

SAMP::CallBacks::CCallbackRegister::Packet__* __fastcall SAMP::CallBacks::CCallbackRegister::RakPeerReceive_HOOKED(RakPeerInterface* _this, void* Unknown) {
	SAMP::CallBacks::CCallbackRegister::Packet__* packet = SAMP::CallBacks::pCallBackRegister->pRakPeerReceiveHook->call<RakPeerInterface*>(_this);

	if (packet != nullptr && packet->data != nullptr && packet->bitSize != 0 && packet->length != 0)
	{
		if (packet->data[0] == ID_MARKERS_SYNC) // packetId
		{
			BitStream	bs(packet->data, packet->length, true);
			int			iNumberOfPlayers = 0;
			uint16_t	playerID = uint16_t(-1);
			short		sPos[3] = { 0, 0, 0 };
			bool		bIsPlayerActive = false;

			bs.IgnoreBits(8);
			bs.Read(iNumberOfPlayers);
			if (iNumberOfPlayers >= 0 || iNumberOfPlayers <= SAMP_MAX_PLAYERS) {
				for (int i = 0; i < iNumberOfPlayers; i++)
				{
					bs.Read(playerID);
					bs.ReadCompressed(bIsPlayerActive);
					if (bIsPlayerActive == 0)
						continue;

					bs.Read(sPos);
					SAMP::pSAMP->getStreamedOutPlayerInfo()->iPlayerID[playerID] = playerID;
					SAMP::pSAMP->getStreamedOutPlayerInfo()->fPlayerPos[playerID][0] = sPos[0];
					SAMP::pSAMP->getStreamedOutPlayerInfo()->fPlayerPos[playerID][1] = sPos[1];
					SAMP::pSAMP->getStreamedOutPlayerInfo()->fPlayerPos[playerID][2] = sPos[2];
				}
			}
		}

		if (!SAMP::CallBacks::pCallBackRegister->vecRakPeerRecvCallback.empty()) {
			HookedStructs::stRakClientRecv params = { 0 };
			BitStream* bs = new BitStream(packet->data, packet->length, true);
			params.bitStream = bs;
			params.lenght = packet->length;
			params.pktID = packet->data[0];
			bool retn;
			for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecRakPeerRecvCallback.size(); i++) {
				retn = SAMP::CallBacks::pCallBackRegister->vecRakPeerRecvCallback[i](&params);
				if (!retn) {
					delete bs;
					//return nullptr;
					//_this->DeallocatePacket((Packet*)packet);
					memset(packet->data, 0, packet->length);
					packet->data[0] = 0xFF;
					return packet;
				}
			}
			//bool retn = SAMP::CallBacks::pCallBackRegister->callRakPeerRecv(&params);
			packet->data = bs->GetData();
			packet->bitSize = bs->GetNumberOfBitsUsed();
			packet->length = bs->GetNumberOfBytesUsed();
			delete bs;
			//if (!retn)
			//	return nullptr;
		}
	}

	return packet;
}
bool __fastcall SAMP::CallBacks::CCallbackRegister::RakPeerHandleRPCPacketHook_HOOKED(RakPeerInterface* _this, void* Unknown, const char* data, int length, SAMP::CallBacks::CCallbackRegister::PlayerID__ playerid) {
	RakNet::BitStream incoming(SAMP::CallBacks::pCallBackRegister->pointer_cast<unsigned char*>(const_cast<char*>(data)), length, true);//from rakhook by imring
	unsigned char id = 0;
	unsigned char* input = nullptr;
	unsigned int bits_data = 0;
	std::unique_ptr<RakNet::BitStream> callback_bs = std::make_unique<RakNet::BitStream>();

	static bool isInitInterface = false;
	if (!isInitInterface) {
		if (SAMP::pSAMP->getRakNet() != nullptr) {
			SAMP::pSAMP->getRakNet()->InitAPIRakNet(_this, (void*)&playerid);
			isInitInterface = true;
		}
		else return SAMP::CallBacks::pCallBackRegister->pRakPeerHandleRPCPacketHook->call<RakPeerInterface*, const char*, int, PlayerID__>(_this, data, length, playerid);
	}

	incoming.IgnoreBits(8);
	if (data[0] == ID_TIMESTAMP)
		incoming.IgnoreBits(8 * (sizeof(RakNetTime) + sizeof(unsigned char)));

	int offset = incoming.GetReadOffset();
	incoming.Read(id);

	if (!incoming.ReadCompressed(bits_data))
		return false;

	if (bits_data) {
		bool used_alloca = false;
		if (BITS_TO_BYTES(incoming.GetNumberOfUnreadBits()) < MAX_ALLOCA_STACK_ALLOCATION) {
			input = SAMP::CallBacks::pCallBackRegister->pointer_cast<unsigned char*>(_malloca(BITS_TO_BYTES(incoming.GetNumberOfUnreadBits())));
			used_alloca = true;
		}
		else input = new unsigned char[BITS_TO_BYTES(incoming.GetNumberOfUnreadBits())];

		if (!incoming.ReadBits(input, bits_data, false))
			return false;

		callback_bs = std::make_unique<RakNet::BitStream>(input, BITS_TO_BYTES(bits_data), true);

		if (!used_alloca)
			delete[] input;
	}

	if (!SAMP::CallBacks::pCallBackRegister->vecRakClientRPCRecvCallback.empty()) {
		HookedStructs::stRakClientRPCRecv params = { 0 };
		params.bitStream = callback_bs.get();
		params.rpc_id = id;
		bool retn;
		for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecRakClientRPCRecvCallback.size(); i++) {
			retn = SAMP::CallBacks::pCallBackRegister->vecRakClientRPCRecvCallback[i](&params);
			if (!retn)
				return false;
		}
		//bool retn = SAMP::CallBacks::pCallBackRegister->callRakClientRPCRecv(&params);
		id = params.rpc_id;
		//if (!retn)
		//	return false;
	}

	incoming.SetWriteOffset(offset);
	incoming.Write(id);
	bits_data = BYTES_TO_BITS(callback_bs->GetNumberOfBytesUsed());
	incoming.WriteCompressed(bits_data);
	if (bits_data)
		incoming.WriteBits(callback_bs->GetData(), bits_data, false);

	return SAMP::CallBacks::pCallBackRegister->pRakPeerHandleRPCPacketHook->call<RakPeerInterface*, const char*, int, PlayerID__>(_this, reinterpret_cast<char*>(incoming.GetData()), incoming.GetNumberOfBytesUsed(), playerid);
}
bool __fastcall SAMP::CallBacks::CCallbackRegister::RakClientRPCSend_HOOKED(RakClientInterface* _this, void* Unknown, int* uniqueID, BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, bool shiftTimestamp) {
	if (_this == nullptr || uniqueID == nullptr || bitStream == nullptr)
		return SAMP::CallBacks::pCallBackRegister->pRakClientRPCSendHook->call<RakClientInterface*, int*, BitStream*, PacketPriority, PacketReliability, char, bool>(_this, uniqueID, bitStream, priority, reliability, orderingChannel, shiftTimestamp);

	if (!SAMP::CallBacks::pCallBackRegister->vecRakClientRPCCallback.empty()) {
		HookedStructs::stRakClientRPC params = { 0 };
		params.bitStream = bitStream;
		params.orderingChannel = orderingChannel;
		params.priority = priority;
		params.reliability = reliability;
		params.shiftTimestamp = shiftTimestamp;
		params.uniqueID = uniqueID;
		params._this = _this;
		bool retn;
		for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecRakClientRPCCallback.size(); i++) {
			retn = SAMP::CallBacks::pCallBackRegister->vecRakClientRPCCallback[i](&params);
			if (!retn)
				return false;
		}
		//bool retn = SAMP::CallBacks::pCallBackRegister->callRakClientRPC(&params);
		bitStream = params.bitStream;
		orderingChannel = params.orderingChannel;
		priority = params.priority;
		reliability = params.reliability;
		shiftTimestamp = params.shiftTimestamp;
		uniqueID = params.uniqueID;
		_this = params._this;
	}

	return SAMP::CallBacks::pCallBackRegister->pRakClientRPCSendHook->call<RakClientInterface*, int*, BitStream*, PacketPriority, PacketReliability, char, bool>(_this, uniqueID, bitStream, priority, reliability, orderingChannel, shiftTimestamp);
}
bool __fastcall SAMP::CallBacks::CCallbackRegister::RakClientSend_HOOKED(RakClientInterface* _this, void* Unknown, BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel) {
	if (_this == nullptr || bitStream == nullptr)
		return SAMP::CallBacks::pCallBackRegister->pRakClientSendHook->call<RakClientInterface*, BitStream*, PacketPriority, PacketReliability, char>(_this, bitStream, priority, reliability, orderingChannel);

	if (!SAMP::CallBacks::pCallBackRegister->vecRakClientSendCallback.empty()) {
		HookedStructs::stRakClientSend params = { 0 };
		params.bitStream = bitStream;
		params.orderingChannel = orderingChannel;
		params.priority = priority;
		params.reliability = reliability;
		params._this = _this;
		bool retn;
		for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecRakClientSendCallback.size(); i++) {
			retn = SAMP::CallBacks::pCallBackRegister->vecRakClientSendCallback[i](&params);
			if (!retn)
				return false;
		}
		//bool retn = SAMP::CallBacks::pCallBackRegister->callRakClientSend(&params);
		bitStream = params.bitStream;
		orderingChannel = params.orderingChannel;
		priority = params.priority;
		reliability = params.reliability;
		_this = params._this;
		//if (!retn)
		//	return false;
	}

	return SAMP::CallBacks::pCallBackRegister->pRakClientSendHook->call<RakClientInterface*, BitStream*, PacketPriority, PacketReliability, char>(_this, bitStream, priority, reliability, orderingChannel);
}
HRESULT __stdcall SAMP::CallBacks::CCallbackRegister::D3DPresent_HOOKED(IDirect3DDevice9* pDevice, CONST RECT* pSrcRect, CONST RECT* pDestRect, HWND hDestWindow, CONST RGNDATA* pDirtyRegion) {
	if (pDevice == nullptr)
		return SAMP::CallBacks::pCallBackRegister->pD3DPresentHook->call<IDirect3DDevice9*, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*>(pDevice, pSrcRect, pDestRect, hDestWindow, pDirtyRegion);
	if (!SAMP::CallBacks::pCallBackRegister->isD3DHookInit) {
		SAMP::CallBacks::pCallBackRegister->isD3DHookInit = true;
		SAMP::CallBacks::pCallBackRegister->pD3DDevice = pDevice;
	}

	if (!SAMP::CallBacks::pCallBackRegister->vecPresentCallback.empty()) {
		HookedStructs::stPresentParams params = { 0 };
		params.hDestWindow = hDestWindow;
		params.pDestRect = pDestRect;
		params.pDevice = pDevice;
		params.pDirtyRegion = pDirtyRegion;
		params.pSrcRect = pSrcRect;
		HRESULT retn;
		//for (auto i : SAMP::CallBacks::pCallBackRegister->vecPresentCallback) { //поебота, которая переполняет стек и кидает исключение на копирование объекта в std::function
		for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecPresentCallback.size(); i++) {
			retn = SAMP::CallBacks::pCallBackRegister->vecPresentCallback[i](&params);
			if (retn != D3D_OK)
				return retn;
		}
		//}
		//LRESULT retn = SAMP::CallBacks::pCallBackRegister->callPresent(&params);
		hDestWindow = params.hDestWindow;
		pDestRect = params.pDestRect;
		pDevice = params.pDevice;
		pDirtyRegion = params.pDirtyRegion;
		pSrcRect = params.pSrcRect;
		//if (retn != D3D_OK)
		//	return retn;
	}

	return SAMP::CallBacks::pCallBackRegister->pD3DPresentHook->call<IDirect3DDevice9*, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*>(pDevice, pSrcRect, pDestRect, hDestWindow, pDirtyRegion);
}
HRESULT __stdcall SAMP::CallBacks::CCallbackRegister::D3DReset_HOOKED(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentParams) {
	if (pDevice == nullptr)
		return SAMP::CallBacks::pCallBackRegister->pD3DResetHook->call<IDirect3DDevice9*, D3DPRESENT_PARAMETERS*>(pDevice, pPresentParams);

	if (!SAMP::CallBacks::pCallBackRegister->vecResetCallback.empty()) {
		HookedStructs::stResetParams params = { 0 };
		params.pDevice = pDevice;
		params.pPresentParams = pPresentParams;
		HRESULT retn;
		for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecResetCallback.size(); i++) {
			retn = SAMP::CallBacks::pCallBackRegister->vecResetCallback[i](&params);
			if (retn != D3D_OK)
				return retn;
		}
		//HRESULT retn = SAMP::CallBacks::pCallBackRegister->callReset(&params);
		pDevice = params.pDevice;
		pPresentParams = params.pPresentParams;
		//if (retn != D3D_OK)
		//	return retn;
	}

	return SAMP::CallBacks::pCallBackRegister->pD3DResetHook->call<IDirect3DDevice9*, D3DPRESENT_PARAMETERS*>(pDevice, pPresentParams);
}
void __cdecl SAMP::CallBacks::CCallbackRegister::GameLoop_HOOKED() {
	if (!SAMP::CallBacks::pCallBackRegister->vecGameLoopCallback.empty()) {
		//SAMP::CallBacks::pCallBackRegister->callGameLoop();
		for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecGameLoopCallback.size(); i++) {
			SAMP::CallBacks::pCallBackRegister->vecGameLoopCallback[i]();
		}
	}
	return SAMP::CallBacks::pCallBackRegister->pGameLoopHook->call<>();
}
LRESULT __stdcall SAMP::CallBacks::CCallbackRegister::WndProc_HOOKED(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
		SAMP::bKeyTable[VK_LBUTTON] = (uMsg == WM_LBUTTONDOWN);
		break;

	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
		SAMP::bKeyTable[VK_RBUTTON] = (uMsg == WM_RBUTTONDOWN);
		break;

	case WM_MBUTTONDOWN:
	case WM_MBUTTONUP:
		SAMP::bKeyTable[VK_MBUTTON] = (uMsg == WM_MBUTTONDOWN);
		break;

	case WM_SYSKEYDOWN:
	case WM_SYSKEYUP:
	case WM_KEYDOWN:
	case WM_KEYUP:
	{
		bool bDown = (uMsg == WM_SYSKEYDOWN || uMsg == WM_KEYDOWN);
		int	iKey = (int)wParam;
		uint32_t ScanCode = LOBYTE(HIWORD(lParam));

		SAMP::bKeyTable[iKey] = bDown;

		switch (iKey)
		{
		case VK_SHIFT:
			if (ScanCode == MapVirtualKey(VK_LSHIFT, 0)) SAMP::bKeyTable[VK_LSHIFT] = bDown;
			if (ScanCode == MapVirtualKey(VK_RSHIFT, 0)) SAMP::bKeyTable[VK_RSHIFT] = bDown;
			break;

		case VK_CONTROL:
			if (ScanCode == MapVirtualKey(VK_LCONTROL, 0)) SAMP::bKeyTable[VK_LCONTROL] = bDown;
			if (ScanCode == MapVirtualKey(VK_RCONTROL, 0)) SAMP::bKeyTable[VK_RCONTROL] = bDown;
			break;

		case VK_MENU:
			if (ScanCode == MapVirtualKey(VK_LMENU, 0)) SAMP::bKeyTable[VK_LMENU] = bDown;
			if (ScanCode == MapVirtualKey(VK_RMENU, 0)) SAMP::bKeyTable[VK_RMENU] = bDown;
			break;
		}
		break;
	}
	}

	if (!SAMP::CallBacks::pCallBackRegister->vecWndProcCallback.empty()) {//maybe error if null?
		HookedStructs::stWndProcParams params = { 0 };
		params.hWnd = hWnd;
		params.uMsg = uMsg;
		params.wParam = wParam;
		params.lParam = lParam;
		LRESULT retn;
		for (std::size_t i = 0; i != SAMP::CallBacks::pCallBackRegister->vecWndProcCallback.size(); i++) {
			retn = SAMP::CallBacks::pCallBackRegister->vecWndProcCallback[i](&params);
			if (retn != 0)
				retn;
		}
		//LRESULT retn = SAMP::CallBacks::pCallBackRegister->callWndProc(&params);
		hWnd = params.hWnd;
		uMsg = params.uMsg;
		wParam = params.wParam;
		lParam = params.lParam;
		//if (retn != 0)
		//	return retn;
	}
	return SAMP::CallBacks::pCallBackRegister->pWndProcHook->call<HWND, UINT, WPARAM, LPARAM>(hWnd, uMsg, wParam, lParam);
}
