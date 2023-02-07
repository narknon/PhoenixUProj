#pragma once
#include "CoreMinimal.h"
#include "AnimationClipProvider.h"
#include "BPAnimationClipProvider.generated.h"

class UAnimSequenceBase;
class UObject;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UBPAnimationClipProvider : public UAnimationClipProvider {
    GENERATED_BODY()
public:
    UBPAnimationClipProvider();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool GetAnimationClipBP(const UObject* Caller, UAnimSequenceBase*& OutAnimClip) const;
    
};

