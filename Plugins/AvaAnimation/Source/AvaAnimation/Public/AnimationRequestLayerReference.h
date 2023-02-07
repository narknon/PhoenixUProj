#pragma once
#include "CoreMinimal.h"
#include "AnimationRequestLayerReference.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimationRequestLayerReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LayerName;
    
    FAnimationRequestLayerReference();
};

