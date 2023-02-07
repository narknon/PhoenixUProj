#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ChainPickMaxMultiplierConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UChainPickMaxMultiplierConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UQualifierConsideration*> Considerations;
    
    UChainPickMaxMultiplierConsideration();
};

