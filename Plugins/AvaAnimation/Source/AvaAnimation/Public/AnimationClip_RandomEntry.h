#pragma once
#include "CoreMinimal.h"
#include "AnimationClip_RandomEntry.generated.h"

class UAnimationClipProvider;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimationClip_RandomEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationClipProvider* ClipProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    FAnimationClip_RandomEntry();
};

