

#if defined(__aarch64__)
#define GetUniqueID(WeaponHand) *(uint32_t*)((uint64_t)WeaponHand + 0x10)
#else
#define GetUniqueID(WeaponHand) *(uint32_t*)((uint64_t)WeaponHand + 0x8)
#endif

bool SilentAim;
//Aimkill By @Gohan52

struct message_PVector3IntPos_StaticFields {
};
//Aimkill By @Gohan52

struct message_PVector3IntPos_VTable {
        VirtualInvokeData _0_Equals;
        VirtualInvokeData _1_Finalize;
        VirtualInvokeData _2_GetHashCodek;
        VirtualInvokeData _3_ToString;
        VirtualInvokeData _6_Serialize;
        VirtualInvokeData _7_UnSerialize;
        VirtualInvokeData _8_CanCache;
        VirtualInvokeData _9_Recycle;
};

uintptr_t getAddressIL2CPP(uintptr_t offset) {
    // Example base address getter — yeh tumhare game ke base function ke hisab se badalna padega
    uintptr_t libBase = reinterpret_cast<uintptr_t>(dlopen("libil2cpp.so", 0));
    return libBase + offset;
}

struct message_PVector3IntPos_c {
        Il2CppClass_1 _1;
        message_PVector3IntPos_StaticFields* static_fields;
        Il2CppClass_2 _2;
        message_PVector3IntPos_VTable vtable;
};

struct message_PVector3IntPos_o;
struct message_PVector3IntPos_o {
        message_PVector3IntPos_c *klass;
        void *monitor;
        bool UDPClientMessageBase_m_GetFromPool;
        int32_t X;
        int32_t Y;
        int32_t Z;
};






struct message_C2S_RUDP_TakeDamage_Req_o2 {//struct message_CHDLJFJCPFN_o2 {
    void *klass;
    void *monitor;
    bool UDPClientMessageBase_m_GetFromPool;
    uint32_t AttackableEntityID;//    uint32_t ALFINFGBOBE;
    uint16_t RealDamageValue;//ECDBFHHNPMI
    uint16_t ShieldDamageValue;//EKCONDDBKFO
    uint32_t DamageValue;//BJBPPEBIPFA
    uint32_t DamagerID;//LIIGLCNGOHG
    int32_t WeaponDataID;//PIAMIOFEBKF
    uint32_t WeaponUniqueID;//HCMIEJEBKAL
    uint8_t HitBodyPart;//ODCJPCEJHPK
    uint32_t TickCount;//CEDJCPLOLNE
    message_PVector3IntPos_o* FirePos;//message_DEACEIFBHJK_o* CNEICNJFGLM;
    message_PVector3IntPos_o* TargetPos;//PGDEDHFOMCN
    monoList<float*> * CheckParams;//AALHLOAJLEE
    uint32_t ExtraData;//HOBOHHJNDNH
    float ArmorRatio;//AILHIPMKJKJ
    uint64_t ExtraFlag;//LHGGPCFJNOO
    int8_t SpecialHitType;//ACAKHEABPEJ
    bool ForceNoHeadShot;//MJIHLDJNHLF
    bool IsPlayerBackArea;//MBGCAHPACOH
    monoList<int*> * DamageData;//FIKOAMIDEHL
    float BaseTime;//IOGIIEFAALP
    bool ManualReload;//HDEJLJKNLCI
};




struct PlayerID_MKFEKBKJCKE_o;

struct PlayerID {
    uint32_t m_Value;
    uint32_t m_ID;
    uint8_t m_TeamID;
    uint8_t m_ShortID;
    uint64_t m_IDMask;
};
//Aimkill By @Gohan52
//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//



struct COW_GamePlay_IHAAMHPPLMG_o;
struct COW_GamePlay_IHAAMHPPLMG_o {
    uint32_t m_Value;
    uint32_t m_ID;
    uint8_t m_TeamID;
    uint8_t m_ShortID;
    uint64_t m_IDMask;
};



struct DamageInfo2_o {
    void *klass;
    void *monitor;
    int32_t BaseDamage;
    int32_t HitColliderType;
    monoString* HitColliderName;
    bool isBackArea;
    //PlayerID Damager;
    COW_GamePlay_IHAAMHPPLMG_o Damager; // chx probably because i don't know the name
    void* Weapon;
    int32_t WeaponDataID;
    Vector3 FirePos;
    Vector3 HitPos;
    Vector3 HitNormal;
    uint8_t SpecialHitType;
    bool ForceNoHeadshot;
    int32_t ExtraInfo;
    monoDictionary<uint8_t*, void **> *SpecialHitDic;
};



struct GCommon_TimeService_o;

struct GCommon_TimeService_StaticFields {
};
struct GCommon_TimeService_VTable {
        VirtualInvokeData _0_Equals;
        VirtualInvokeData _1_Finalize;
        VirtualInvokeData _2_GetHashCodek;
        VirtualInvokeData _3_ToString;
};

struct GCommon_TimeService_c {
        Il2CppClass_1 _1;
        GCommon_TimeService_StaticFields* static_fields;
        Il2CppClass_2 _2;
        GCommon_TimeService_VTable vtable;
};

