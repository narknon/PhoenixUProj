#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Actor_GameplayCamera.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UActor_GameplayCamera : public UActorProvider {
    GENERATED_BODY()
public:
    UActor_GameplayCamera();
};

