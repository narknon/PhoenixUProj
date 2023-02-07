#pragma once
#include "CoreMinimal.h"
#include "SceneActionActorFunctionReference.generated.h"

class UFunction;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneActionActorFunctionReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UFunction> Function;
    
    FSceneActionActorFunctionReference();
};

