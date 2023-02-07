#pragma once
#include "CoreMinimal.h"
#include "SkinFXBoneProperty.generated.h"

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXBoneProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FSkinFXBoneProperty();
};

