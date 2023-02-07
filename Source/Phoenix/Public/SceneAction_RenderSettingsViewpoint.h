#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_RenderSettingsViewpoint.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_RenderSettingsViewpoint : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostProcessingViewpoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SmoothChangeTimePercent;
    
    USceneAction_RenderSettingsViewpoint();
};

