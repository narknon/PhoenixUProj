#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ChainCombineConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UChainCombineConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UQualifierConsideration*> Considerations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCounterbalanceScoreDegradation;
    
    UChainCombineConsideration();
};

