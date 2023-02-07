#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleCameraPlayer.h"
#include "WorldFXRulePlayerWithinDistance.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRulePlayerWithinDistance : public UWorldFXRuleCameraPlayer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
    UWorldFXRulePlayerWithinDistance();
};

