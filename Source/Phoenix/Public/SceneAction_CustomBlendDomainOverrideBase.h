#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_CustomBlendDomainOverrideBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_CustomBlendDomainOverrideBase : public USceneRigActionBase {
    GENERATED_BODY()
public:
    USceneAction_CustomBlendDomainOverrideBase();
};

