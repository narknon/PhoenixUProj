#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Base_Character_Interface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UBase_Character_Interface : public UInterface {
    GENERATED_BODY()
};

class IBase_Character_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUnFreeze();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnResetFullRagdoll();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFreeze();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnableFullRagdoll();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAboutToDie();
    
};

