#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_LightCullingSettings.generated.h"

class ULightCullingSettings;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_LightCullingSettings : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULightCullingSettings* Settings;
    
    USceneAction_LightCullingSettings();
};

