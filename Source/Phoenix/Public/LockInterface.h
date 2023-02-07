#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "LockInterface.generated.h"

class UPrimitiveComponent;

UINTERFACE(Blueprintable, MinimalAPI)
class ULockInterface : public UInterface {
    GENERATED_BODY()
};

class ILockInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUnlocked();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLocked();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFailedToUnlock();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool CanUnlock(UPrimitiveComponent* Comp, FVector Location);
    
};

