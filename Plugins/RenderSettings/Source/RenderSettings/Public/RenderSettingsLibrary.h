#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LastRenderedExposureFilterTimeConstants.h"
#include "RenderSettingsCustomBlendDomainConsoleEntry.h"
#include "RenderSettingsCustomBlendDomainEntry.h"
#include "RenderSettingsLibrary.generated.h"

class UCharacterLightRigAdjustmentsSettings;
class UDistanceFogSettings;
class URenderSettingsBlendDomainConsoleLiens;
class URenderSettingsEmissiveAdaptationSettings;
class URenderSettingsPPAmbientSettings;
class URenderSettingsPPBloomSettings;
class URenderSettingsPPColorGradingSettings;
class URenderSettingsPPDepthOfFieldSettings;
class URenderSettingsPPExposureSettings;
class URenderSettingsPPFilmSettings;
class URenderSettingsPPLensFXSettings;
class URenderSettingsPPMotionBlurSettings;
class URenderSettingsPPProbesSettings;
class URenderSettingsPPScreenSpaceReflectionsSettings;
class URenderSettingsPostProcessingGroupSettings;

UCLASS(Blueprintable)
class RENDERSETTINGS_API URenderSettingsLibrary : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostProcessingPriorityBoost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InsideTransitionDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AudioInsideTransitionDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IndoorsOutdoorsFiltering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IndoorsOutdoorsTeleportDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLastRenderedExposureFilterTimeConstants ExposureTimeConstants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsPostProcessingGroupSettings* PostProcessingGroupSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsPPExposureSettings* ExposureSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsPPColorGradingSettings* ColorGradingSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsPPFilmSettings* FilmSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsPPLensFXSettings* LensFXSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsPPBloomSettings* BloomSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsPPMotionBlurSettings* MotionBlurSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsPPDepthOfFieldSettings* DepthOfFieldSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsPPAmbientSettings* AmbientSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsPPScreenSpaceReflectionsSettings* ScreenSpaceReflectionsSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsPPProbesSettings* ProbeSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsEmissiveAdaptationSettings* EmissiveAdaptationSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDistanceFogSettings* DistanceFogSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCharacterLightRigAdjustmentsSettings* CharacterLightRigAdjustmentsSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderSettingsCustomBlendDomainEntry> CustomBlendDomains;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderSettingsCustomBlendDomainConsoleEntry> ConsoleCustomBlendDomains;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsBlendDomainConsoleLiens* GlobalBlendDomainConsoleVars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AutoDisableWorldNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGlobalDisableLevelDefaults;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPostProcessingPriorityBoost;
    
    URenderSettingsLibrary();
};

