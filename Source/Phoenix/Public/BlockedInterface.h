#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "EBlockTiming.h"
#include "BlockedInterface.generated.h"

class AActor;
class UInteractionArchitectAsset;

UINTERFACE(Blueprintable, MinimalAPI)
class UBlockedInterface : public UInterface {
    GENERATED_BODY()
};

class IBlockedInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlocked(AActor* Instigator, UInteractionArchitectAsset* DataAsset, EBlockTiming BlockedTiming, FGameplayTagContainer MunitionTagContainer, FVector Throw, FVector ImpactDirection);
    
};

