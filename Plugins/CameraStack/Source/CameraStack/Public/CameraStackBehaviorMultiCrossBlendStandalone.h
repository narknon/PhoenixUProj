#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorMultiCrossBlend.h"
#include "CameraStackMultiCrossBlendGroupTemplate.h"
#include "CameraStackBehaviorMultiCrossBlendStandalone.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, HideDropdown)
class CAMERASTACK_API UCameraStackBehaviorMultiCrossBlendStandalone : public UCameraStackBehaviorMultiCrossBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCameraStackMultiCrossBlendGroupTemplate> GroupTemplates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdateWeightsFromImplementation;
    
    UCameraStackBehaviorMultiCrossBlendStandalone();
};

