#pragma once
#include "CoreMinimal.h"
#include "SceneRigBoundObject.generated.h"

class UObjectProvider;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigBoundObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoundObjectName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObjectProvider* ObjectProvider;
    
    FSceneRigBoundObject();
};

