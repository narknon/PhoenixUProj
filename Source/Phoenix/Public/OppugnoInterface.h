#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "OppugnoInterface.generated.h"

class AActor;

UINTERFACE(Blueprintable, MinimalAPI)
class UOppugnoInterface : public UInterface {
    GENERATED_BODY()
};

class IOppugnoInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOppugnoThrow(AActor* Instigator, AActor* Target, FVector Velocity);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOppugnoPull(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOppugnoImpact(AActor* Instigator, AActor* Target, AActor* HitObject);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOppugnoHold(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnOppugnoEnd(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnHitByOppugnoImpact(AActor* Instigator, AActor* Object);
    
};

