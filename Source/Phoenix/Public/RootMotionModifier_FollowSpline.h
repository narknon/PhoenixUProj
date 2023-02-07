#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "RootMotionModifier_FollowSpline.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_FollowSpline : public URootMotionModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Speed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float InitialMaxOffsetRadius;
    
    URootMotionModifier_FollowSpline();
};

