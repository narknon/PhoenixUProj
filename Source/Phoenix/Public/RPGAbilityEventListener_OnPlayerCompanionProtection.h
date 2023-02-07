#pragma once
#include "CoreMinimal.h"
#include "RPGAbilityEventListener.h"
#include "RPGAbilityEventListener_OnPlayerCompanionProtection.generated.h"

class UObject;

UCLASS(Blueprintable, EditInlineNew)
class URPGAbilityEventListener_OnPlayerCompanionProtection : public URPGAbilityEventListener {
    GENERATED_BODY()
public:
    URPGAbilityEventListener_OnPlayerCompanionProtection();
protected:
    UFUNCTION(BlueprintCallable)
    void OnCastCompanionProtego(const UObject* Caller);
    
};

