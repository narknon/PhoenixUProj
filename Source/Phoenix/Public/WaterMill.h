#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WaterMill.generated.h"

UCLASS(Blueprintable)
class AWaterMill : public AActor {
    GENERATED_BODY()
public:
    AWaterMill();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DeactivateWaterMill();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ActivateWaterMill();
    
};

