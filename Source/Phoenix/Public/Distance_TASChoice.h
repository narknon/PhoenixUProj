#pragma once
#include "CoreMinimal.h"
#include "ENPC_TurnAssistState.h"
#include "NPC_TurnAssistStateChoice.h"
#include "Distance_TASChoice.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UDistance_TASChoice : public UNPC_TurnAssistStateChoice {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_TurnAssistState TargetCriteriaNotMetState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartMaxAngleToDest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ContinueMaxAngleToDest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartMinDistToDest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ContinueMinDistToDest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartMinDistToTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ContinueMinDistToTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartAngleOverrideMinDistToTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ContinueAngleOverrideMinDistToTarget;
    
    UDistance_TASChoice();
};

