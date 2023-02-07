#pragma once
#include "CoreMinimal.h"
#include "LerpParameterAtlas.h"
#include "NightLightRigLerpParameterAtlas.generated.h"

USTRUCT(BlueprintType)
struct DAYNIGHT_API FNightLightRigLerpParameterAtlas {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpParameterAtlas LerpAtlas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LerpT;
    
    FNightLightRigLerpParameterAtlas();
};

