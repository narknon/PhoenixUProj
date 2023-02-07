#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "ECreatureFleeFlyingOption.h"
#include "SelfCreatureFleeFlyingConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfCreatureFleeFlyingConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureFleeFlyingOption FleeFlyingOption;
    
    USelfCreatureFleeFlyingConsideration();
};

