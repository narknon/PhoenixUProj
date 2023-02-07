#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterKey.h"
#include "MaterialPermuterKeyCached.h"
#include "MaterialPermuterKeyCache.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterKeyCache {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FMaterialPermuterKey> Map;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialPermuterKeyCached> Cache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSorted;
    
    FMaterialPermuterKeyCache();
};

