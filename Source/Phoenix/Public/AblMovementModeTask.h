#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "Engine/EngineTypes.h"
#include "AblMovementModeTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblMovementModeTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMovementMode> StartMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseEndMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMovementMode> EndMovement;
    
public:
    UAblMovementModeTask();
};

