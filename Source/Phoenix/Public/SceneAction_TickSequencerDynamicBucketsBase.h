#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_TickSequencerDynamicBucketsBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_TickSequencerDynamicBucketsBase : public USceneRigActionBase {
    GENERATED_BODY()
public:
    USceneAction_TickSequencerDynamicBucketsBase();
};

