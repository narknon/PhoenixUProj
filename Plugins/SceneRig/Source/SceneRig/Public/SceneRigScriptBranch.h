#pragma once
#include "CoreMinimal.h"
#include "SceneRigScriptBranch.generated.h"

class USceneRigScriptNode;
class UScriptConditionProvider;

USTRUCT(BlueprintType)
struct FSceneRigScriptBranch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScriptConditionProvider* Condition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigScriptNode* Script;
    
    SCENERIG_API FSceneRigScriptBranch();
};

