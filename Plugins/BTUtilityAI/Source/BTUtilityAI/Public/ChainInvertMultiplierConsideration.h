#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ChainInvertMultiplierConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UChainInvertMultiplierConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierConsideration* Consideration;
    
    UChainInvertMultiplierConsideration();
};

