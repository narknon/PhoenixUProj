#pragma once
#include "CoreMinimal.h"
#include "AkSpeakerConfiguration.generated.h"

UENUM(BlueprintType)
enum class AkSpeakerConfiguration : uint8 {
    Ak_Speaker_Front_Left = 0x1,
    Ak_Speaker_Front_Right,
    Ak_Speaker_Front_Center = 0x4,
    Ak_Speaker_Low_Frequency = 0x8,
    Ak_Speaker_Back_Left = 0x10,
    Ak_Speaker_Back_Right = 0x20,
    Ak_Speaker_Back_Center = 0x100,
    Ak_Speaker_Side_Left = 0x200,
    Ak_Speaker_Side_Right = 0x400,
    Ak_Speaker_Top = 0x800,
    Ak_Speaker_Height_Front_Left = 0x1000,
    Ak_Speaker_Height_Front_Center = 0x2000,
    Ak_Speaker_Height_Front_Right = 0x4000,
    Ak_Speaker_Height_Back_Left = 0x8000,
    Ak_Speaker_Height_Back_Center = 0x10000,
    Ak_Speaker_Height_Back_Right = 0x20000,
    Ak_Speaker_MAX UMETA(Hidden),
};

