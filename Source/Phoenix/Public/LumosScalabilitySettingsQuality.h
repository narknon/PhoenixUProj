#pragma once
#include "CoreMinimal.h"
#include "LumosScalabilitySettingsQuality.generated.h"

class ULumosScalabilityAsset;

USTRUCT(BlueprintType)
struct FLumosScalabilitySettingsQuality {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULumosScalabilityAsset* Low;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULumosScalabilityAsset* Medium;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULumosScalabilityAsset* High;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULumosScalabilityAsset* Epic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULumosScalabilityAsset* Cinematic;
    
    PHOENIX_API FLumosScalabilitySettingsQuality();
};

