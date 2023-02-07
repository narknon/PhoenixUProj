#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RevealInterface.generated.h"

class AActor;

UINTERFACE(Blueprintable, MinimalAPI)
class URevealInterface : public UInterface {
    GENERATED_BODY()
};

class IRevealInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool StartReveal(AActor* Instigator, bool ShowOccluded);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHiddenObjectRevealed(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHiddenObjectHinted(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEndReveal(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginRevealFade(AActor* Instigator);
    
};

