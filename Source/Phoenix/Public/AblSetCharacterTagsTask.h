#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "GameplayTagContainer.h"
#include "AblSetCharacterTagsTask.generated.h"

class UAblTaskCondition;

UCLASS(Blueprintable, EditInlineNew)
class UAblSetCharacterTagsTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer CharacterTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RemoveTagsAtEndOfTask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AddTheseTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RemoveTheseTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskCondition*> TaskConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMustPassAllConditions;
    
public:
    UAblSetCharacterTagsTask();
};

