#pragma once
#include "CoreMinimal.h"
#include "AkChannelConfiguration.generated.h"

UENUM(BlueprintType)
enum class AkChannelConfiguration : uint8 {
    Ak_Parent,
    Ak_MainMix,
    Ak_Passthrough,
    Ak_LFE,
    AK_Audio_Objects,
    Ak_1_0,
    Ak_2_0,
    Ak_2_1,
    Ak_3_0,
    Ak_3_1,
    Ak_4_0,
    Ak_4_1,
    Ak_5_0,
    Ak_5_1,
    Ak_7_1,
    Ak_5_1_2,
    Ak_7_1_2,
    Ak_7_1_4,
    Ak_Auro_9_1,
    Ak_Auro_10_1,
    Ak_Auro_11_1,
    Ak_Auro_13_1,
    Ak_Ambisonics_1st_order,
    Ak_Ambisonics_2nd_order,
    Ak_Ambisonics_3rd_order,
    Ak_Ambisonics_4th_order,
    Ak_Ambisonics_5th_order,
};

