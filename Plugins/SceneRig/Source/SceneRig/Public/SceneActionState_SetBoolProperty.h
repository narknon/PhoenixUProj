#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_SetProperty.h"
#include "SceneActionState_SetBoolProperty.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_SetBoolProperty : public USceneActionState_SetProperty {
    GENERATED_BODY()
public:
    USceneActionState_SetBoolProperty();
};

