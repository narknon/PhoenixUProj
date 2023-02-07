#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AvaRootMotionWarper.h"
#include "AnimNotifyState_AvaMotionWarp.generated.h"

class UAnimSequenceBase;
class UAvaMotionWarpWindowFinder;
class UAvaMotionWarpingModifierConfig;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AMBULATORY_API UAnimNotifyState_AvaMotionWarp : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAvaMotionWarpingModifierConfig* RootMotionModifierConfig;
    
    UAnimNotifyState_AvaMotionWarp();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddMotionWarpModifier(FAvaRootMotionWarper& InMotionWarper, UAvaMotionWarpWindowFinder* InWindowFinder, UAnimSequenceBase* InAnimation, float StartTime, float EndTime) const;
    
};

