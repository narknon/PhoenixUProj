#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "UObject/NoExportTypes.h"
#include "RootMotionModifier_Slide.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_Slide : public URootMotionModifier {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector CurrentVelocity;
    
public:
    URootMotionModifier_Slide();
};

