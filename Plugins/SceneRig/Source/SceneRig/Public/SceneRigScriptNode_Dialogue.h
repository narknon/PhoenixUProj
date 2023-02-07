#pragma once
#include "CoreMinimal.h"
#include "SceneRigScriptNode.h"
#include "SceneRigScriptNode_Dialogue.generated.h"

class UDialogueScriptCommand;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigScriptNode_Dialogue : public USceneRigScriptNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DialogueID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CharacterID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDialogueScriptCommand*> Commands;
    
    USceneRigScriptNode_Dialogue();
};

