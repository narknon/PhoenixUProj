#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "Name_GameLogicPropFloat.h"
#include "FXAutoTriggerScalarGameLogicPropositional.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarGameLogicPropositional : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicPropFloat Propositional;
    
    UFXAutoTriggerScalarGameLogicPropositional();
};

