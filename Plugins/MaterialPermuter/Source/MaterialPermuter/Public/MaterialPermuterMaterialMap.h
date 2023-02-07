#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterMaterialMapPermutation.h"
#include "MaterialPermuterMaterialMap.generated.h"

class UMaterial;
class UMaterialInterface;

USTRUCT(BlueprintType)
struct FMaterialPermuterMaterialMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInterface> DefaultMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftObjectPtr<UMaterial>, FMaterialPermuterMaterialMapPermutation> MaterialMap;
    
    MATERIALPERMUTER_API FMaterialPermuterMaterialMap();
};

