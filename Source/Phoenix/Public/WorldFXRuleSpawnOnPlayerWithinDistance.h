#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleCameraPlayerAttached.h"
#include "WorldFXRuleSpawnOnPlayerWithinDistance.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleSpawnOnPlayerWithinDistance : public UWorldFXRuleCameraPlayerAttached {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
    UWorldFXRuleSpawnOnPlayerWithinDistance();
};

