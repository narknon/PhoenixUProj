#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EAblGaitSpeed.h"
#include "AblBranchConditionDiscreteSpeedChanged.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionDiscreteSpeedChanged : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpeedsMustMatch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EAblGaitSpeed> LastGaitSpeeds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EAblGaitSpeed> NewGaitSpeeds;
    
public:
    UAblBranchConditionDiscreteSpeedChanged();
};