struct GCommon_TimeService_o {
        GCommon_TimeService_c *klass;
        void *monitor;
        float m_GameTime;
        float m_LastGameTime;
        float m_DeltaTime;
        uint32_t m_DeltaTickCount;
        uint32_t m_TickCount;
        uint32_t m_RealDoLogicTickCount;
        bool m_UsingFixedDeltaTime;
        float m_FixedDeltaTime;
};







#define offset_PNGAJBCPDNJ (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PhyXShield"), OBFUSCATE("CreateDamageReq"), 0)
#define offset_BaseDamage (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Weapon"), OBFUSCATE("m_WeaponParams"))
#define offset_KFMGKCJMCAM (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("m_PlayerID"))
#define offset_GEGFCFDGGGP (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("m_LastAimingInfoFromWeapon"))
#define offset_PlayerAttributes (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("m_Attributes"))
#define offset_AHEKHEAHOPP (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerAttributes"), OBFUSCATE("m_DamageContextData"))
#define offset_DamageBaseInfo (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("FDamageContextData"), OBFUSCATE("damageInfo"))
#define offset_SetStartDamage (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Weapon"), OBFUSCATE("OnCalcDamageOrHealing"), 1)
#define offset_JMKMBNIBFNA (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("HitObjectInfo"), OBFUSCATE("HitObject"))
#define offset_GHACJPMCEDK (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("HitObjectInfo"), OBFUSCATE("HitCollider"))
#define offset_OJKBBAOPPIN (uintptr_t) Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("HitObjectInfo"), OBFUSCATE("HitGroup"))


// New Classes
#define offset_GetWeaponOnHand (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("GetWeaponOnHand"), 0)
#define offset_GetWeaponID (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("ItemBase"), OBFUSCATE("GetItemDataID"), 0)
#define offset_GetHeadCollider (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("get_HeadCollider"), 0)
#define offset_GKHECDLGAJA (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("GetAimingAttackableEntity"), 1)
#define offset_LCLHHHKFCFP (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Weapon"), OBFUSCATE("GenerateCheckParams"), 4)
#define offset_JDGGIFMKIKF (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Weapon"), OBFUSCATE("get_Range"), 0)
#define offset_CFFPIACECIG (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerID"), OBFUSCATE("op_Implicit"), 1)
#define offset_LHGGPDLOPAH (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("message"), OBFUSCATE("ProtoUtil"), OBFUSCATE("PackVector3Pos"), 1)
#define offset_SendFunction (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("GameFacade"), OBFUSCATE("Send"), 4)
#define offset_StartFiring (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerNetwork"), OBFUSCATE("StartFiring"), 1)
#define offset_StopFire (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerNetwork"), OBFUSCATE("StopFire"), 1)
#define offset_StartWholeBodyFiring (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerNetwork"), OBFUSCATE("StartWholeBodyFiring"), 1)
#define offset_get_realtimeSinceStartup (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Time"), OBFUSCATE("get_realtimeSinceStartup"), 0)
#define offset_SimulationTimer (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("GameFacade"), OBFUSCATE("CurrentGameSimulationTimer"), 0)
#define offset_DPPPFBHIHJA (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("ffantihack"), OBFUSCATE("DCKLGOGDPCH"), OBFUSCATE("DPPPFBHIHJA"), 0)
#define offset_LocalPlayerOrObServer (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("GameFacade"), OBFUSCATE("GetLocalPlayerOrObServer"), 0)
#define HeadColider1 (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("get_HeadCollider"), 0)
#define get_gameObject1 Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Component"), OBFUSCATE("get_gameObject"), 0)
#define offset_LocalPlayer (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("GameFacade"), OBFUSCATE("CurrentLocalPlayer"), 0)

#define Classdamageinfo Il2CppGetClassType(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("DamageInfo"))
#define BNJIPPIIMDF1616 Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("message"), OBFUSCATE("C2S_RUDP_WholeBody_StartFire_Req"), OBFUSCATE(".ctor"), 0)
#define offset_currenttimerxamcac Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("GameFacade"), OBFUSCATE("CurrentGameSimulationTimer"), 0)
#define offset_TakeDamage (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerNetwork"), OBFUSCATE("TakeDamage"), 9)
//KOGBJLFDJHC = ItemBase
#define startwholdrfirjfjdjdjdjssjcsc Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerNetwork"), OBFUSCATE("SwapWeapon"), 3)
#define offsetphy2concsc Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("GetPhysXPose"), 0)

#define SwapWeapon11234 Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerNetwork"), OBFUSCATE("SwapWeapon"), 2)


// auto change
#define GetPlayerID111 Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("GetPlayerID"), 0)
#define offsetsendaimkkll Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("message"), OBFUSCATE("C2S_RUDP_WholeBody_StartFire_Req"), OBFUSCATE(".ctor"), 0)


#define Current_Local_Player1 Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW"), OBFUSCATE("GameFacade"), OBFUSCATE("CurrentLocalPlayer"), 0)







static int GetWeapon(void* enemy) {
    int (*GetWeapon)(void *player) = (int(*)(void *))(offset_GetWeaponID);
    return GetWeapon(enemy);
}





void *GKHECDLGAJA(void *pthis, void* a1)
{
    return ((void* (*)(void *,void *))(offset_GKHECDLGAJA))(pthis,a1);
}

