#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "DialogueConversationReference.h"
#include "SkippableDialogueActionStateInterface.h"
#include "SceneActionState_DialogueEvent.generated.h"

UCLASS(Blueprintable)
class USceneActionState_DialogueEvent : public USceneRigObjectActionState, public ISkippableDialogueActionStateInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueConversationReference Event;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AudioHandle;
    
    USceneActionState_DialogueEvent();
    
    // Fix for true pure virtual functions not being implemented
};

