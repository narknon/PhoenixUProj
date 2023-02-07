#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldFXRuleCameraPlayer.h"
#include "WorldFXRulePlayerWithinBounds.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRulePlayerWithinBounds : public UWorldFXRuleCameraPlayer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Bounds;
    
    UWorldFXRulePlayerWithinBounds();
};

