#pragma once
#include "CoreMinimal.h"
#include "SkinFXMaterialScalarProperty.generated.h"

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXMaterialScalarProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FSkinFXMaterialScalarProperty();
};

