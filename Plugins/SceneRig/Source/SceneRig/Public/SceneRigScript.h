#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneRigScript.generated.h"

class USceneRigScriptNode;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigScript : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigScriptNode* RootNode;
    
    USceneRigScript();
};

