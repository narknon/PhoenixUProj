#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MapFXData.h"
#include "MapFXDataTable.generated.h"

USTRUCT(BlueprintType)
struct FMapFXDataTable : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapFXData Overland;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapFXData Hogwarts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapFXData Hogsmeade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapFXData Dungeon;
    
    PHOENIX_API FMapFXDataTable();
};

