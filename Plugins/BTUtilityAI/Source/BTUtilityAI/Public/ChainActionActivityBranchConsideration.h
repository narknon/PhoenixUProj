#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ChainActionActivityBranchConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UChainActionActivityBranchConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString WhenActiveDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierConsideration* ConsiderationWhenActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString WhenInactiveDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierConsideration* ConsiderationWhenInactive;
    
    UChainActionActivityBranchConsideration();
};

