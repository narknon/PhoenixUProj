#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_AnimateCurves.h"
#include "SceneActionState_AnimateProperty.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_AnimateProperty : public USceneActionState_AnimateCurves {
    GENERATED_BODY()
public:
    USceneActionState_AnimateProperty();
};

