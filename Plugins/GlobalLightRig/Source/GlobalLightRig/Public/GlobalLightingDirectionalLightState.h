#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightParameters.h"
#include "GlobalLightingDirectionalLightDirection.h"
#include "GlobalLightingDirectionalLightState.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightingDirectionalLightState : public FGlobalLightingDirectionalLightDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightParameters Parameters;
    
    GLOBALLIGHTRIG_API FGlobalLightingDirectionalLightState();
};

