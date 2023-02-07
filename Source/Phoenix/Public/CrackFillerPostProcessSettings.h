#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CrackFillerPostProcessSettings.generated.h"

USTRUCT(BlueprintType)
struct FCrackFillerPostProcessSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor CutoffColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CutoffDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SkyHoleSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SkyHoleHardness;
    
    PHOENIX_API FCrackFillerPostProcessSettings();
};

