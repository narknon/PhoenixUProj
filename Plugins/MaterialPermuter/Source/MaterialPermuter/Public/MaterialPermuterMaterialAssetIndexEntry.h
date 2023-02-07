#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterMaterialAssetIndexEntry.generated.h"

class UMaterial;
class UMaterialInterface;

USTRUCT(BlueprintType)
struct FMaterialPermuterMaterialAssetIndexEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterial> Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInterface> Asset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Hash;
    
    MATERIALPERMUTER_API FMaterialPermuterMaterialAssetIndexEntry();
};

