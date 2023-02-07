#pragma once
#include "CoreMinimal.h"
#include "SceneActionFunctionEventReference.generated.h"

class UFunction;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneActionFunctionEventReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFunction* Function;
    
    FSceneActionFunctionEventReference();
};

