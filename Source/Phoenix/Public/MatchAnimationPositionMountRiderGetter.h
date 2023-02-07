#pragma once
#include "CoreMinimal.h"
#include "MatchAnimationPositionCharacterGetter.h"
#include "MatchAnimationPositionMountRiderGetter.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMatchAnimationPositionMountRiderGetter : public UMatchAnimationPositionCharacterGetter {
    GENERATED_BODY()
public:
    UMatchAnimationPositionMountRiderGetter();
};

