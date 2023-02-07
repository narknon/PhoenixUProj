#pragma once
#include "CoreMinimal.h"
#include "AchievementChallenge.h"
#include "AchievementCategory.generated.h"

USTRUCT(BlueprintType)
struct FAchievementCategory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CategoryID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAchievementChallenge> Challenges;
    
    PHOENIX_API FAchievementCategory();
};

