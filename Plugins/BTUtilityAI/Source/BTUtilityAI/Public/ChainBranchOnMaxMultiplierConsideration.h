#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ChainBranchOnMaxMultiplierConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UChainBranchOnMaxMultiplierConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierConsideration* ConsiderationA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierConsideration* ConsiderationB;
    
    UChainBranchOnMaxMultiplierConsideration();
};

