#pragma once
#include "CoreMinimal.h"
#include "FootPlantEffects.h"
#include "UObject/NoExportTypes.h"
#include "EFootprintTypes.h"
#include "PhoenixFootPlantEffects.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPhoenixFootPlantEffects : public UFootPlantEffects {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VfxRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFootprintTypes FootprintType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FootOffsetZ;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FootprintScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScaleMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FemaleFootprintScaleAdjustment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D FootprintScaleVariationRange;
    
    UPhoenixFootPlantEffects();
};

