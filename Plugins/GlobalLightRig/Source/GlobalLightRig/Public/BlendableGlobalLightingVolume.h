#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "BlendDomain.h"
#include "EGlobalLightingFogZMode.h"
#include "GlobalLightingBlendableInterface.h"
#include "BlendableGlobalLightingVolume.generated.h"

class UGlobalLightingBlendable;

UCLASS(Blueprintable)
class GLOBALLIGHTRIG_API ABlendableGlobalLightingVolume : public AVolume, public IGlobalLightingBlendableInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGlobalLightingBlendable* GlobalLightingBlendable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float BlendRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float BlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUnbounded: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    uint8 bEnabled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCameraExpHeightFogHeight_DEPRICATED: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    EGlobalLightingFogZMode FogZMode;
    
    ABlendableGlobalLightingVolume();
    
    // Fix for true pure virtual functions not being implemented
};

