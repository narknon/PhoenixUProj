#pragma once
#include "CoreMinimal.h"
#include "CogGroupTargetPoint.h"
#include "CogGroupTargetPoint_CollisionCenterOLD.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class COGNITION_API UCogGroupTargetPoint_CollisionCenterOLD : public UCogGroupTargetPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyCollidingComponents;
    
    UCogGroupTargetPoint_CollisionCenterOLD();
};

