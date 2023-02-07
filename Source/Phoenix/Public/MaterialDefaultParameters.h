#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MaterialDefaultParameters.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct FMaterialDefaultParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FLinearColor> Vectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UTexture*> Textures;
    
    PHOENIX_API FMaterialDefaultParameters();
};

