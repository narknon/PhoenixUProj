#pragma once
#include "CoreMinimal.h"
#include "EmissiveAdaptationLerpSettings.h"
#include "EmissiveAdaptationWorldState.h"
#include "EmissiveAdaptationStateCompute.generated.h"

USTRUCT(BlueprintType)
struct FEmissiveAdaptationStateCompute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmissiveAdaptationWorldState WorldState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmissiveAdaptationLerpSettings VolumeSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PPBloomIntensity;
    
    RENDERSETTINGS_API FEmissiveAdaptationStateCompute();
};

