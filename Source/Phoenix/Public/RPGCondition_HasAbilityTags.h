#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "RPGCondition.h"
#include "RPGCondition_HasAbilityTags.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGCondition_HasAbilityTags : public URPGCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AbilityTags;
    
public:
    URPGCondition_HasAbilityTags();
};

