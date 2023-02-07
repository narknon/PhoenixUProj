#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterMaterialMapPermutation.generated.h"

class UMaterial;
class UMaterialInterface;

USTRUCT(BlueprintType)
struct FMaterialPermuterMaterialMapPermutation {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInterface> PermutedMaterial;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterial> PermutedMasterMaterial;
    
    MATERIALPERMUTER_API FMaterialPermuterMaterialMapPermutation();
};

