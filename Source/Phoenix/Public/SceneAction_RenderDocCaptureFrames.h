#pragma once
#include "CoreMinimal.h"
#include "SceneAction_ConsoleRenderingVar.h"
#include "SceneAction_RenderDocCaptureFrames.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_RenderDocCaptureFrames : public USceneAction_ConsoleRenderingVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Frames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCaptureInSceneRigEditor;
    
    USceneAction_RenderDocCaptureFrames();
};

