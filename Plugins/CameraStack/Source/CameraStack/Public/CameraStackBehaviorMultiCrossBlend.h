#pragma once
#include "CoreMinimal.h"
#include "CameraCrossBlendBehaviorGroup.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorMultiCrossBlend.generated.h"

class UCameraStack;
class UCameraStackBehaviorMultiCrossBlend;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, HideDropdown)
class CAMERASTACK_API UCameraStackBehaviorMultiCrossBlend : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxCrossBlendSpeed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCameraCrossBlendBehaviorGroup> CrossBlendBehaviorGroups;
    
public:
    UCameraStackBehaviorMultiCrossBlend();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FCameraCrossBlendBehaviorGroup> GetCrossBlendBehaviorGroups() const;
    
    UFUNCTION(BlueprintCallable)
    static UCameraStackBehaviorMultiCrossBlend* CreateMultiCrossBlendBehavior(UCameraStack* InCameraStack, float InMaxCrossBlendSpeed);
    
};