monoList<float *> *LCLHHHKFCFP(void *Weapon,void *CAGCICACKCF,void *HFBDJJDICLN,bool LDGHPOPPPNL,DamageInfo2_o *DamageInfo)
{
    return ((monoList<float *> * (*)(void*,void*,void*,bool,DamageInfo2_o*))(offset_LCLHHHKFCFP))(Weapon,CAGCICACKCF,HFBDJJDICLN,LDGHPOPPPNL,DamageInfo);
}







monoList<float *> *LCLHHHKFCFP2(void *Weapon,void *CAGCICACKCF,void *HFBDJJDICLN,bool LDGHPOPPPNL,void *DamageInfo)
{
    //return ((monoList<float *> * (*)(void*,void*,void*,bool,DamageInfo2_o*))(offset_LCLHHHKFCFP))(Weapon,CAGCICACKCF,HFBDJJDICLN,LDGHPOPPPNL,DamageInfo);
        return ((monoList<float *> * (*)(void*,void*,void*,bool,void*))(offset_LCLHHHKFCFP))(Weapon,CAGCICACKCF,HFBDJJDICLN,LDGHPOPPPNL,DamageInfo);

}




bool isEnemyInRangeWeapon(void *player, void *enemy, void* weapon)
{
    if (player != nullptr && enemy != nullptr && weapon != nullptr)
    {
        Vector3 EnemyHeadPosition = GetHeadPosition(enemy);
        Vector3 PlayerHeadPosition = GetHeadPosition(player);
        float distance = Vector3::Distance(PlayerHeadPosition, EnemyHeadPosition);
        float range = get_Range(weapon);

        if (distance <= range) {
            return true;
        }
    }
    return false;
}



uint32_t CFFPIACECIG(COW_GamePlay_IHAAMHPPLMG_o id)
{
    return ((uint32_t (*)(COW_GamePlay_IHAAMHPPLMG_o))(offset_CFFPIACECIG))(id);
}






message_PVector3IntPos_o *PackVector3Pos(Vector3 v)//message_DEACEIFBHJK_o *LHGGPDLOPAH(Vector3 JOGHOHLEJFL)
{
    return ((message_PVector3IntPos_o* (*)(Vector3))offset_LHGGPDLOPAH)(v);
}//    return ((message_DEACEIFBHJK_o* (*)(Vector3))offset_LHGGPDLOPAH)(JOGHOHLEJFL);




// Then in your hook:



bool GameFacade_Send(uint32_t messageID,void *msg,uint8_t sendOption,bool cacheMsgAnyWay)
{
    return ((bool (*)(uint32_t,void *,uint8_t,bool))offset_SendFunction)(messageID,msg,sendOption,cacheMsgAnyWay);
}




static void StartFiring(void *Player, void *WeaponOnHand) {
    void (*_StartFiring)(void *, void *) = (void (*)(void *, void *))(offset_StartFiring);
    return _StartFiring(Player, WeaponOnHand);
}

static void StopFire1(void* Player,void* WeaponOnHand){
    void(*_StopFire1)(void*,void*) = (void(*)(void*,void*))(offset_StopFire);
    return _StopFire1(Player,WeaponOnHand);
}

void StartWholeBodyFiring(void* Player,void* WeaponOnHand){
    void(*_StartWholeBodyFiring)(void*,void*) = (void(*)(void*,void*))(offset_StartWholeBodyFiring);
    return _StartWholeBodyFiring(Player,WeaponOnHand);
}


static void StartonFiring(void *LocalPlayer, void *WeaponHand) {
        StartFiring(LocalPlayer, WeaponHand);
        StartWholeBodyFiring(LocalPlayer, WeaponHand);
        StopFire1(LocalPlayer, WeaponHand);
}







static float get_realtimeSinceStartup() {
    float (*_get_realtimeSinceStartup)(void *nuls) = (float (*)(void *))(offset_get_realtimeSinceStartup);
    return _get_realtimeSinceStartup(NULL);
}

void* CurrentGameSimulationTimer()
{
    return ((void* (*)(void *))(offset_SimulationTimer))(NULL);
}

monoList<int*> *DPPPFBHIHJA()
{
    return ((monoList<int*> * (*)())(offset_DPPPFBHIHJA))();
}
// k qtrong





static int32_t TakeDamage(void *_this, int32_t KOCMLPLOILD, PlayerID HLJDHPGGODB, void* JIIJIFKKCCB, int32_t BOEIBGAABDL, Vector3 NJMFBKNHMBP, Vector3 DOBOBMFMKBJ, monoList<float *> *NBKBEBFNDBE, void* damagerWeaponDynamicInfo, uint32_t damagerVehicleID) {
    return ((int32_t (*)(void*, int32_t, PlayerID, void*, int32_t, Vector3, Vector3, monoList<float *> *, void*, uint32_t))(offset_TakeDamage))(_this, KOCMLPLOILD, HLJDHPGGODB, JIIJIFKKCCB, BOEIBGAABDL, NJMFBKNHMBP, DOBOBMFMKBJ, NBKBEBFNDBE, damagerWeaponDynamicInfo, damagerVehicleID);
}


//














// ================================================================ AIMKILL=================================================================
int SetDamage = 1;



COW_GamePlay_IHAAMHPPLMG_o GetplayerID(void *_this)

