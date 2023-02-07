#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfBlackboardBool.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfBlackboardBool : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BlackboardKeyName;
    
    USelfBlackboardBool();
};

