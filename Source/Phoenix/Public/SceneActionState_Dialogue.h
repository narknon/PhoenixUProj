#pragma once
#include "CoreMinimal.h"
#include "SceneRigBakeSequence.h"
#include "SceneRigObjectActionState.h"
#include "DialogueLineReference.h"
#include "SkippableDialogueActionStateInterface.h"
#include "SceneActionState_Dialogue.generated.h"

UCLASS(Blueprintable)
class USceneActionState_Dialogue : public USceneRigObjectActionState, public ISceneRigBakeSequence, public ISkippableDialogueActionStateInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueLineReference LineReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AudioHandle;
    
    USceneActionState_Dialogue();
    
    // Fix for true pure virtual functions not being implemented
};

