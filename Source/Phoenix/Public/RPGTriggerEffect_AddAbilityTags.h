#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "RPGTriggerEffect_Conditional.h"
#include "RPGTriggerEffect_AddAbilityTags.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_AddAbilityTags : public URPGTriggerEffect_Conditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AbilityTags;
    
public:
    URPGTriggerEffect_AddAbilityTags();
};

