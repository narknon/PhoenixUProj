#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationSettings.h"
#include "SceneAction_AnimatedLightControllerComponent.h"
#include "SceneAction_AdaptiveLightControllerComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AdaptiveLightControllerComponent : public USceneAction_AnimatedLightControllerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDynamicLightAdaptationSettings Settings;
    
    USceneAction_AdaptiveLightControllerComponent();
};

