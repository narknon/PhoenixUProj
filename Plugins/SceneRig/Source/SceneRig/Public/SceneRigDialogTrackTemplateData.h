#pragma once
#include "CoreMinimal.h"
#include "SceneRigDialogTrackSectionData.h"
#include "SceneRigDialogTrackTemplateData.generated.h"

USTRUCT(BlueprintType)
struct FSceneRigDialogTrackTemplateData : public FSceneRigDialogTrackSectionData {
    GENERATED_BODY()
public:
    SCENERIG_API FSceneRigDialogTrackTemplateData();
};

