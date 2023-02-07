#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleCameraPlayer.h"
#include "WorldFXRuleOutsideOfCameraDistance.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleOutsideOfCameraDistance : public UWorldFXRuleCameraPlayer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
    UWorldFXRuleOutsideOfCameraDistance();
};

