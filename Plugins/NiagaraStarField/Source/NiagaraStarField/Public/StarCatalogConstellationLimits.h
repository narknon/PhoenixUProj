#pragma once
#include "CoreMinimal.h"
#include "StarCatalogConstellationStars.h"
#include "StarCatalogConstellationLimits.generated.h"

USTRUCT(BlueprintType)
struct FStarCatalogConstellationLimits {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStarCatalogConstellationStars LimitConstellationStars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DefaultLimitConstellationStars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConstellationNameMagnitudeCutoff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseConstellationStarsLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDefaultConstellationStarsLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseConstellationNameMagnitudeCutoff;
    
    NIAGARASTARFIELD_API FStarCatalogConstellationLimits();
};