{

    return ((COW_GamePlay_IHAAMHPPLMG_o (*)(void *))(GetPlayerID111))(_this);
}









static void SwapWeapon11(void* player, int POFFNNMOOBM, bool GDKLMFLNNGM) {
    void (*_SwapWeapon11)(void* player, int POFFNNMOOBM, bool GDKLMFLNNGM) = (void (*)(void *, int, bool))(SwapWeapon11234);
     _SwapWeapon11(player, POFFNNMOOBM, GDKLMFLNNGM);
}













#include <cstdint>
#include <cstring>
#include <ctime>

// assume Vector3, PlayerID etc. are defined as in your codebase

namespace Save {
    void* DamageInfo = nullptr;
    clock_t AimDelay = 0;
    // AimFPS was weird units (1000000/60). If you want microsecond frame time: 1000000/60 ~ 16666
    // But typical FPS delay should be milliseconds: 1000/60 = 16 ms
    int AimFPS = (1000 / 60); // ms per frame if you ever use it
}

bool HeadKill = false;
bool aimkillsend = false;
bool autochangesendnew = false;
bool AimKill2 = false;

// helper: write int to raw pointer offset
inline void write_int(void* base, size_t offset, int value) {
    if (!base) return;
    int* p = reinterpret_cast<int*>(reinterpret_cast<char*>(base) + offset);
    *p = value;
}
inline void write_ptr(void* base, size_t offset, void* value) {
    if (!base) return;
    void** p = reinterpret_cast<void**>(reinterpret_cast<char*>(base) + offset);
    *p = value;
}
inline void write_uint32(void* base, size_t offset, uint32_t value) {
    if (!base) return;
    uint32_t* p = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(base) + offset);
    *p = value;
}

static int gay2000 = 95;
static int minInterval = 75;
static int maxInterval = 135;

static int getRandomInterval() {
    static unsigned int seed = time(NULL);
    seed = seed * 1103515245 + 12345;
    return minInterval + (seed % (maxInterval - minInterval + 1));
}

static float getRandomOffset() {
    static unsigned int seed = time(NULL) + 1;
    seed = seed * 1103515245 + 12345;
    return ((seed % 100) / 1000.0f) - 0.05f;
}

