#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "UObject/NoExportTypes.h"
#include "AlphaBlend.h"
#include "AblNPCTurnToTaskScratchPad.generated.h"

class AActor;

UCLASS(Blueprintable, NonTransient)
class UAblNPCTurnToTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* ActorToTrack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator TargetRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAlphaBlend TurningBlend;
    
    UAblNPCTurnToTaskScratchPad();
};

