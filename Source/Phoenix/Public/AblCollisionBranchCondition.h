#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "EAblCollisionBranchDetectionType.h"
#include "Templates/SubclassOf.h"
#include "AblCollisionBranchCondition.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class UAblCollisionBranchCondition : public UAblTaskCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAblCollisionBranchDetectionType DetectionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DotProductLowerBound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DotProductUpperBound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BranchOnImminentCollisionLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckForInheritance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AActor>> OtherActorMustBeA;
    
public:
    UAblCollisionBranchCondition();
};

