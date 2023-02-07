#pragma once
#include "CoreMinimal.h"
#include "CogGroupTargetPoint.h"
#include "CogGroupTargetPoint_CollisionCenter.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class COGNITION_API UCogGroupTargetPoint_CollisionCenter : public UCogGroupTargetPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyCollidingComponents;
    
    UCogGroupTargetPoint_CollisionCenter();
};

