#pragma once
#include "CoreMinimal.h"
#include "StarCatalogConstellationStars.generated.h"

USTRUCT(BlueprintType)
struct FStarCatalogConstellationStars {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> ConstellationStars;
    
    NIAGARASTARFIELD_API FStarCatalogConstellationStars();
};

