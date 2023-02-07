#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_ConsoleRenderingVar.h"
#include "SceneActionState_RenderDocCaptureFrames.generated.h"

UCLASS(Blueprintable)
class USceneActionState_RenderDocCaptureFrames : public USceneActionState_ConsoleRenderingVar {
    GENERATED_BODY()
public:
    USceneActionState_RenderDocCaptureFrames();
};

