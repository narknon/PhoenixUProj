#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ProtegoDeflection.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ProtegoDeflection : uint8 {
    None,
    DeflectBlock,
    DeflectRandom,
    DeflectTarget,
    DeflectBack,
    DeflectDeflect,
    DeflectCounter,
    EEnemy_MAX UMETA(Hidden),
};

