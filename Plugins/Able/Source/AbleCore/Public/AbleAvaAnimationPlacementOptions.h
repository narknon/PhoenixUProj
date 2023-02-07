#pragma once
#include "CoreMinimal.h"
#include "AbleAvaAnimationPlacementOptions.generated.h"

class UAnimationTransformProvider;
class UBoolProvider;
class UTransformProvider;

USTRUCT(BlueprintType)
struct ABLECORE_API FAbleAvaAnimationPlacementOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* InitialPlacementTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* ConstrainedToPlacement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* PlacementIsMoving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* HandledByRequest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* PlacementProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationTransformProvider* AnimationPlacementOffset;
    
    FAbleAvaAnimationPlacementOptions();
};

