#pragma once
#include "CoreMinimal.h"
#include "SceneAction_ExternalRenderingCutBase.h"
#include "SceneAction_ExternalRenderingCut.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ExternalRenderingCut : public USceneAction_ExternalRenderingCutBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RenderingCuts;
    
    USceneAction_ExternalRenderingCut();
};

