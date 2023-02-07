#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Templates/SubclassOf.h"
#include "Ability_Character_Interface.generated.h"

class UAblAbility;

UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UAbility_Character_Interface : public UInterface {
    GENERATED_BODY()
};

class IAbility_Character_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    virtual void StopCustomAbility() PURE_VIRTUAL(StopCustomAbility,);
    
    UFUNCTION(BlueprintCallable)
    virtual void PlayCustomAbility(TSubclassOf<UAblAbility> InAbility, bool bPreventReactions) PURE_VIRTUAL(PlayCustomAbility,);
    
};

