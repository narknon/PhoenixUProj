#pragma once
#include "CoreMinimal.h"
#include "DynamicCharacterLightRigFillLight.generated.h"

USTRUCT(BlueprintType)
struct FDynamicCharacterLightRigFillLight {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AwayIntensityPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TowardsIntensityPercent;
    
    RENDERSETTINGS_API FDynamicCharacterLightRigFillLight();
};

