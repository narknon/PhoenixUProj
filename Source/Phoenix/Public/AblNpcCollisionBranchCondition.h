#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EAblNpcCollisionDetectionType.h"
#include "AblNpcCollisionBranchCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNpcCollisionBranchCondition : public UAblBranchCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAblNpcCollisionDetectionType DetectionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DotProductLowerBound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DotProductUpperBound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BranchOnImminentCollisionLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinSpeed;
    
    UAblNpcCollisionBranchCondition();
};

