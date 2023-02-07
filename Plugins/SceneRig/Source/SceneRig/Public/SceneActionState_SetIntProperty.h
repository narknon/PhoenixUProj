#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_SetProperty.h"
#include "SceneActionState_SetIntProperty.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_SetIntProperty : public USceneActionState_SetProperty {
    GENERATED_BODY()
public:
    USceneActionState_SetIntProperty();
};

