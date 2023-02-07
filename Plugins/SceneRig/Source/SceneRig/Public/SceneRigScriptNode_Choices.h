#pragma once
#include "CoreMinimal.h"
#include "SceneRigScriptChoice.h"
#include "SceneRigScriptNode.h"
#include "SceneRigScriptNode_Choices.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneRigScriptNode_Choices : public USceneRigScriptNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneRigScriptChoice> Choices;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentChoice;
    
    USceneRigScriptNode_Choices();
};

