#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ExpHeightFogInscatteringTextureParameters.generated.h"

class UTextureCube;

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FExpHeightFogInscatteringTextureParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureCube* InscatteringColorCubemap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InscatteringColorCubemapAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor InscatteringTextureTint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FullyDirectionalInscatteringColorDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NonDirectionalInscatteringColorDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSkyLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InscatteringColorCubemapFactor;
    
    FExpHeightFogInscatteringTextureParameters();
};

