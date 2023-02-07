#pragma once
#include "CoreMinimal.h"
#include "LightComponentStates.generated.h"

class ULightComponentState;

USTRUCT(BlueprintType)
struct FLightComponentStates {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULightComponentState*> States;
    
    PHOENIX_API FLightComponentStates();
};

