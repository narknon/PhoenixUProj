#pragma once
#include "CoreMinimal.h"
#include "WorldFXMaterialOverrideList.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct WORLDFX_API FWorldFXMaterialOverrideList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UMaterialInterface>> Elements;
    
    FWorldFXMaterialOverrideList();
};

