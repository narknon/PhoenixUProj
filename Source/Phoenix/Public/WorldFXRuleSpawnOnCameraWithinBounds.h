#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldFXRuleCameraPlayerAttached.h"
#include "WorldFXRuleSpawnOnCameraWithinBounds.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleSpawnOnCameraWithinBounds : public UWorldFXRuleCameraPlayerAttached {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Bounds;
    
    UWorldFXRuleSpawnOnCameraWithinBounds();
};

