#pragma once
#include "CoreMinimal.h"
#include "ESkinFXMaterialOverrideType.h"
#include "SkinFXMaterialOverride.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXMaterialOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXMaterialOverrideType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UMaterialInterface>> Materials;
    
    FSkinFXMaterialOverride();
};