void StartTakeDamage(void* ClosestEnemy) {
    if (ClosestEnemy == nullptr || !Aimbot) return;

    void* trandau = Curent_Match();
    if (!trandau) return;
    
    void* LocalPlayer = GetLocalPlayer(trandau);
    if (!LocalPlayer) return;

    auto damagePacket = (message_C2S_RUDP_TakeDamage_Req_o2*)((void* (*)(void*))offset_PNGAJBCPDNJ)(LocalPlayer);
    if (!damagePacket) return;

    void* Class_message_DamageInfo_c = Classdamageinfo;
    if (!Class_message_DamageInfo_c) return;

    auto DamageInfo = (DamageInfo2_o*)((void* (*)(void*))(BNJIPPIIMDF1616))(Class_message_DamageInfo_c);
    if (!DamageInfo) return;

    void* WeaponHand = GetWeaponOnHand1(LocalPlayer);
    if (!WeaponHand) return;

    PlayerID PlayerID2 = *(PlayerID*)((uintptr_t)LocalPlayer + offset_KFMGKCJMCAM);
    PlayerID playerID_Enemy = *(PlayerID*)((uintptr_t)ClosestEnemy + offset_KFMGKCJMCAM);
    int baseDamage = *(int*)((uintptr_t)WeaponHand + offset_BaseDamage);
    if (baseDamage <= 0) return;
    
    int weaponID = GetWeapon(WeaponHand);
    void* objectPool = *(void**)((uintptr_t)LocalPlayer + offset_GEGFCFDGGGP);
    if (!objectPool) return;

    static bool s_Il2CppMethodIntialized = false;
    if (!s_Il2CppMethodIntialized) {
        ((void (*)(void*, void*))offset_SetStartDamage)(WeaponHand, objectPool);
        ((void* (*)(void*))offset_PNGAJBCPDNJ)(LocalPlayer);
        s_Il2CppMethodIntialized = true;
    }

    Save::DamageInfo = DamageInfo;
    if (Save::DamageInfo == nullptr) return;

    write_int(Save::DamageInfo, 0x14, 1);
    write_int(Save::DamageInfo, 0x10, baseDamage);
    write_ptr(Save::DamageInfo, 0x40, WeaponHand);
    write_int(Save::DamageInfo, 0x48, weaponID);

    void* headCollider = GetHeadCollider(ClosestEnemy);
    if (!headCollider) return;

    write_ptr(objectPool, offset_JMKMBNIBFNA, get_gameObject(headCollider));
    write_ptr(objectPool, offset_GHACJPMCEDK, headCollider);
    write_int(objectPool, offset_OJKBBAOPPIN, 1);

    void* sl3 = GKHECDLGAJA(LocalPlayer, objectPool);
    if (!sl3) return;
    
    monoList<float*>* paramCheck = LCLHHHKFCFP(WeaponHand, sl3, headCollider, false, (DamageInfo2_o*)Save::DamageInfo);

    GCommon_TimeService_o* GameSimulation = (GCommon_TimeService_o*)CurrentGameSimulationTimer();
    if (!GameSimulation || !paramCheck) return;

    static auto lastTime = std::chrono::steady_clock::now() - std::chrono::milliseconds(1000);
    static int lastInterval = getRandomInterval();

    if (isEnemyInRangeWeapon(LocalPlayer, ClosestEnemy, WeaponHand)) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTime).count();

        if (elapsed >= lastInterval) {
            Vector3 firePos = GetHeadPosition(LocalPlayer);
            Vector3 hitPos = GetHeadPosition(ClosestEnemy);
            
            hitPos.x += getRandomOffset();
            hitPos.y += getRandomOffset();
            hitPos.z += getRandomOffset();

            TakeDamage(ClosestEnemy, baseDamage, PlayerID2,
                       (DamageInfo2_o*)Save::DamageInfo, weaponID,
                       firePos, hitPos, paramCheck, nullptr, 0);

            StartonFiring(LocalPlayer, WeaponHand);

            lastTime = now;
            lastInterval = getRandomInterval();
        }
    } else {
        lastTime = std::chrono::steady_clock::now() - std::chrono::milliseconds(1000);
        lastInterval = getRandomInterval();
    }
}
void StartAimKillSend(void* ClosestEnemy) {
    if (ClosestEnemy == nullptr || !Aimbot) return;
    void* localPlayer = Current_Local_Player();
    if (!localPlayer) return;

    void* weapon = GetWeaponOnHand1(localPlayer);
    if (!weapon) return;
    int baseDamage = *(int*)((uintptr_t)weapon + offset_BaseDamage);
    if (baseDamage == 0) return;

    Vector3 firePos = GetHeadPosition(localPlayer);
    int weaponID = GetWeapon(weapon);
    PlayerID playerID_Local = *(PlayerID*)((uintptr_t)localPlayer + offset_KFMGKCJMCAM);
    void* objectPool = *(void**)((uintptr_t)localPlayer + offset_GEGFCFDGGGP);
    if (!objectPool) return;

    void* Class_message_DamageInfo_c = Classdamageinfo;
    if (!Class_message_DamageInfo_c) return;

    // allocate or get the damage packet
    auto damagePacket = (message_C2S_RUDP_TakeDamage_Req_o2*)((void* (*)(void*))offset_PNGAJBCPDNJ)(localPlayer);
    if (!damagePacket) return;

    auto damageBaseInfo = (DamageInfo2_o*)((void* (*)(void*))(BNJIPPIIMDF1616))(Class_message_DamageInfo_c);
    if (!damageBaseInfo) return;

    static bool hasStartedDamage = false;
    if (!hasStartedDamage) {
        ((void (*)(void*, void*))offset_SetStartDamage)(weapon, objectPool);
        ((void* (*)(void*))offset_PNGAJBCPDNJ)(localPlayer); // refresh
        hasStartedDamage = true;
    }

    Vector3 hitPos = GetHeadPosition(ClosestEnemy);
    void* headCollider = GetHeadCollider(ClosestEnemy);
    if (!headCollider) return;

    PlayerID playerID_Enemy = *(PlayerID*)((uintptr_t)ClosestEnemy + offset_KFMGKCJMCAM);

    void* sl3 = GKHECDLGAJA(localPlayer, objectPool);
    monoList<float*>* paramCheck = LCLHHHKFCFP(weapon, sl3, headCollider, false, damageBaseInfo);
    if (!paramCheck) return;

    if (isEnemyInRangeWeapon(localPlayer, ClosestEnemy, weapon)) {
        // Set fields carefully / correctly
        damagePacket->AttackableEntityID = CFFPIACECIG(GetplayerID(ClosestEnemy));
        damagePacket->DamagerID = CFFPIACECIG(GetplayerID(localPlayer));
        damagePacket->DamageValue = baseDamage;
        damagePacket->HitBodyPart = SetDamage;
        damagePacket->WeaponDataID = weaponID;
        // WeaponUniqueID is often at weapon + 0x10 but ensure correct endianness/type
        uint32_t uniqueId = *(uint32_t*)((uintptr_t)weapon + 0x10);
        damagePacket->WeaponUniqueID = uniqueId;
        damagePacket->FirePos = PackVector3Pos(firePos);
        damagePacket->TargetPos = PackVector3Pos(hitPos);
        damagePacket->CheckParams = paramCheck;

        // If your packet struct has a timestamp or tick field, set it to the current GameSimulation tick.
        // e.g. damagePacket->Timestamp = GameSimulation->GetServerTick(); // pseudo

        // Send reliably
        GameFacade_Send(106, damagePacket, 2, 0); // 106 = take damage (your code)
    }
}

#include <chrono>

