#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AblAbilityTask.h"
#include "AblSetGameplayTagTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblSetGameplayTagTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTag> m_TagList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_RemoveOnEnd;
    
public:
    UAblSetGameplayTagTask();
};

