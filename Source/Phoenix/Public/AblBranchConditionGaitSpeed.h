#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EAblGaitSpeed.h"
#include "ESpeedType.h"
#include "AblBranchConditionGaitSpeed.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAblBranchConditionGaitSpeed : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EAblGaitSpeed> GaitSpeeds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ESpeedType::Type> SpeedType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BufferSampleTime;
    
public:
    UAblBranchConditionGaitSpeed();
};

