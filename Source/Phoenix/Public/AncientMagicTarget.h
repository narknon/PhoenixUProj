#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AncientMagicTarget.generated.h"

UCLASS(Blueprintable)
class AAncientMagicTarget : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Discovered;
    
    AAncientMagicTarget();
    UFUNCTION(BlueprintCallable)
    void SetDebugVisible(bool DebugVisibleIn);
    
    UFUNCTION(BlueprintCallable)
    void Reset();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReset();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDiscover();
    
    UFUNCTION(BlueprintCallable)
    void Discover();
    
};

