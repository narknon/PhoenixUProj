#pragma once
#include "CoreMinimal.h"
#include "DialogueLineRuleState.h"
#include "DialogueLineRuleState_Camera.generated.h"

class UAnimSequenceBase;
class UCameraFixupOperations;
class USceneAction_Animation;
class USceneAction_CameraFixup;
class USceneAction_Transform;

UCLASS(Blueprintable)
class UDialogueLineRuleState_Camera : public UDialogueLineRuleState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USceneAction_Animation*> LastAnimationActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimSequenceBase*> LastCameraClips;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneAction_Transform* LastTransformAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCameraFixupOperations* LastCameraFixupOperations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneAction_CameraFixup* LastCameraFixupAction;
    
    UDialogueLineRuleState_Camera();
};

