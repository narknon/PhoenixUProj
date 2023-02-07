#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ChainOnlyWhenNamedActionIsActiveConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UChainOnlyWhenNamedActionIsActiveConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NamedAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierConsideration* Consideration;
    
    UChainOnlyWhenNamedActionIsActiveConsideration();
};

