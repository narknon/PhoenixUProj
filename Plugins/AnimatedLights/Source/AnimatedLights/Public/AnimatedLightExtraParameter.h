#pragma once
#include "CoreMinimal.h"
#include "Engine/Scene.h"
#include "EAnimatedLightExtraParameterValue.h"
#include "AnimatedLightExtraParameter.generated.h"

USTRUCT(BlueprintType)
struct FAnimatedLightExtraParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToleranceThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimatedLightExtraParameterValue Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightUnits OutputIntensityUnits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOnlyUpdateOnce: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseOutputIntensityUnits: 1;
    
    ANIMATEDLIGHTS_API FAnimatedLightExtraParameter();
};

