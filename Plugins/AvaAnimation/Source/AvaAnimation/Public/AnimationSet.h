#pragma once
#include "CoreMinimal.h"
#include "AnimationSetEntry.h"
#include "AnimationSet.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimationSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimationSetEntry> AnimationEntries;
    
    FAnimationSet();
};

