#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BlendDomain.h"
#include "EGlobalLightingFogZMode.h"
#include "BlendableGlobalLightingVolumeFogDefaultsBase.generated.h"

class UExpHeightFogTransmuter;

UCLASS(Blueprintable)
class UBlendableGlobalLightingVolumeFogDefaultsBase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightingFogZMode FogZMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExpHeightFogTransmuter* Transmuter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float BlendRadius;
    
    UBlendableGlobalLightingVolumeFogDefaultsBase();
};

