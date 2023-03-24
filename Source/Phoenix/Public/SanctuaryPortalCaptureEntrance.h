#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SanctuaryPortalCaptureEntrance.generated.h"

class ASanctuaryPortalCaptureExit;
class UMaterialInstanceDynamic;
class UTextureCube;
class UTextureRenderTargetCube;

UCLASS(Abstract, Blueprintable)
class ASanctuaryPortalCaptureEntrance : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EntranceZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTargetCube* RenderTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureCube* PreRenderedTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASanctuaryPortalCaptureExit* Exit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReCaptureAtRuntime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bHasRuntimeCapture;
    
    ASanctuaryPortalCaptureEntrance(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void RuntimeReCapture();
    
    UFUNCTION(BlueprintCallable)
    void Capture();
    
    UFUNCTION(BlueprintCallable)
    void ApplyMaterialParameters(UMaterialInstanceDynamic* InMaterialInstanceDynamic);
    
};

