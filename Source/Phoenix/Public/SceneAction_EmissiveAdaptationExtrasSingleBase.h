#pragma once
#include "CoreMinimal.h"
#include "SceneAction_EmissiveAdaptationBase.h"
#include "SceneAction_EmissiveAdaptationExtrasSingleBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_EmissiveAdaptationExtrasSingleBase : public USceneAction_EmissiveAdaptationBase {
    GENERATED_BODY()
public:
    USceneAction_EmissiveAdaptationExtrasSingleBase();
};

