#pragma once
#include "CoreMinimal.h"
#include "SanctuaryBonusStatus.generated.h"

USTRUCT(BlueprintType)
struct FSanctuaryBonusStatus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BonusID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString UnlockTextKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsMaxedOut;
    
    PHOENIX_API FSanctuaryBonusStatus();
};

