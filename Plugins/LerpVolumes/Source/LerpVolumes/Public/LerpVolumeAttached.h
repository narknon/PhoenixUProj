#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlendDomain.h"
#include "LerpVolumeInterface.h"
#include "VolumeCenterlineSettings.h"
#include "LerpVolumeAttached.generated.h"

class AVolume;
class ULerpVolumeInterpolant;

UCLASS(Blueprintable)
class LERPVOLUMES_API ALerpVolumeAttached : public AActor, public ILerpVolumeInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AVolume* AttachVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULerpVolumeInterpolant*> Interpolants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumeCenterlineSettings Shape;
    
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
    
    ALerpVolumeAttached(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetPriority(float NewPriority);
    
    UFUNCTION(BlueprintCallable)
    void Recompute();
    
    
    // Fix for true pure virtual functions not being implemented
};

