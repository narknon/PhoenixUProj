#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierUltimate.h"
#include "RootMotionModifierUltimate_SplineLock.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifierUltimate_SplineLock : public URootMotionModifierUltimate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float SplineRightOffset;
    
    URootMotionModifierUltimate_SplineLock();
};

