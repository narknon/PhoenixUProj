#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraActionTransitionSettings.h"
#include "EManagedCameraPriority.h"
#include "SceneRigStage_ActorReference.h"
#include "DialogueLineRule_PickCameraItem.h"
#include "DialogueLineRule_PickCamera_Event.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class UDialogueLineRule_PickCamera_Event : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_ActorReference Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDialogueLineRule_PickCameraItem> CameraList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EManagedCameraPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraActionTransitionSettings TransitionInSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraActionTransitionSettings TransitionOutSettings;
    
    UDialogueLineRule_PickCamera_Event();
};

