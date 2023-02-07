#pragma once
#include "CoreMinimal.h"
#include "SkinFXLerpIndex.generated.h"

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXLerpIndex {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Alpha;
    
    FSkinFXLerpIndex();
};

