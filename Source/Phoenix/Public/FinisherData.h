#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FinisherData.generated.h"

class UAblAbility;

USTRUCT(BlueprintType)
struct FFinisherData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UAblAbility> AvatarAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MunitionTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 weight;
    
    PHOENIX_API FFinisherData();
};

