#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterParameterSet.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterParameterSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Vectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Textures;
    
    MATERIALPERMUTER_API FMaterialPermuterParameterSet();
};

