#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "BlendDomain.h"
#include "EGlobalLightingFogZMode.h"
#include "GlobalLightingBlendableInterface.h"
#include "BlendableGlobalLightingVolumeFogBase.generated.h"

class UExpHeightFogTransmuter;
class UGlobalLightingBlendableExpHeightFogVolume;

UCLASS(Abstract, Blueprintable)
class GLOBALLIGHTRIG_API ABlendableGlobalLightingVolumeFogBase : public AVolume, public IGlobalLightingBlendableInterface {
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float BlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bUnbounded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalLightingBlendableExpHeightFogVolume* GlobalLightingBlendable;
    
public:
    ABlendableGlobalLightingVolumeFogBase(const FObjectInitializer& ObjectInitializer);
    
    // Fix for true pure virtual functions not being implemented
};

