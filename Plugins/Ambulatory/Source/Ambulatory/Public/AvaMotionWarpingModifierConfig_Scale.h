#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AvaMotionWarpingModifierConfig.h"
#include "AvaRootMotionWarper.h"
#include "AvaMotionWarpingModifierConfig_Scale.generated.h"

class UAnimSequenceBase;
class UAvaMotionWarpWindowFinder;

UCLASS(Blueprintable, EditInlineNew)
class AMBULATORY_API UAvaMotionWarpingModifierConfig_Scale : public UAvaMotionWarpingModifierConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Scale;
    
    UAvaMotionWarpingModifierConfig_Scale();
    UFUNCTION(BlueprintCallable)
    static void AddRootMotionModifierScale(FAvaRootMotionWarper& InMotionWarper, UAvaMotionWarpWindowFinder* InWindowFinder, const UAnimSequenceBase* InAnimation, float InStartTime, float InEndTime, FVector InScale);
    
};

