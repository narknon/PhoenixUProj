#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ERegionType.h"
#include "RegionNamesDataTable.generated.h"

USTRUCT(BlueprintType)
struct FRegionNamesDataTable : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERegionType RegionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RegionLocName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EnemyLevelMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EnemyLevelMax;
    
    PHOENIX_API FRegionNamesDataTable();
};

