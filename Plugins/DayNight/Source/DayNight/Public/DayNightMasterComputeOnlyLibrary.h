#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DayNightMasterComputeOnlyPerLevel.h"
#include "Templates/SubclassOf.h"
#include "DayNightMasterComputeOnlyLibrary.generated.h"

class ADayNightMasterComputeOnly;

UCLASS(Blueprintable)
class DAYNIGHT_API UDayNightMasterComputeOnlyLibrary : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ADayNightMasterComputeOnly> ComputeDefault;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDayNightMasterComputeOnlyPerLevel> LevelOverrides;
    
    UDayNightMasterComputeOnlyLibrary();
};

