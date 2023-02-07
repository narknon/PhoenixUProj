#pragma once
#include "CoreMinimal.h"
#include "SceneAction_ConsoleRenderingVar.h"
#include "SceneAction_TestCameraCut.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_TestCameraCut : public USceneAction_ConsoleRenderingVar {
    GENERATED_BODY()
public:
    USceneAction_TestCameraCut();
};

