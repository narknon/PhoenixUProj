#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "DayNightMasterComputeOnlyPerLevel.generated.h"

class ADayNightMasterComputeOnly;

USTRUCT(BlueprintType)
struct FDayNightMasterComputeOnlyPerLevel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LevelPartialMatch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ADayNightMasterComputeOnly> ComputeDefault;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSubString;
    
    DAYNIGHT_API FDayNightMasterComputeOnlyPerLevel();
};

