#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehavior.h"
#include "CameraStackBehaviorBlend.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorBlend : public UCameraStackBehavior {
    GENERATED_BODY()
public:
    UCameraStackBehaviorBlend();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBlendAlpha() const;
    
};

