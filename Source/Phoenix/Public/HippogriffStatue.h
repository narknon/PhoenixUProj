#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HippogriffStatue.generated.h"

UCLASS(Blueprintable)
class AHippogriffStatue : public AActor {
    GENERATED_BODY()
public:
    AHippogriffStatue();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RepairAll();
    
};

