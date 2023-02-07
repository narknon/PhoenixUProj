#pragma once
#include "CoreMinimal.h"
#include "CogGroupTargetPoint.h"
#include "CogGroupTargetPoint_ClosestPointOnCollision.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class COGNITION_API UCogGroupTargetPoint_ClosestPointOnCollision : public UCogGroupTargetPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinZHeightFromActorLocation;
    
    UCogGroupTargetPoint_ClosestPointOnCollision();
};

