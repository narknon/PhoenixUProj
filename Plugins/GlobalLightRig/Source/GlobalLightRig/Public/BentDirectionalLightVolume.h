#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlendDomain.h"
#include "BentDirectionalLightParams.h"
#include "GlobalLightingBlendableInterface.h"
#include "BentDirectionalLightVolume.generated.h"

class UBoxComponent;
class UGlobalLightingBlendableBentDirectionalLight;

UCLASS(Blueprintable)
class GLOBALLIGHTRIG_API ABentDirectionalLightVolume : public AActor, public IGlobalLightingBlendableInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBentDirectionalLightParams Params;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGlobalLightingBlendableBentDirectionalLight* GlobalLightingBlendable;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* BoundingBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float BlendRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float BlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float PositionalBlendWeight;
    
public:
    ABentDirectionalLightVolume();
    
    // Fix for true pure virtual functions not being implemented
};

