#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ScoreOverrideReturnConfiguration.h"
#include "ChainMultiplierCompareScoreOverrideConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UChainMultiplierCompareScoreOverrideConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierConsideration* ConsiderationA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierConsideration* ConsiderationB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScoreOverrideReturnConfiguration ALargerThanB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScoreOverrideReturnConfiguration AEqualToB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScoreOverrideReturnConfiguration ASmallerThanB;
    
    UChainMultiplierCompareScoreOverrideConsideration();
};

