#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ChainAtMultiplierThresholdConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UChainAtMultiplierThresholdConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MultiplierThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierConsideration* TestConsideration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierConsideration* ChainConsideration;
    
    UChainAtMultiplierThresholdConsideration();
};

