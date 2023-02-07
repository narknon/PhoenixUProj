#pragma once
#include "CoreMinimal.h"
#include "AnimationClipProvider.h"
#include "AnimationClip_SharedRandomEntry.h"
#include "AnimationClip_SharedRandom.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UAnimationClip_SharedRandom : public UAnimationClipProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AvoidPickingSameTwice;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimationClip_SharedRandomEntry> Entries;
    
    UAnimationClip_SharedRandom();
};

