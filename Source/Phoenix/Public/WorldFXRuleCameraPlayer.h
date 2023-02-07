#pragma once
#include "CoreMinimal.h"
#include "WorldFXRule.h"
#include "WorldFXRuleCameraPlayer.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleCameraPlayer : public UWorldFXRule {
    GENERATED_BODY()
public:
    UWorldFXRuleCameraPlayer();
};

