#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ECreatureHappinessLevel.h"
#include "SelfHappinessLevel.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfHappinessLevel : public UQualifierConsideration {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureHappinessLevel HappinessLevel;
    
public:
    USelfHappinessLevel();
};

