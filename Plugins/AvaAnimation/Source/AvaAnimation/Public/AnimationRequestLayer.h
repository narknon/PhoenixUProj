#pragma once
#include "CoreMinimal.h"
#include "EAnimationRequestLayerBlendType.h"
#include "AnimationRequestLayer.generated.h"

class UAnimMaskAsset;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimationRequestLayer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LayerName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxLODLevel;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimationRequestLayerBlendType BlendType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRecordLastSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMaskAsset* LayerMask;
    
    FAnimationRequestLayer();
};

