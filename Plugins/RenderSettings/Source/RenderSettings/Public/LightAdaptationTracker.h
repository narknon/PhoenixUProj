#pragma once
#include "CoreMinimal.h"
#include "EmissiveAdaptationFinalState.h"
#include "LightAdaptationTracker.generated.h"

class ULightAdaptationComponent;

USTRUCT(BlueprintType)
struct FLightAdaptationTracker {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ULightAdaptationComponent>> Components;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmissiveAdaptationFinalState LastState;
    
    RENDERSETTINGS_API FLightAdaptationTracker();
};

