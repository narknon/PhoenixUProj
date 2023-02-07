#pragma once
#include "CoreMinimal.h"
#include "AnimInstanceProxy_RetrieveActorTransform.h"
#include "SceneRigAnimInstanceProxy.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigAnimInstanceProxy : public FAnimInstanceProxy_RetrieveActorTransform {
    GENERATED_BODY()
public:
    FSceneRigAnimInstanceProxy();
};

