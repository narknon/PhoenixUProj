#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "AblLeavingNavMeshTaskCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblLeavingNavMeshTaskCondition : public UAblTaskCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DotProductCheck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckForCollision;
    
public:
    UAblLeavingNavMeshTaskCondition();
};

