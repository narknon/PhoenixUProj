#pragma once
#include "CoreMinimal.h"
#include "EZeroDirectionalLightMode.h"
#include "ZeroDirectionalLightSettings.generated.h"

USTRUCT(BlueprintType)
struct FZeroDirectionalLightSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EZeroDirectionalLightMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ClampToMinimum;
    
    GLOBALLIGHTRIG_API FZeroDirectionalLightSettings();
};

