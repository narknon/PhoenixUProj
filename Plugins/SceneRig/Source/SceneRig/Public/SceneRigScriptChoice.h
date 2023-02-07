#pragma once
#include "CoreMinimal.h"
#include "SceneRigScriptChoice.generated.h"

class USceneRigScriptNode;

USTRUCT(BlueprintType)
struct FSceneRigScriptChoice {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigScriptNode* Script;
    
    SCENERIG_API FSceneRigScriptChoice();
};

