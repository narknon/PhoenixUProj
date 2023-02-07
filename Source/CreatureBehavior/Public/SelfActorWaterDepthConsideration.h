#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfActorWaterDepthConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfActorWaterDepthConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDepth;
    
public:
    USelfActorWaterDepthConsideration();
};

