#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "ETargetID.h"
#include "ETargetType.h"
#include "EUseTargetTracker.h"
#include "AblBranchConditionTargetTracker_AnyValidTargets.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionTargetTracker_AnyValidTargets : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EUseTargetTracker::Type> UseTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReturnTrueIfTargetListEmptyThisFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETargetID::Type> MatchTargetID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETargetType::Type> MatchTargetType;
    
public:
    UAblBranchConditionTargetTracker_AnyValidTargets();
};

