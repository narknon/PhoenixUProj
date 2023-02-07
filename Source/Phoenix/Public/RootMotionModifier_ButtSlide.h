#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "UObject/NoExportTypes.h"
#include "RootMotionModifier_ButtSlide.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_ButtSlide : public URootMotionModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector LastVelocity;
    
    URootMotionModifier_ButtSlide();
};

