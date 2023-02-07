#pragma once
#include "CoreMinimal.h"
#include "SkinFXMaterialParamProperty.generated.h"

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXMaterialParamProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FSkinFXMaterialParamProperty();
};

