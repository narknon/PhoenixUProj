#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "Templates/SubclassOf.h"
#include "OptionActorIsPlayerWithActiveInventoryToolConsideration.generated.h"

class ATool;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorIsPlayerWithActiveInventoryToolConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ATool> ToolClass;
    
    UOptionActorIsPlayerWithActiveInventoryToolConsideration();
};

