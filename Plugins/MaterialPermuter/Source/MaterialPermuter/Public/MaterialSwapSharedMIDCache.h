#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapSharedMIDCacheEntry.h"
#include "MaterialSwapSharedMIDCache.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapSharedMIDCache {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UMaterialInterface*, FMaterialSwapSharedMIDCacheEntry> Map;
    
    FMaterialSwapSharedMIDCache();
};

