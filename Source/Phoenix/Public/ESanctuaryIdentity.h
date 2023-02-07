#pragma once
#include "CoreMinimal.h"
#include "ESanctuaryIdentity.generated.h"

UENUM(BlueprintType)
enum class ESanctuaryIdentity : uint8 {
    Default,
    Potioneer,
    Herbologist,
    Magizoologist,
    DarkWizard,
    NUM,
};

