#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_CharacterWalkBase.h"
#include "SceneActionState_CharacterTurnToFace.generated.h"

UCLASS(Blueprintable)
class USceneActionState_CharacterTurnToFace : public USceneActionState_CharacterWalkBase {
    GENERATED_BODY()
public:
    USceneActionState_CharacterTurnToFace();
};

