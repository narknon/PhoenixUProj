#pragma once
#include "CoreMinimal.h"
#include "SkinFXMaterialTextureProperty.h"
#include "SkinFXTextureAdvanced.h"
#include "SkinFXTexture.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct FSkinFXTexture {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXMaterialTextureProperty MaterialParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture> Texture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXTextureAdvanced Advanced;
    
    SKINFX_API FSkinFXTexture();
};

