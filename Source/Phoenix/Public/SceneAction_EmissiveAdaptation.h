#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsEmissiveAdaptation.h"
#include "SceneAction_EmissiveAdaptationBase.h"
#include "SceneAction_EmissiveAdaptation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_EmissiveAdaptation : public USceneAction_EmissiveAdaptationBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsEmissiveAdaptation EmissiveAdaptation;
    
    USceneAction_EmissiveAdaptation();
};

