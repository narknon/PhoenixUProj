#pragma once
#include "CoreMinimal.h"
#include "SkinFXSubTypeProperty.generated.h"

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXSubTypeProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FSkinFXSubTypeProperty();
};

