#pragma once
#include "CoreMinimal.h"
#include "SceneRigScriptBranch.h"
#include "SceneRigScriptNode.h"
#include "SceneRigScriptNode_Branch.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneRigScriptNode_Branch : public USceneRigScriptNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneRigScriptBranch> Branches;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentBranch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasMissmatchingInternalBranches;
    
    USceneRigScriptNode_Branch();
};

