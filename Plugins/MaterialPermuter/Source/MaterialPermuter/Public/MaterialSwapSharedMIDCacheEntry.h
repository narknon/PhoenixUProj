#pragma once
#include "CoreMinimal.h"
#include "CachedMIDParameters.h"
#include "MaterialSwapSharedMIDCacheEntry.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapSharedMIDCacheEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* Mid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCachedMIDParameters CachedParameters;
    
    FMaterialSwapSharedMIDCacheEntry();
};

