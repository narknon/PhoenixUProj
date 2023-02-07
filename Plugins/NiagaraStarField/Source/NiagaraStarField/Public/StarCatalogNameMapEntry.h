#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "StarCatalogNameMapEntry.generated.h"

USTRUCT(BlueprintType)
struct NIAGARASTARFIELD_API FStarCatalogNameMapEntry : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FStarCatalogNameMapEntry();
};

