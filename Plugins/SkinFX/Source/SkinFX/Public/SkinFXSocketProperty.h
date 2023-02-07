#pragma once
#include "CoreMinimal.h"
#include "SkinFXSocketProperty.generated.h"

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXSocketProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FSkinFXSocketProperty();
};

