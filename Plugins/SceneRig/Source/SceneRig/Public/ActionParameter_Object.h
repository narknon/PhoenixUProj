#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameterBinding_Object.h"
#include "ActionParameter_Object.generated.h"

class UObjectProvider;

USTRUCT(BlueprintType)
struct SCENERIG_API FActionParameter_Object {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_Object BoundParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObjectProvider* DefaultObject;
    
    FActionParameter_Object();
};

