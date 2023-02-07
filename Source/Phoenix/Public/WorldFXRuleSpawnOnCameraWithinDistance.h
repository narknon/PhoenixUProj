#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleCameraPlayerAttached.h"
#include "WorldFXRuleSpawnOnCameraWithinDistance.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleSpawnOnCameraWithinDistance : public UWorldFXRuleCameraPlayerAttached {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
    UWorldFXRuleSpawnOnCameraWithinDistance();
};

