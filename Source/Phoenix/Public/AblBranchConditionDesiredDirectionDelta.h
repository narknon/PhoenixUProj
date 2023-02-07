#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "UObject/NoExportTypes.h"
#include "EDesiredDeltaOperator.h"
#include "EDesiredDeltaSourceDirection.h"
#include "EDesiredDeltaTargetTracker.h"
#include "AblBranchConditionDesiredDirectionDelta.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionDesiredDirectionDelta : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EDesiredDeltaSourceDirection::Type> UseSourceDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EDesiredDeltaTargetTracker::Type> UseTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BufferSampleTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAbsoulteValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EDesiredDeltaOperator::Type> UseOperator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D AngleRange;
    
public:
    UAblBranchConditionDesiredDirectionDelta();
};

