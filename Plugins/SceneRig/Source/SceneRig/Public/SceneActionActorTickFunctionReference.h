#pragma once
#include "CoreMinimal.h"
#include "SceneActionActorFunctionReference.h"
#include "SceneActionActorTickFunctionReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneActionActorTickFunctionReference : public FSceneActionActorFunctionReference {
    GENERATED_BODY()
public:
    FSceneActionActorTickFunctionReference();
};

