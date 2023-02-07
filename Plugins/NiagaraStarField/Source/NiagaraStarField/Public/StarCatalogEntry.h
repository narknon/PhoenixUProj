#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "StarCatalogEntry.generated.h"

USTRUCT(BlueprintType)
struct NIAGARASTARFIELD_API FStarCatalogEntry : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightAscention;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Declination;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Temperature;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Magnitude;
    
    FStarCatalogEntry();
};

