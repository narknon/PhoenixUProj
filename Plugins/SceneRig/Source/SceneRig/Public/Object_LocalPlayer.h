#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Object_LocalPlayer.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UObject_LocalPlayer : public UActorProvider {
    GENERATED_BODY()
public:
    UObject_LocalPlayer();
};

