#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "RootMotionModifierProperties_StopAtEdge.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_StopAtEdge : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceStartUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceEndDown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DesiredDistanceFromEdge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebug;
    
    URootMotionModifierProperties_StopAtEdge();
};

