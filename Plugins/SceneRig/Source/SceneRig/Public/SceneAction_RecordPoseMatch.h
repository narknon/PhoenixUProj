#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_RecordPoseMatch.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_RecordPoseMatch : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    USceneAction_RecordPoseMatch();
};

