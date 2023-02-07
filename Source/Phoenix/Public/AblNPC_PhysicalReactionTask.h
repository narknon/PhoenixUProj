#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EImpactReactionStrength.h"
#include "ERagdollCOMLocationDrivingMode.h"
#include "ERagdollCOMRotationDrivingMode.h"
#include "ERagdollPoseDrivingMode.h"
#include "EPhysicalReactionTaskAction.h"
#include "ERagdollDrivingSetting.h"
#include "AblNPC_PhysicalReactionTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNPC_PhysicalReactionTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPhysicalReactionTaskAction Action;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EImpactReactionStrength ReactionStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBlendBackOnTaskEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERagdollDrivingSetting SetPoseDrivingMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERagdollPoseDrivingMode PoseDrivingMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PoseDrivingBlendDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetCenterOfMassDrivingModes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERagdollCOMLocationDrivingMode LocationDrivingMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERagdollCOMRotationDrivingMode RotationDrivingMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableCcd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CcdTime;
    
    UAblNPC_PhysicalReactionTask();
};

