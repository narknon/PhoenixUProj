#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "Engine/EngineTypes.h"
#include "EManagedMovementModePriority.h"
#include "AblSetPhoenixCharacterMovementModeTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSetPhoenixCharacterMovementModeTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMovementMode> MovementMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EManagedMovementModePriority Priority;
    
    UAblSetPhoenixCharacterMovementModeTask();
};

