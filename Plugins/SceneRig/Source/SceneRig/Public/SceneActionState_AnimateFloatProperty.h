#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_AnimateProperty.h"
#include "SceneActionState_AnimateFloatProperty.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_AnimateFloatProperty : public USceneActionState_AnimateProperty {
    GENERATED_BODY()
public:
    USceneActionState_AnimateFloatProperty();
};

