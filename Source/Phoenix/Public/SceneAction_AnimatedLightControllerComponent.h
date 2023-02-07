#pragma once
#include "CoreMinimal.h"
#include "SceneAction_SpawnActorAllowAsChild.h"
#include "SceneAction_AnimatedLightControllerComponent.generated.h"

class UAnimatedLightsClusterSettings;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AnimatedLightControllerComponent : public USceneAction_SpawnActorAllowAsChild {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimatedLightsClusterSettings* CullingSettings;
    
    USceneAction_AnimatedLightControllerComponent();
};

