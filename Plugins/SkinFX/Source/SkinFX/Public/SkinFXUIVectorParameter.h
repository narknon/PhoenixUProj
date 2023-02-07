#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkinFXMaterialVectorProperty.h"
#include "SkinFXUIVectorParameter.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXUIVectorParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXMaterialVectorProperty Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Value;
    
    SKINFX_API FSkinFXUIVectorParameter();
};

