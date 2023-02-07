#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "GameplayTagContainer.h"
#include "AblReactionsDamageTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblReactionsDamageTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseTagsFromReactionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AdditionalGameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Damage;
    
    UAblReactionsDamageTask();
};

