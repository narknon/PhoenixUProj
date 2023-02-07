#pragma once
#include "CoreMinimal.h"
#include "SceneRigScriptNode.h"
#include "SceneRigScriptNode_ChoicePreview.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneRigScriptNode_ChoicePreview : public USceneRigScriptNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DialogueID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CharacterID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EnglishScriptText;
    
    USceneRigScriptNode_ChoicePreview();
};

