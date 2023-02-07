#pragma once
#include "CoreMinimal.h"
#include "SkinFXFunctionProperty.generated.h"

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXFunctionProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FSkinFXFunctionProperty();
};

