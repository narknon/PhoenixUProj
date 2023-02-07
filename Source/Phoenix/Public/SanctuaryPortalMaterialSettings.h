#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SanctuaryPortalMaterialSettings.generated.h"

USTRUCT(BlueprintType)
struct FSanctuaryPortalMaterialSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Desaturation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Brightness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Contrast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Tint;
    
    PHOENIX_API FSanctuaryPortalMaterialSettings();
};

