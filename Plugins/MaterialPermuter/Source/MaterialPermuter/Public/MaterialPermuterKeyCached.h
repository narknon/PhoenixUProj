#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterKey.h"
#include "MaterialPermuterKeyCached.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterKeyCached : public FMaterialPermuterKey {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CachedHash;
    
    FMaterialPermuterKeyCached();
};

