#pragma once
#include "CoreMinimal.h"
#include "EScoreOverrideReturnConfigurationType.h"
#include "ScoreOverrideReturnConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FScoreOverrideReturnConfiguration {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EScoreOverrideReturnConfigurationType MultiplierToReturn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CustomMultiplier;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EScoreOverrideReturnConfigurationType RankToReturn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CustomRank;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EScoreOverrideReturnConfigurationType BonusToReturn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CustomBonus;
    
    BTUTILITYAI_API FScoreOverrideReturnConfiguration();
};

