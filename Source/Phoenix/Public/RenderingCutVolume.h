#pragma once
#include "CoreMinimal.h"
#include "Interfaces/Interface_PostProcessVolume.h"
#include "Engine/Scene.h"
#include "GameFramework/Volume.h"
#include "BlendDomain.h"
#include "RenderingCutBits.h"
#include "RenderingCutVolume.generated.h"

class AActor;

UCLASS(Blueprintable)
class ARenderingCutVolume : public AVolume/*, public IInterface_PostProcessVolume*/ {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderingCutBits RenderingCut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float PreExposureResetValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bOnlyAlongPositiveXAxis;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FPostProcessSettings PostProcessing;
    
public:
    ARenderingCutVolume();
    UFUNCTION(BlueprintCallable)
    void SetPriority(float NewPriority);
    
private:
    UFUNCTION(BlueprintCallable)
    void ProcessBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
    
    
    // Fix for true pure virtual functions not being implemented
};

