#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "EAblGaitSpeed.h"
#include "ESpeedType.h"
#include "AblBranchConditionGaitSpeed_New.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAblBranchConditionGaitSpeed_New : public UAblTaskCondition {
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
    UAblBranchConditionGaitSpeed_New();
};

