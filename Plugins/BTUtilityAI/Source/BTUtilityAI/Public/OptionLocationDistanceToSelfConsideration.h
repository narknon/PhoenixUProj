#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionLocationDistanceToSelfConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UOptionLocationDistanceToSelfConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartRangeOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EndRangeOffset;
    
    UOptionLocationDistanceToSelfConsideration();
};

