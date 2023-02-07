#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_SetProperty.h"
#include "SceneActionState_SetFloatProperty.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_SetFloatProperty : public USceneActionState_SetProperty {
    GENERATED_BODY()
public:
    USceneActionState_SetFloatProperty();
};

