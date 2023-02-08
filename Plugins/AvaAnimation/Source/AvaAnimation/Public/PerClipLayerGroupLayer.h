#pragma once
#include "CoreMinimal.h"
#include "AnimationRequestLayerReference.h"
#include "PerClipLayerGroupLayer.generated.h"



USTRUCT(BlueprintType)
struct AVAANIMATION_API FPerClipLayerGroupLayer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* LayerAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LayerName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationRequestLayerReference LayerReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ScaleToFit;
    
    FPerClipLayerGroupLayer();
};

