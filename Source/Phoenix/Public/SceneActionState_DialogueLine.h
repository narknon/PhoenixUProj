#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "DialogueLineReference.h"
#include "SkippableDialogueActionStateInterface.h"
#include "SceneActionState_DialogueLine.generated.h"

UCLASS(Blueprintable)
class USceneActionState_DialogueLine : public USceneRigObjectActionState, public ISkippableDialogueActionStateInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueLineReference Line;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AudioHandle;
    
    USceneActionState_DialogueLine();
    
    // Fix for true pure virtual functions not being implemented
};

