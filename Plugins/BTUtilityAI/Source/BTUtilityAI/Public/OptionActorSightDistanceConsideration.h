#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorSightDistanceConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UOptionActorSightDistanceConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseLoseSightDistance;
    
    UOptionActorSightDistanceConsideration();
};

