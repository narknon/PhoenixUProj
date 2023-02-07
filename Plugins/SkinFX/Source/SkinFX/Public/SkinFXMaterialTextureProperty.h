#pragma once
#include "CoreMinimal.h"
#include "SkinFXMaterialTextureProperty.generated.h"

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXMaterialTextureProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FSkinFXMaterialTextureProperty();
};

