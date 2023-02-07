#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "RootMotionModifierProperties_EdgeCheck.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_EdgeCheck : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DetectMaxDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ComputeEdgeAtThreshhold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugDraw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SafeDistanceFromEdge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EdgeOffsetSpeed;
    
    URootMotionModifierProperties_EdgeCheck();
};