void StartTakeDamage3(void* ClosestEnemy) {
    // persistent timer inside the function
    static auto lastTime = std::chrono::steady_clock::now();

    // return early if no enemy or Aimbot off
    if (!ClosestEnemy || !Aimbot) return;

    // check elapsed time
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTime).count();

    if (elapsed >= 25) {      // only run the body every 25 ms
        lastTime = now;        // reset timer

        // -------------------------
        // Original function code
        // -------------------------
        void* trandau = Curent_Match();
        void* LocalPlayer = GetLocalPlayer(trandau);
        if (!LocalPlayer) return;

        auto damagePacket = (message_C2S_RUDP_TakeDamage_Req_o2*)((void* (*)(void*))offset_PNGAJBCPDNJ)(LocalPlayer);
        if (!damagePacket) return;

        void* Class_message_DamageInfo_c = Classdamageinfo;
        if (!Class_message_DamageInfo_c) return;

        auto DamageInfo = (DamageInfo2_o*)((void* (*)(void*))(BNJIPPIIMDF1616))(Class_message_DamageInfo_c);
        if (!DamageInfo) return;

        void* WeaponHand = GetWeaponOnHand1(LocalPlayer);
        if (!WeaponHand) return;

        Vector3 firePos = GetHeadPosition(LocalPlayer);
        Vector3 hitPos  = GetHeadPosition(ClosestEnemy);

        PlayerID PlayerID2      = *(PlayerID*)((uintptr_t)LocalPlayer + offset_KFMGKCJMCAM);
        PlayerID playerID_Enemy = *(PlayerID*)((uintptr_t)ClosestEnemy + offset_KFMGKCJMCAM);
        int baseDamage          = *(int*)((uintptr_t)WeaponHand + offset_BaseDamage);
        int weaponID            = GetWeapon(WeaponHand);
        void* objectPool        = *(void**)((uintptr_t)LocalPlayer + offset_GEGFCFDGGGP);
        if (!objectPool) return;

        static bool s_Il2CppMethodIntialized = false;
        if (!s_Il2CppMethodIntialized) {
            ((void (*)(void*, void*))offset_SetStartDamage)(WeaponHand, objectPool);
            ((void* (*)(void*))offset_PNGAJBCPDNJ)(LocalPlayer); // refresh
            s_Il2CppMethodIntialized = true;
        }

        Save::DamageInfo = DamageInfo;
        if (!Save::DamageInfo) return;

        write_int(Save::DamageInfo, 0x14, 1);              // crit/flag
        write_int(Save::DamageInfo, 0x10, baseDamage);     // damage
        write_ptr(Save::DamageInfo, 0x40, WeaponHand);     // weapon pointer
        write_int(Save::DamageInfo, 0x48, weaponID);       // weapon ID

        void* headCollider = GetHeadCollider(ClosestEnemy);
        if (!headCollider) return;

        write_ptr(objectPool, offset_JMKMBNIBFNA, get_gameObject(headCollider));
        write_ptr(objectPool, offset_GHACJPMCEDK, headCollider);
        write_int(objectPool, offset_OJKBBAOPPIN, 1);

        void* sl3 = GKHECDLGAJA(LocalPlayer, objectPool);
        monoList<float*>* paramCheck = LCLHHHKFCFP(WeaponHand, sl3, headCollider, false, (DamageInfo2_o*)Save::DamageInfo);

        GCommon_TimeService_o* GameSimulation = (GCommon_TimeService_o*)CurrentGameSimulationTimer();
        if (GameSimulation && paramCheck) {
            TakeDamage(ClosestEnemy, baseDamage, PlayerID2,
                       (DamageInfo2_o*)Save::DamageInfo, weaponID,
                       firePos, hitPos, paramCheck, nullptr, 0);
           
            // Randomized slight delay before firing
            usleep(rand() % 20000 + 10000); // 10ms - 30ms delay

            StartFiring(LocalPlayer, WeaponHand);
            usleep(rand() % 15 + 5); // 5ms - 20ms delay before next action
            StartWholeBodyFiring(LocalPlayer, WeaponHand);
            usleep(rand() % 10 + 5); // 5ms - 15ms delay before stopping
            StopFire1(LocalPlayer, WeaponHand);
                       // Randomized slight delay before firing
            usleep(rand() % 2 + 10); // 10ms - 30ms delay

            StartFiring(LocalPlayer, WeaponHand);
            usleep(rand() % 1 + 5); // 5ms - 20ms delay before next action
            StartWholeBodyFiring(LocalPlayer, WeaponHand);
            usleep(rand() % 1 + 5); // 5ms - 15ms delay before stopping
            StopFire1(LocalPlayer, WeaponHand);
        }
    }
}

