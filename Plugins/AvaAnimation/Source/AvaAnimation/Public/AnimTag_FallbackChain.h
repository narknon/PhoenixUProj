#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitectTagProvider.h"
#include "AnimTag_FallbackChain.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UAnimTag_FallbackChain : public UAnimationArchitectTagProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAnimationArchitectTagProvider*> Entries;
    
    UAnimTag_FallbackChain();
};

