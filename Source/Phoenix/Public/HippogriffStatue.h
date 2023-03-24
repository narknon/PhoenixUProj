#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HippogriffStatue.generated.h"

UCLASS(Blueprintable)
class AHippogriffStatue : public AActor {
    GENERATED_BODY()
public:
    AHippogriffStatue(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RepairAll();
    
};

