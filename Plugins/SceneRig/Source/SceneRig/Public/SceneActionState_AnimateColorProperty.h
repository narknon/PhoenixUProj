#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_AnimateProperty.h"
#include "SceneActionState_AnimateColorProperty.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_AnimateColorProperty : public USceneActionState_AnimateProperty {
    GENERATED_BODY()
public:
    USceneActionState_AnimateColorProperty();
};

