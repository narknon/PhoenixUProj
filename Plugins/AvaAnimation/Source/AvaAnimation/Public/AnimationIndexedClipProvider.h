#pragma once
#include "CoreMinimal.h"
#include "AnimationClipProvider.h"
#include "AnimationIndexedClipProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class AVAANIMATION_API UAnimationIndexedClipProvider : public UAnimationClipProvider {
    GENERATED_BODY()
public:
    UAnimationIndexedClipProvider();
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SetIndex(int32 Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetIndex() const;
    
};

