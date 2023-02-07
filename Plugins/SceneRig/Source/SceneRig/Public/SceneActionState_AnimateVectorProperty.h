#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_AnimateProperty.h"
#include "SceneActionState_AnimateVectorProperty.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_AnimateVectorProperty : public USceneActionState_AnimateProperty {
    GENERATED_BODY()
public:
    USceneActionState_AnimateVectorProperty();
};

