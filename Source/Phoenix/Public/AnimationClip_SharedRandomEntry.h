#pragma once
#include "CoreMinimal.h"
#include "AnimationClip_SharedRandomEntry.generated.h"

class UAnimationClipProvider;

USTRUCT(BlueprintType)
struct PHOENIX_API FAnimationClip_SharedRandomEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationClipProvider* ClipProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    FAnimationClip_SharedRandomEntry();
};

