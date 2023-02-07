#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "AblCanRagdollRecoverBranchCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblCanRagdollRecoverBranchCondition : public UAblTaskCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckForRecoverOnGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckForRecoverInWater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckForRecoverInAir;
    
public:
    UAblCanRagdollRecoverBranchCondition();
};

