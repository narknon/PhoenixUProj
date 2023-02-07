#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneRigScriptNode.generated.h"

class USceneRigScriptNode;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigScriptNode : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USceneRigScriptNode*> PreviousNodes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigScriptNode* NextNode;
    
    USceneRigScriptNode();
};

