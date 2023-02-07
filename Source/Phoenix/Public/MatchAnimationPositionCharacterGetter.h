#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MatchAnimationPositionCharacterGetter.generated.h"

UCLASS(Abstract, Blueprintable, DefaultToInstanced, EditInlineNew)
class UMatchAnimationPositionCharacterGetter : public UObject {
    GENERATED_BODY()
public:
    UMatchAnimationPositionCharacterGetter();
};

