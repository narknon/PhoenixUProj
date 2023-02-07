#pragma once
#include "CoreMinimal.h"
#include "Enemy_ParryParamData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_ParryParamData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWindowOpenUntilImpact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WindowLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeadInSkipLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanSuspendRelease;
    
    PHOENIX_API FEnemy_ParryParamData();
};