void StartAimKillSend3(void* ClosestEnemy) {
    if (ClosestEnemy == nullptr || !Aimbot) return;
    void* localPlayer = Current_Local_Player();
    if (!localPlayer) return;

    void* weapon = GetWeaponOnHand1(localPlayer);
    if (!weapon) return;
    int baseDamage = *(int*)((uintptr_t)weapon + offset_BaseDamage);
    if (baseDamage == 0) return;

    Vector3 firePos = GetHeadPosition(localPlayer);
    int weaponID = GetWeapon(weapon);
    PlayerID playerID_Local = *(PlayerID*)((uintptr_t)localPlayer + offset_KFMGKCJMCAM);
    void* objectPool = *(void**)((uintptr_t)localPlayer + offset_GEGFCFDGGGP);
    if (!objectPool) return;

    void* Class_message_DamageInfo_c = Classdamageinfo;
    if (!Class_message_DamageInfo_c) return;

    // allocate or get the damage packet
    auto damagePacket = (message_C2S_RUDP_TakeDamage_Req_o2*)((void* (*)(void*))offset_PNGAJBCPDNJ)(localPlayer);
    if (!damagePacket) return;

    auto damageBaseInfo = (DamageInfo2_o*)((void* (*)(void*))(BNJIPPIIMDF1616))(Class_message_DamageInfo_c);
    if (!damageBaseInfo) return;

    static bool hasStartedDamage = false;
    if (!hasStartedDamage) {
        ((void (*)(void*, void*))offset_SetStartDamage)(weapon, objectPool);
        ((void* (*)(void*))offset_PNGAJBCPDNJ)(localPlayer); // refresh
        hasStartedDamage = true;
    }

    Vector3 hitPos = GetHeadPosition(ClosestEnemy);
    void* headCollider = GetHeadCollider(ClosestEnemy);
    if (!headCollider) return;

    PlayerID playerID_Enemy = *(PlayerID*)((uintptr_t)ClosestEnemy + offset_KFMGKCJMCAM);

    void* sl3 = GKHECDLGAJA(localPlayer, objectPool);
    monoList<float*>* paramCheck = LCLHHHKFCFP(weapon, sl3, headCollider, false, damageBaseInfo);
    if (!paramCheck) return;

    if (isEnemyInRangeWeapon(localPlayer, ClosestEnemy, weapon)) {
        // Set fields carefully / correctly
        damagePacket->AttackableEntityID = CFFPIACECIG(GetplayerID(ClosestEnemy));
        damagePacket->DamagerID = CFFPIACECIG(GetplayerID(localPlayer));
        damagePacket->DamageValue = baseDamage;
        damagePacket->HitBodyPart = SetDamage;
        damagePacket->WeaponDataID = weaponID;
        // WeaponUniqueID is often at weapon + 0x10 but ensure correct endianness/type
        uint32_t uniqueId = *(uint32_t*)((uintptr_t)weapon + 0x10);
        damagePacket->WeaponUniqueID = uniqueId;
        damagePacket->FirePos = PackVector3Pos(firePos);
        damagePacket->TargetPos = PackVector3Pos(hitPos);
        damagePacket->CheckParams = paramCheck;

        // If your packet struct has a timestamp or tick field, set it to the current GameSimulation tick.
        // e.g. damagePacket->Timestamp = GameSimulation->GetServerTick(); // pseudo

        // Send reliably
        GameFacade_Send(106, damagePacket, 2, 0); // 106 = take damage (your code)
    }
}
bool SpeedHack = false;


