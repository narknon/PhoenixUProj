#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InteractionArchitectAsset_KeyValueGroup.generated.h"

class UBaseArchitectAsset;

USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FInteractionArchitectAsset_KeyValueGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBaseArchitectAsset* Asset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    FInteractionArchitectAsset_KeyValueGroup();
};

