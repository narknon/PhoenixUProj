#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "ImmunityInterface.generated.h"

class AActor;

UINTERFACE(Blueprintable, MinimalAPI)
class UImmunityInterface : public UInterface {
    GENERATED_BODY()
};

class IImmunityInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ImmunityActivated(AActor* Instigator, FGameplayTagContainer Immunity);
    
};

