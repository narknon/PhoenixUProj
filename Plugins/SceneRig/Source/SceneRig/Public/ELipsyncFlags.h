#pragma once
#include "CoreMinimal.h"
#include "ELipsyncFlags.generated.h"

UENUM(BlueprintType)
enum class ELipsyncFlags : uint8 {
    NoLipsync,
    Lipsync,
    MouthOnlyLipsyncLocalizedLanguages,
    MouthOnlyLipsync,
};

