#pragma once
#include "CoreMinimal.h"
#include "StarCatalogNameIDMap.generated.h"

USTRUCT(BlueprintType)
struct FStarCatalogNameIDMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Names;
    
    NIAGARASTARFIELD_API FStarCatalogNameIDMap();
};

