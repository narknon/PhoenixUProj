#pragma once
#include "CoreMinimal.h"
#include "DialogueLineRuleState.h"
#include "DialogueLineRuleState_PickCamera.generated.h"

class USceneAction_Camera;
class UStoryGraph_Conversation;

UCLASS(Blueprintable)
class UDialogueLineRuleState_PickCamera : public UDialogueLineRuleState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneAction_Camera* LastCameraAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStoryGraph_Conversation* CurrentConversation;
    
    UDialogueLineRuleState_PickCamera();
};

