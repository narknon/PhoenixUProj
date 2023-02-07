#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DirectionalLightParameters.h"
#include "GlobalLightingDirectionalLightBlendState.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightingDirectionalLightBlendState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightParameters Parameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuat Rotation;
    
    GLOBALLIGHTRIG_API FGlobalLightingDirectionalLightBlendState();
};

