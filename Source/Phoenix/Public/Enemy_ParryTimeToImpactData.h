#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EEnemy_ParryButtonPressed.h"
#include "EEnemy_ParryCounterStepDirection.h"
#include "EEnemy_ParryCounterStyle.h"
#include "EEnemy_ParryCounterType.h"
#include "EEnemy_ParryDodgeStyle.h"
#include "EEnemy_ParryResponseType.h"
#include "Enemy_ParryTimeToImpactData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_ParryTimeToImpactData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeToImpact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WindowID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MunitionTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnblockable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPerfect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_ParryCounterType CounterType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_ParryResponseType ResponseType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_ParryCounterStepDirection CounterStepDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_ParryCounterStyle CounterStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_ParryDodgeStyle DodgeStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_ParryButtonPressed ButtonPressed;
    
    PHOENIX_API FEnemy_ParryTimeToImpactData();
};

