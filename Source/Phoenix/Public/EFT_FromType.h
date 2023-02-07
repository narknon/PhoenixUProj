#pragma once
#include "CoreMinimal.h"
#include "EFT_FromType.generated.h"

UENUM(BlueprintType)
enum EFT_FromType {
    EFT_FromType_Normal,
    EFT_FromType_Map,
    EFT_FromType_Door,
    EFT_FromType_Mission,
    EFT_FromType_Floo,
    EFT_FromType_CrimeScene,
    EFT_FromType_SceneAction,
};

