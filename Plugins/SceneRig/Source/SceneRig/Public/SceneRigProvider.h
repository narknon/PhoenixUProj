#pragma once
#include "CoreMinimal.h"
#include "ObjectProvider.h"
#include "SceneRigProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class SCENERIG_API USceneRigProvider : public UObjectProvider {
    GENERATED_BODY()
public:
    USceneRigProvider();
};

