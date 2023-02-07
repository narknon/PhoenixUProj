#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfActorHasActorTagConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API USelfActorHasActorTagConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TagName;
    
    USelfActorHasActorTagConsideration();
};

