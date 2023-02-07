#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorBonusForPreferedParentConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorBonusForPreferedParentConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BonusForParent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BonusForMother;
    
    UOptionActorBonusForPreferedParentConsideration();
};

