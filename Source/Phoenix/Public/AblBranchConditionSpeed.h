#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "UObject/NoExportTypes.h"
#include "ESpeedInclusivity.h"
#include "ESpeedType.h"
#include "AblBranchConditionSpeed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionSpeed : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ESpeedType::Type> SpeedType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D SpeedRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ESpeedInclusivity::Type> Inclusivity;
    
public:
    UAblBranchConditionSpeed();
};

