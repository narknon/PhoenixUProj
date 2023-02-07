#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfTimeSinceActionEndConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API USelfTimeSinceActionEndConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WindowOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WindowSize;
    
    USelfTimeSinceActionEndConsideration();
};

