#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MapLocItem.h"
#include "MapLocTable.generated.h"

USTRUCT(BlueprintType)
struct FMapLocTable : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMapLocItem> MapActions;
    
    PHOENIX_API FMapLocTable();
};

