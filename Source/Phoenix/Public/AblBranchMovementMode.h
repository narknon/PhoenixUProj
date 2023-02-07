#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "Engine/EngineTypes.h"
#include "AblBranchMovementMode.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchMovementMode : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EMovementMode>> MovementModes;
    
public:
    UAblBranchMovementMode();
};

