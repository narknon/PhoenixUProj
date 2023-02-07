#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldFXRuleCameraPlayerAttached.h"
#include "WorldFXRuleSpawnOnPlayerWithinBounds.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleSpawnOnPlayerWithinBounds : public UWorldFXRuleCameraPlayerAttached {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Bounds;
    
    UWorldFXRuleSpawnOnPlayerWithinBounds();
};

