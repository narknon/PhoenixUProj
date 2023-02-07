#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterMIDCacheEntry.h"
#include "MaterialPermuterMIDCache.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FMaterialPermuterMIDCache {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UMaterialInterface*, FMaterialPermuterMIDCacheEntry> Cache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TTLSeconds;
    
    MATERIALPERMUTER_API FMaterialPermuterMIDCache();
};

