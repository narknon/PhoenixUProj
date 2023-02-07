#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorMultiCrossBlendStandalone.h"
#include "UObject/NoExportTypes.h"
#include "CameraStackBehaviorFlyingMountHeightCrossBlend.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackBehaviorFlyingMountHeightCrossBlend : public UCameraStackBehaviorMultiCrossBlendStandalone {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatRange HeightRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatRange DescendingVelocityRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FilterHalflifeIncrease;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FilterHalflifeDecrease;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FilterHalflifeDescending;
    
    UCameraStackBehaviorFlyingMountHeightCrossBlend();
};

