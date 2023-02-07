#pragma once
#include "CoreMinimal.h"
#include "SceneAction_AnimatedLightControllerComponent.h"
#include "SceneAction_FlickeringLightControllerComponent.generated.h"

class UAnimatedLightSettingsAsset;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_FlickeringLightControllerComponent : public USceneAction_AnimatedLightControllerComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimatedLightSettingsAsset* Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DurationScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bRandomizeStartOffset: 1;
    
    USceneAction_FlickeringLightControllerComponent();
};

