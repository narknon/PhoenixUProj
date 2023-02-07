#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AnimationArchitectTagProvider.h"
#include "AnimTag_Direct.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ANIMATIONARCHITECTRUNTIME_API UAnimTag_Direct : public UAnimationArchitectTagProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UAnimTag_Direct();
};

