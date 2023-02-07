#pragma once
#include "CoreMinimal.h"
#include "SceneRigScriptNode.h"
#include "SceneRigScriptNode_Scene.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneRigScriptNode_Scene : public USceneRigScriptNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SceneText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigScriptNode* SceneScript;
    
    USceneRigScriptNode_Scene();
};

