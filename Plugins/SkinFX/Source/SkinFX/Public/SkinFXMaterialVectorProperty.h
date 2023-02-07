#pragma once
#include "CoreMinimal.h"
#include "SkinFXMaterialVectorProperty.generated.h"

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXMaterialVectorProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FSkinFXMaterialVectorProperty();
};

