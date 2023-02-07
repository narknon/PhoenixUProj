#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapTextureParameter.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapTextureParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* Value;
    
    FMaterialSwapTextureParameter();
};

