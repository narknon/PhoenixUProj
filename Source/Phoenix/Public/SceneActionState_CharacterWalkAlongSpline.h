#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_CharacterWalkBase.h"
#include "SceneActionState_CharacterWalkAlongSpline.generated.h"

UCLASS(Blueprintable)
class USceneActionState_CharacterWalkAlongSpline : public USceneActionState_CharacterWalkBase {
    GENERATED_BODY()
public:
    USceneActionState_CharacterWalkAlongSpline();
};

