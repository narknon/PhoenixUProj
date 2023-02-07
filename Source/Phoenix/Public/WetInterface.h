#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "WetInterface.generated.h"

class AActor;

UINTERFACE(Blueprintable, MinimalAPI)
class UWetInterface : public UInterface {
    GENERATED_BODY()
};

class IWetInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool StartWetness(AActor* Instigator, float Amount, FVector Location);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFailedToWet();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDry(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDecreaseWetness(float decreaseAmount);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAttemptToApplyWetness(float Amount, FVector Location);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool IncreaseWetness(AActor* Instigator, float increaseAmount, FVector Location);
    
};

