#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "Engine/EngineTypes.h"
#include "AblBranchConditionMovementMode.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAblBranchConditionMovementMode : public UAblTaskCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMovementMode> MovementMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDuration;
    
public:
    UAblBranchConditionMovementMode();
};

