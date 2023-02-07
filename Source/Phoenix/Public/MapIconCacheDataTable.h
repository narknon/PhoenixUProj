#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MapIconCacheDataTable.generated.h"

USTRUCT(BlueprintType)
struct FMapIconCacheDataTable : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> Icons;
    
    PHOENIX_API FMapIconCacheDataTable();
};

