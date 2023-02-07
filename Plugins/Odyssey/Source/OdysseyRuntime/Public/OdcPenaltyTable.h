#pragma once
#include "CoreMinimal.h"
#include "EOdcPenaltyTableMode.h"
#include "OdcPenaltyTable.generated.h"

USTRUCT(BlueprintType)
struct FOdcPenaltyTable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOdcPenaltyTableMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> PerFlagPenalties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 FixedPointDenominator;
    
    ODYSSEYRUNTIME_API FOdcPenaltyTable();
};

