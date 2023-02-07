#pragma once
#include "CoreMinimal.h"
#include "CreatureActivityThreshold.generated.h"

USTRUCT(BlueprintType)
struct FCreatureActivityThreshold {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActivityName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HappinessPercentageThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnlocked;
    
    PHOENIX_API FCreatureActivityThreshold();
};

