#pragma once
#include "CoreMinimal.h"
#include "EActor_LoadDBProcessingType.generated.h"

UENUM(BlueprintType)
enum EActor_LoadDBProcessingType {
    LoadProcessingType_None,
    LoadProcessingType_NPC,
    LoadProcessingType_ObjectState,
    LoadProcessingType_MAX UMETA(Hidden),
};