/*


#include <ctime>

namespace Save {
    void* DamageInfo;
    clock_t AimDelay;
    int AimFPS = (1000000 / 60);
}

bool HeadKill;
bool aimkillsend;

bool autochangesendnew;
bool AimKill2;

void StartTakeDamage(void *ClosestEnemy) {
    if (ClosestEnemy == nullptr || !Aimbot) return;
    void* trandau = Curent_Match();
    void* LocalPlayer = GetLocalPlayer(trandau);
   auto damagePacket = (message_C2S_RUDP_TakeDamage_Req_o2*)((void* (*)(void*))(offset_PNGAJBCPDNJ))(LocalPlayer);
   if (!damagePacket) return;
    if (!LocalPlayer) return; 
    void *Class_message_DamageInfo_c = Classdamageinfo;
    if(Class_message_DamageInfo_c) {
        auto DamageInfo = (DamageInfo2_o *)((void * (*)(void *))(BNJIPPIIMDF1616))(Class_message_DamageInfo_c); // damageinfo là class đk còn cái kia là address của class đó
          if (DamageInfo) {
    void *WeaponHand = GetWeaponOnHand1(LocalPlayer);
    if (WeaponHand) {
    Vector3 firePos = GetHeadPosition(LocalPlayer);
    Vector3 hitPos = GetHeadPosition(ClosestEnemy);
    auto PlayerID2 = *(PlayerID *)((uintptr_t)LocalPlayer + offset_KFMGKCJMCAM);
    auto playerID_Enemy = *(PlayerID*)((uintptr_t)ClosestEnemy + offset_KFMGKCJMCAM);
    int baseDamage = *(int*)((uintptr_t)WeaponHand + offset_BaseDamage);
    int weaponID = GetWeapon(WeaponHand);
    void* objectPool = *(void**)((uintptr_t)LocalPlayer + offset_GEGFCFDGGGP);
    if (!objectPool) return;
    
    
    
    
    static bool s_Il2CppMethodIntialized = false;
    if (!s_Il2CppMethodIntialized) {
        ((void (*)(void*, void*))offset_SetStartDamage)(WeaponHand, objectPool);
        ((void* (*)(void*))offset_PNGAJBCPDNJ)(LocalPlayer); // refresh
        
        s_Il2CppMethodIntialized = true;
    }
    Save::DamageInfo = DamageInfo;
        if (Save::DamageInfo != nullptr) {
*(int*)((char*)DamageInfo + 0x14) = 1;
*(int*)((char*)DamageInfo + 0x10) = baseDamage;
*(void**)((char*)DamageInfo + 0x40) = WeaponHand;
*(int*)((char*)DamageInfo + 0x48) = weaponID;

void* headCollider = GetHeadCollider(ClosestEnemy);
if(headCollider) {
    *(void**)((uintptr_t)objectPool + offset_JMKMBNIBFNA) = get_gameObject(headCollider);
    *(void**)((uintptr_t)objectPool + offset_GHACJPMCEDK) = headCollider;
    *(int*)((uintptr_t)objectPool + offset_OJKBBAOPPIN) = 1;
    void* sl3 = GKHECDLGAJA(LocalPlayer, objectPool); // fast chabge
    monoList<float*>* paramCheck = LCLHHHKFCFP(WeaponHand, sl3, headCollider, false, DamageInfo);
    GCommon_TimeService_o *GameSimulation = (GCommon_TimeService_o *)CurrentGameSimulationTimer();
    if (GameSimulation && isEnemyInRangeWeapon(LocalPlayer, ClosestEnemy, WeaponHand)) {

    
    TakeDamage(ClosestEnemy, baseDamage, PlayerID2, DamageInfo, weaponID, firePos, hitPos, paramCheck, nullptr, 0);
        StartonFiring(LocalPlayer, WeaponHand);
     }
  }
}
}
    
    }
        
        }
}





void StartAimKillSend(void* ClosestEnemy) {
    if (ClosestEnemy == nullptr || !Aimbot) return;
    void* localPlayer = Current_Local_Player();
    if (!localPlayer) return;
    
    void* weapon = GetWeaponOnHand1(localPlayer);
    if (!weapon) return;
    int baseDamage = *(int*)((uintptr_t)weapon + offset_BaseDamage);
    if (baseDamage == 0) return;
    Vector3 firePos = GetHeadPosition(localPlayer);
    int weaponID = GetWeapon(weapon);
    PlayerID playerID_Local = *(PlayerID*)((uintptr_t)localPlayer + offset_KFMGKCJMCAM);
    void* objectPool = *(void**)((uintptr_t)localPlayer + offset_GEGFCFDGGGP);
    if (!objectPool) return;
    void *Class_message_DamageInfo_c = Classdamageinfo;
    if(!Class_message_DamageInfo_c) return;
    //void *classchamayne = classgamevardefhaha;
   // auto damagePacket = (message_CHDLJFJCPFN_o2*)((void* (*)(void*))offsetsendaimkkll)(BNJIPPIIMDF1616);
  //  if (!damagePacket) return;
    
    auto damagePacket = (message_C2S_RUDP_TakeDamage_Req_o2*)((void* (*)(void*))offset_PNGAJBCPDNJ)(localPlayer);
    if (!damagePacket) return;
    
   
    
    
        auto damageBaseInfo = (DamageInfo2_o *)((void * (*)(void *))(BNJIPPIIMDF1616))(Class_message_DamageInfo_c);
          if (damageBaseInfo) {
    static bool hasStartedDamage = false;
    
    
            
    
    if (!hasStartedDamage) {
        ((void (*)(void*, void*))offset_SetStartDamage)(weapon, objectPool);
        ((void* (*)(void*))offset_PNGAJBCPDNJ)(localPlayer); // refresh
        hasStartedDamage = true;
    }
    
    





    
    Vector3 hitPos = GetHeadPosition(ClosestEnemy);
    void* headCollider = GetHeadCollider(ClosestEnemy);
    PlayerID playerID_Enemy = *(PlayerID*)((uintptr_t)ClosestEnemy + offset_KFMGKCJMCAM);
    
    void* sl3 = GKHECDLGAJA(localPlayer, objectPool);
        
        
    monoList<float*>* paramCheck = LCLHHHKFCFP(weapon, sl3, headCollider, false, damageBaseInfo);
        
        
        

    if (paramCheck && isEnemyInRangeWeapon(localPlayer, ClosestEnemy, weapon)) {
    
        
    
        damagePacket->AttackableEntityID = CFFPIACECIG(GetplayerID(ClosestEnemy));
        damagePacket->DamagerID = CFFPIACECIG(GetplayerID(localPlayer));
        damagePacket->DamageValue = baseDamage;
        damagePacket->HitBodyPart = SetDamage;
        damagePacket->WeaponDataID = weaponID;
        damagePacket->WeaponUniqueID = *(uint32_t*)((uint64_t)weapon + 0x10);
        damagePacket->FirePos = PackVector3Pos(firePos);
        damagePacket->TargetPos = PackVector3Pos(hitPos);
        damagePacket->CheckParams = paramCheck;
        
        
        
        
        
        
        GameFacade_Send(106, damagePacket, 2, 0); //106 là take damage
        
    }
}

}


*/
/*
int damageCooldown = 0;

int delayCounter = 2;
int delayLimit = 8;
int delayLimit2 = 0;
int DamageDelay = 2;


int damageCooldown = 0;   // jitna zyada, utna slow
int delayCounter = 2;     // shuruat me wait
int delayLimit = 8;       // max wait limit (zyada rakha to slow)
int delayLimit2 = 0;      // secondary delay
int DamageDelay = 4;      // har damage ke beech ka gap




int damageCooldown = 0;
int delayCounter   = 0;
int delayLimit     = 2;   // safe + fast
int delayLimit2    = 0;
int DamageDelay    = 2;   // safe + fast

*/
int damageCooldown = 0;
int delayCounter   = 0;
int delayLimit     = 2;   // safe + fast
int delayLimit2    = 0;
int DamageDelay    = 2;   // safe + fast


bool AimKill1;

//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//Aimkill By @Gohan52//
