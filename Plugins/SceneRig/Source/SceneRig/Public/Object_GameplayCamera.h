#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Object_GameplayCamera.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UObject_GameplayCamera : public UActorProvider {
    GENERATED_BODY()
public:
    UObject_GameplayCamera();
};

