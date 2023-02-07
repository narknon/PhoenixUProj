#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Waterfall.generated.h"

UCLASS(Blueprintable)
class AWaterfall : public AActor {
    GENERATED_BODY()
public:
    AWaterfall();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StopWater();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartWater();
    
};

