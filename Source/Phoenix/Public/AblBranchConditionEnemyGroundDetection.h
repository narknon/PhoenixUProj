#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "AblBranchConditionEnemyGroundDetection.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionEnemyGroundDetection : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OnGroundDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeCharacterHeightBounds;
    
public:
    UAblBranchConditionEnemyGroundDetection();
};

