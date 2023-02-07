#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GetupAnimationProfile.generated.h"

USTRUCT(BlueprintType)
struct FGetupAnimationProfile {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTagContainer> GetupAnimationTags;
    
    RAGDOLL_API FGetupAnimationProfile();
};

