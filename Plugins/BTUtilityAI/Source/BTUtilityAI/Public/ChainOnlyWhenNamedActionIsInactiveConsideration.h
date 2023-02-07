#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ChainOnlyWhenNamedActionIsInactiveConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UChainOnlyWhenNamedActionIsInactiveConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NamedAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQualifierConsideration* Consideration;
    
    UChainOnlyWhenNamedActionIsInactiveConsideration();
};

