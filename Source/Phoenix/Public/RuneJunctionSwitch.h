#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RuneJunctionSwitch.generated.h"

class ARuneSwitch;

UCLASS(Blueprintable)
class ARuneJunctionSwitch : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsUnderHeat;
    
    ARuneJunctionSwitch();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RuneHitBySpell(ARuneSwitch* RuneSwitch);
    
};

