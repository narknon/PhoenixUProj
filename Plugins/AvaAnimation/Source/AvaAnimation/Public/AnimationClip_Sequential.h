#pragma once
#include "CoreMinimal.h"
#include "AnimationClipProvider.h"
#include "AnimationClip_Sequential.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UAnimationClip_Sequential : public UAnimationClipProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAnimationClipProvider*> Entries;
    
    UAnimationClip_Sequential();
};

