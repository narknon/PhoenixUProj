#pragma once
#include "CoreMinimal.h"
#include "ArchitectType.h"
#include "GameplayTagContainer.h"
#include "AblAbilityTask.h"
#include "AblSetArchitectTagsTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblSetArchitectTagsTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ArchitectTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RemoveTagsAtEndOfTask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AddTheseTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RemoveTheseTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ArchitectType> Type;
    
public:
    UAblSetArchitectTagsTask();
};

