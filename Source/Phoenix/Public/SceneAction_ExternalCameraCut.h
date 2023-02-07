#pragma once
#include "CoreMinimal.h"
#include "SceneAction_ExternalRenderingCutBase.h"
#include "SceneAction_ExternalCameraCut.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ExternalCameraCut : public USceneAction_ExternalRenderingCutBase {
    GENERATED_BODY()
public:
    USceneAction_ExternalCameraCut();
};

