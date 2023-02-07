#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MaterialPermuterMIDCacheTemplate.h"
#include "MaterialPermuterMIDCacheEntry.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FMaterialPermuterMIDCacheEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UMaterialInterface*, FMaterialPermuterMIDCacheTemplate> Templates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime Touched;
    
    MATERIALPERMUTER_API FMaterialPermuterMIDCacheEntry();
};

