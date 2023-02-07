#pragma once
#include "CoreMinimal.h"
#include "MatchAnimationPositionCharacterGetter.h"
#include "MatchAnimationPositionAttachParentGetter.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMatchAnimationPositionAttachParentGetter : public UMatchAnimationPositionCharacterGetter {
    GENERATED_BODY()
public:
    UMatchAnimationPositionAttachParentGetter();
};

