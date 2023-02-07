#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfActorCloseToOffspring.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfActorCloseToOffspring : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyCheckOwnOffspring;
    
    USelfActorCloseToOffspring();
};

