#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ECreatureNurtureInteractRange.h"
#include "OptionActorWithinNurtureInteractRangeConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorWithinNurtureInteractRangeConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureNurtureInteractRange NurtureInteractRange;
    
public:
    UOptionActorWithinNurtureInteractRangeConsideration();
};

