#pragma once
#include "CoreMinimal.h"
#include "CachedColovariaMaterialArray.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FCachedColovariaMaterialArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> Materials;
    
    PHOENIX_API FCachedColovariaMaterialArray();
};

