#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ChainEliminateScoreBelowActiveInactiveThresholdConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UChainEliminateScoreBelowActiveInactiveThresholdConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThesholdWhenActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThesholdWhenInactive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierConsideration* Consideration;
    
    UChainEliminateScoreBelowActiveInactiveThresholdConsideration();
};

