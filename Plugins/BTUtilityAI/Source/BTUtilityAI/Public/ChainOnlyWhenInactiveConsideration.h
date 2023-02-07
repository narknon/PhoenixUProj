#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ChainOnlyWhenInactiveConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UChainOnlyWhenInactiveConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierConsideration* Consideration;
    
    UChainOnlyWhenInactiveConsideration();
};

