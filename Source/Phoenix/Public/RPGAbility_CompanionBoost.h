#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "RPGAbility.h"
#include "RPGAbility_CompanionBoost.generated.h"

class UGameplayPropertyMod;
class URPGAbilityBase;

UCLASS(Blueprintable)
class URPGAbility_CompanionBoost : public URPGAbility {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameplayPropertyMod*> ModsForCompanions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<URPGAbilityBase*> AbilitiesForCompanions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AbilityTagsForCompanions;
    
public:
    URPGAbility_CompanionBoost();
};

