#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfIsTaggedByGroupCoordinationConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfIsTaggedByGroupCoordinationConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TagID;
    
    USelfIsTaggedByGroupCoordinationConsideration();
};

