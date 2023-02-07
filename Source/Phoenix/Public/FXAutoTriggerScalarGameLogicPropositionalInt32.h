#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "Name_GameLogicPropInt32.h"
#include "FXAutoTriggerScalarGameLogicPropositionalInt32.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarGameLogicPropositionalInt32 : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicPropInt32 Propositional;
    
    UFXAutoTriggerScalarGameLogicPropositionalInt32();
};

