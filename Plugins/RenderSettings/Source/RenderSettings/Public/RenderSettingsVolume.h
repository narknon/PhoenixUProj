#pragma once
#include "CoreMinimal.h"
#include "Interfaces/Interface_PostProcessVolume.h"
#include "Engine/Scene.h"
#include "GameFramework/Volume.h"
#include "BlendDomainIndoorsOutdoorsCurve.h"
#include "BlendDomainNormalizedTimeCurve.h"
#include "CharacterLightRigAdjustments.h"
#include "CharacterLightRigAdjustmentsName.h"
#include "DistanceFog.h"
#include "DistanceFogName.h"
#include "DistanceFogOverrides.h"
#include "EBlendDomainLightingMode.h"
#include "ERenderSettingsIndoorsType.h"
#include "ERenderSettingsVolumeDayNightType.h"
#include "ERenderSettingsVolumeIndoorsOutdoorsType.h"
#include "ERenderSettingsVolumeOvercastType.h"
#include "Interface_RenderSettingsEmissiveAdaptation.h"
#include "RenderSettingsEmissiveAdaptationName.h"
#include "RenderSettingsPostProcessing.h"
#include "RenderSettingsVolume.generated.h"

class URenderSettingsCustomBlendDomain;
class URenderSettingsLibrary;

UCLASS(Blueprintable)
class RENDERSETTINGS_API ARenderSettingsVolume : public AVolume/*, public IInterface_PostProcessVolume, public IInterface_RenderSettingsEmissiveAdaptation*/ {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsPostProcessing PostProcessing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDistanceFogName DistanceFog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDistanceFogOverrides DistanceFogOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterLightRigAdjustmentsName CharacterLightRigAdjustments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsEmissiveAdaptationName EmissiveAdaptation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExposureTweak;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERenderSettingsVolumeIndoorsOutdoorsType IndoorsOutdoors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERenderSettingsIndoorsType IndoorsType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERenderSettingsVolumeDayNightType DayNight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERenderSettingsVolumeOvercastType Overcast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBlendDomainLightingMode LightingMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomainNormalizedTimeCurve NormalizedTimeBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomainIndoorsOutdoorsCurve IndoorsOutdoorsBlendCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URenderSettingsCustomBlendDomain*> CustomBlends;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float BlendRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float BlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    uint8 bUnbounded: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    uint8 bEnabled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bExposureTweak: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDistanceFog: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCharacterLightRigAdjustments: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bEmissiveAdaptation: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostProcessSettings EnginePostProcessSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDistanceFog DistanceFogData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterLightRigAdjustments CharacterLightRigAdjustmentsData;
    
public:
    ARenderSettingsVolume(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UpdateEnginePostProcessing();
    
    UFUNCTION(BlueprintCallable)
    void UpdateEmissiveAdaptation(const URenderSettingsLibrary* Library);
    
    UFUNCTION(BlueprintCallable)
    void UpdateDistanceFog(const URenderSettingsLibrary* Library);
    
    UFUNCTION(BlueprintCallable)
    void UpdateCharacterLightRigAdjustments(const URenderSettingsLibrary* Library);
    
    UFUNCTION(BlueprintCallable)
    void UpdateAll();
    
    UFUNCTION(BlueprintCallable)
    void SetPriority(float NewPriority);
    
    UFUNCTION(BlueprintCallable)
    void EditProbes();
    
    UFUNCTION(BlueprintCallable)
    void EditGroups();
    
    UFUNCTION(BlueprintCallable)
    void EditExposure();
    
    UFUNCTION(BlueprintCallable)
    void EditDistanceFog();
    
    UFUNCTION(BlueprintCallable)
    void EditColorGrading();
    
    UFUNCTION(BlueprintCallable)
    void EditAll();
    
    
    // Fix for true pure virtual functions not being implemented
};

