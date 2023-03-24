#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interface_PostProcessVolume.h"
#include "Engine/Scene.h"
#include "LastRenderedExposure.h"
#include "LastRenderedExposurePair.h"
#include "BlendDomainState.h"
#include "DistanceFog.h"
#include "DistanceFogCompute.h"
#include "ERenderSettingsIndoorsType.h"
#include "EmissiveAdaptationStateCompute.h"
#include "LightAdaptationTracker.h"
#include "PlayerCentricPostProcessingOverrides.h"
#include "RenderSettingsEmissiveAdaptation.h"
#include "RenderSettingsPostProcessingGroup.h"
#include "RenderSettingsSingleton.generated.h"

class UDirectionalLightComponent;
class UObject;
class UPlayerCentricPostProcessingComponent;
class UPostProcessComponent;

UCLASS(Blueprintable, NotPlaceable, Transient)
class RENDERSETTINGS_API ARenderSettingsSingleton : public AActor/*, public IInterface_PostProcessVolume*/ {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRenderSettingsPostProcessingGroup DefaultPostProcessing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLightAdaptationTracker LightAdaptation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bCreatedInInactiveWorld;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FPostProcessSettings EnginePostProcessSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDistanceFog DefaultDistanceFog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDistanceFogCompute DistanceFog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRenderSettingsEmissiveAdaptation DefaultEmissiveAdaptation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEmissiveAdaptationStateCompute EmissiveAdaptation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FPlayerCentricPostProcessingOverrides PlayerCentricViewpointOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerCentricPostProcessingComponent* PlayerCentricPostProcessing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBlendDomainState ViewpointState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBlendDomainState CameraState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBlendDomainState PlayerState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLastRenderedExposurePair LastFrameExposure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLastRenderedExposure LastValidExposure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ViewpointEye0Player1Lerp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 ActiveEditorViewport;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint32 LastCameraCutFrame;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint32 LastExposureRenderCutFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInExposureRenderingCut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsFixedExposure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPostProcessComponent* DebugPostProcessComponent;
    
public:
    ARenderSettingsSingleton(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static float RenderSettingsGetOvercast(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static float RenderSettingsGetIndoors(UObject* WorldContextObject, ERenderSettingsIndoorsType IndoorsType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static float RenderSettingsGetDayNight(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PushPlayerViewpointOverride(UObject* WorldContextObject, UObject* ViewpointOverrideOwner, float PostProcessingViewpointOverride, float LerpAlpha);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PopPlayerViewpointOverride(UObject* WorldContextObject, UObject* ViewpointOverrideOwner);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void IsPlayerIndoors(UObject* WorldContextObject, float& Indoors0To1, bool& bIsIndoors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void IsCameraIndoors(UObject* WorldContextObject, float& Indoors0To1, bool& bIsIndoors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void HasPlayerViewpointOverride(UObject* WorldContextObject, UObject* ViewpointOverrideOwner, bool& bExists);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetViewpointIsInside(UObject* WorldContextObject, float& Indoors, ERenderSettingsIndoorsType IndoorsType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetViewpointBlendDomain(UObject* WorldContextObject, FBlendDomainState& BlendDomainState);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetPlayerIsInside(UObject* WorldContextObject, float& Indoors, ERenderSettingsIndoorsType IndoorsType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetPlayerBlendDomain(UObject* WorldContextObject, FBlendDomainState& BlendDomainState);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static float GetOvercast(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static float GetIndoors(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static float GetFilteredIndoors(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static float GetDayNight(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetCameraIsInside(UObject* WorldContextObject, float& Indoors, ERenderSettingsIndoorsType IndoorsType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetCameraBlendDomain(UObject* WorldContextObject, FBlendDomainState& BlendDomainState);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetBlendDomainValueBool(const FBlendDomainState& BlendDomainState, FName BlendDomain, bool& bValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetBlendDomainValue(const FBlendDomainState& BlendDomainState, FName BlendDomain, float& Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetBlendDomainIndoors(const FBlendDomainState& BlendDomainState, float& Indoors, ERenderSettingsIndoorsType IndoorsType);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UDirectionalLightComponent* GetBestDirectionalLight(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void CustomBlendDomainSetOverride(UObject* WorldContextObject, FName CustomBlendDomainName, float Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void CustomBlendDomainHasOverride(UObject* WorldContextObject, FName CustomBlendDomainName, bool& bExists);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void CustomBlendDomainGetOverride(UObject* WorldContextObject, FName CustomBlendDomainName, float& Value, bool& bExists);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void CustomBlendDomainGetBool(UObject* WorldContextObject, FName CustomBlendDomainName, bool& bValue, bool bDefaultValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void CustomBlendDomainGet(UObject* WorldContextObject, FName CustomBlendDomainName, float& Value, bool& bExists);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void CustomBlendDomainExists(UObject* WorldContextObject, FName CustomBlendDomainName, bool& bExists);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void CustomBlendDomainClearOverride(UObject* WorldContextObject, FName CustomBlendDomainName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static float CurrentPlayerViewpointOverride(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void ComputeIsInside(UObject* WorldContextObject, FVector Position, float& Indoors, ERenderSettingsIndoorsType IndoorsType, bool bHighQuality);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void ComputeBlendDomain(UObject* WorldContextObject, FVector Position, FBlendDomainState& BlendDomainState, bool bHighQuality);
    
    
    // Fix for true pure virtual functions not being implemented
};

