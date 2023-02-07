#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorBlackboardBool.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorBlackboardBool : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BlackboardKeyName;
    
    UOptionActorBlackboardBool();
};

