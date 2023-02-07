#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_SetProperty.h"
#include "SceneActionState_SetVectorProperty.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_SetVectorProperty : public USceneActionState_SetProperty {
    GENERATED_BODY()
public:
    USceneActionState_SetVectorProperty();
};

