#pragma once
#include "CoreMinimal.h"
#include "ERenderSettingsEditAssetType.generated.h"

UENUM(BlueprintType)
enum class ERenderSettingsEditAssetType : uint8 {
    Library,
    PostProcessingGroups,
    Exposure,
    ColorGrading,
    DistanceFog,
    EmissiveAdaptation,
    CharacterLightRig,
    Probes,
};

