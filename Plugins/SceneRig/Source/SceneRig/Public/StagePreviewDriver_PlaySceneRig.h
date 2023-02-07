#pragma once
#include "CoreMinimal.h"
#include "StagePreviewDriver.h"
#include "StagePreviewDriver_PlaySceneRig.generated.h"

class USceneRig;
class USceneRigPlayer;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UStagePreviewDriver_PlaySceneRig : public UStagePreviewDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRig* SceneRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigPlayer* SceneRigPlayer;
    
    UStagePreviewDriver_PlaySceneRig();
};

