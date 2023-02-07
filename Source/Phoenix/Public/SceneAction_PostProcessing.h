#pragma once
#include "CoreMinimal.h"
#include "Engine/Scene.h"
#include "BlendDomain.h"
#include "SceneAction_PostProcessingBaseFeatherInOut.h"
#include "SceneAction_PostProcessing.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_PostProcessing : public USceneAction_PostProcessingBaseFeatherInOut {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostProcessSettings PostProcessSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    USceneAction_PostProcessing();
};

