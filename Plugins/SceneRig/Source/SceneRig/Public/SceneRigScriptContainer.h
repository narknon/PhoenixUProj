#pragma once
#include "CoreMinimal.h"
#include "SceneRigScriptContainer.generated.h"

class USceneRigScript;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigScriptContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigScript* ScriptObject;
    
    FSceneRigScriptContainer();
};

