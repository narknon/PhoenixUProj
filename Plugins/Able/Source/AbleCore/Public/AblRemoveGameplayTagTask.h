#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AblAbilityTask.h"
#include "AblRemoveGameplayTagTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblRemoveGameplayTagTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTag> m_TagList;
    
public:
    UAblRemoveGameplayTagTask();
};

