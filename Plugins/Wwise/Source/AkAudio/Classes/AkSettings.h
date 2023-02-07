/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/

#pragma once

#include "Engine/EngineTypes.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "AssetRegistryModule.h"
#include "AkUEFeatures.h"
#include "AkRtpc.h"
#include "AkSettings.generated.h"

class UAkAcousticTexture;

USTRUCT()
struct FAkGeometrySurfacePropertiesToMap
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "AkGeometry Surface Properties Map")
	TSoftObjectPtr<class UAkAcousticTexture> AcousticTexture = nullptr;
	
	UPROPERTY(EditAnywhere, DisplayName = "Transmission Loss", Category = "AkGeometry Surface Properties Map", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float OcclusionValue = 1.f;
};

struct AkGeometrySurfaceProperties
{
	UAkAcousticTexture* AcousticTexture = nullptr;
	float OcclusionValue = 1.f;
};

USTRUCT()
struct FAkAcousticTextureParams
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY()
	FVector4 AbsorptionValues = FVector4(FVector::ZeroVector, 0.0f);
	uint32 shortID = 0;

	float AbsorptionLow() const { return AbsorptionValues[0]; }
	float AbsorptionMidLow() const { return AbsorptionValues[1]; }
	float AbsorptionMidHigh() const { return AbsorptionValues[2]; }
	float AbsorptionHigh() const { return AbsorptionValues[3]; }

	TArray<float> AsTArray() const { return { AbsorptionLow(), AbsorptionMidLow(), AbsorptionMidHigh(), AbsorptionHigh() }; }
};

#define AK_MAX_AUX_PER_OBJ	4

DECLARE_EVENT(UAkSettings, ActivatedNewAssetManagement);
DECLARE_EVENT(UAkSettings, ShowRoomsPortalsChanged);
DECLARE_EVENT(UAkSettings, AuxBusAssignmentMapChanged);
DECLARE_EVENT(UAkSettings, ReverbRTPCChanged);
DECLARE_EVENT_TwoParams(UAkSettings, SoundDataFolderChanged, const FString&, const FString&);
DECLARE_EVENT_OneParam(UAkSettings, AcousticTextureParamsChanged, const FGuid&)

UCLASS(config = Game, defaultconfig)
class AKAUDIO_API UAkSettings : public UObject
{
	GENERATED_UCLASS_BODY()

	~UAkSettings();

	// The maximum number of reverb auxiliary sends that will be simultaneously applied to a sound source
	// Reverbs from a Spatial Audio room will be active even if this maximum is reached.
	UPROPERTY(Config, EditAnywhere, DisplayName = "Max Simultaneous Reverb", Category="Reverb")
	uint8 MaxSimultaneousReverbVolumes = AK_MAX_AUX_PER_OBJ;

	// Wwise Project Path
	UPROPERTY(Config, EditAnywhere, Category="Installation", meta=(FilePathFilter="wproj", AbsolutePath))
	FFilePath WwiseProjectPath;

	// Where the Sound Data will be generated in the Content Folder
	UPROPERTY(Config, EditAnywhere, Category = "Sound Data", meta=(RelativeToGameContentDir))
	FDirectoryPath WwiseSoundDataFolder;

	UPROPERTY(Config)
	bool bAutoConnectToWAAPI_DEPRECATED;

	// Default value for Occlusion Collision Channel when creating a new Ak Component.
	UPROPERTY(Config, EditAnywhere, Category = "Occlusion")
	TEnumAsByte<ECollisionChannel> DefaultOcclusionCollisionChannel = ECollisionChannel::ECC_Visibility;
	
	// Default value for Collision Channel when fitting Ak Acoustic Portals and Ak Spatial Audio Volumes to surrounding geometry.
	UPROPERTY(Config, EditAnywhere, Category = "Fit To Geometry")
	TEnumAsByte<ECollisionChannel> DefaultFitToGeometryCollisionChannel = ECollisionChannel::ECC_WorldStatic;

	// PhysicalMaterial to AcousticTexture and Occlusion Value Map
	UPROPERTY(Config, EditAnywhere, EditFixedSize, Category = "AkGeometry Surface Properties Map")
	TMap<TSoftObjectPtr<class UPhysicalMaterial>, FAkGeometrySurfacePropertiesToMap> AkGeometryMap;

	// Global surface absorption value to use when estimating environment decay value. Acts as a global scale factor for the decay estimations. Defaults to 0.5.
	UPROPERTY(Config, EditAnywhere, Category = "Reverb Assignment Map", meta = (ClampMin = 0.1f, ClampMax = 1.0f, UIMin = 0.1f, UIMax = 1.0f))
	float GlobalDecayAbsorption;

	// Default reverb aux bus to apply to rooms
	UPROPERTY(Config, EditAnywhere, Category = "Reverb Assignment Map")
	TSoftObjectPtr<class UAkAuxBus> DefaultReverbAuxBus = nullptr;
	
	// RoomDecay to AuxBusID Map. Used to automatically assign aux bus ids to rooms depending on their volume and surface area.
	UPROPERTY(Config, EditAnywhere, Category = "Reverb Assignment Map")
	TMap<float, TSoftObjectPtr<class UAkAuxBus>> EnvironmentDecayAuxBusMap;

	UPROPERTY(Config, EditAnywhere, Category = "Reverb Assignment Map|RTPCs")
	FString HFDampingName = "";

	UPROPERTY(Config, EditAnywhere, Category = "Reverb Assignment Map|RTPCs")
	FString DecayEstimateName = "";

	UPROPERTY(Config, EditAnywhere, Category = "Reverb Assignment Map|RTPCs")
	FString TimeToFirstReflectionName = "";

	UPROPERTY(Config, EditAnywhere, Category = "Reverb Assignment Map|RTPCs")
	TSoftObjectPtr<UAkRtpc> HFDampingRTPC = nullptr;

	UPROPERTY(Config, EditAnywhere, Category = "Reverb Assignment Map|RTPCs")
	TSoftObjectPtr<UAkRtpc> DecayEstimateRTPC = nullptr;

	UPROPERTY(Config, EditAnywhere, Category = "Reverb Assignment Map|RTPCs")
	TSoftObjectPtr<UAkRtpc> TimeToFirstReflectionRTPC = nullptr;

	// Input event associated with the Wwise Audio Input
	UPROPERTY(Config, EditAnywhere, Category = "Audio Mixer")
	TSoftObjectPtr<class UAkAudioEvent> AudioInputEvent = nullptr;

	UPROPERTY(Config)
	TMap<FGuid, FAkAcousticTextureParams> AcousticTextureParamsMap;

	// When generating the event data, the media contained in switch containers will be splitted by state/switch value
	// and only loaded if the state/switch value are currently loaded
	UPROPERTY(Config, EditAnywhere, Category = "Sound Data", meta=(EditCondition="UseEventBasedPackaging"))
	bool SplitSwitchContainerMedia = false;

	// Split Media folder into several folders.
	// Perforce has a limit of 32000 files per folder, if you are using Perforce you are strongly suggested to enable this.
	UPROPERTY(Config, EditAnywhere, Category = "Sound Data", meta = (EditCondition = "UseEventBasedPackaging"))
	bool SplitMediaPerFolder = false;

	// Enable the new Event-based Soundbank Pipeline
	// When ticking this to true, it will delete the content of the SoundBank folder
	// and modify the Wwise project for the required changes in the project settings.
	// The new assets will be created the next time you open the editor.
	UPROPERTY(Config, EditAnywhere, Category = "Sound Data", meta=(DisplayName="Use Event-Based Packaging"))
	bool UseEventBasedPackaging = false;

	UPROPERTY(Config)
	bool EnableAutomaticAssetSynchronization_DEPRECATED;

	// Commit message that GenerateSoundBanksCommandlet will use
	UPROPERTY(Config, EditAnywhere, Category = "Sound Data")
	FString CommandletCommitMessage = TEXT("Unreal Wwise Sound Data auto-generation");
	
	UPROPERTY(Config, EditAnywhere, Category = "Sound Data")
	TMap<FString, FString> UnrealCultureToWwiseCulture;

	UPROPERTY(Config)
	bool AskedToUseNewAssetManagement = false;

	UPROPERTY(Config)
	bool bEnableMultiCoreRendering_DEPRECATED = false;

	UPROPERTY(Config)
	bool MigratedEnableMultiCoreRendering = false;

	UPROPERTY(Config)
	bool FixupRedirectorsDuringMigration = false;

	UPROPERTY(Config)
	FDirectoryPath WwiseWindowsInstallationPath_DEPRECATED;

	UPROPERTY(Config)
	FFilePath WwiseMacInstallationPath_DEPRECATED;

	static FString DefaultSoundDataFolder;



	virtual void PostInitProperties() override;

	bool ReverbRTPCsInUse() const;
	bool DecayRTPCInUse() const;
	bool DampingRTPCInUse() const;
	bool PredelayRTPCInUse() const;

	bool GetAssociatedAcousticTexture(const UPhysicalMaterial* physMaterial, UAkAcousticTexture*& acousticTexture) const;
	bool GetAssociatedOcclusionValue(const UPhysicalMaterial* physMaterial, float& occlusionValue) const;

#if WITH_EDITOR
#if AK_SUPPORT_WAAPI
	/** This needs to be called after the waapi client has been initialized, which happens after AkSettings is constructed. */
	void InitWaapiSync();
	/** Set the color of a UAkAcousticTexture asset using a color from the UnrealWwiseObjectColorPalette (this is the same as the 'dark theme' in Wwise Authoring). Send a colorIndex of -1 to use the 'unset' color. */
	void SetTextureColor(FGuid textureID, int colorIndex);
#endif
	void EnsureSoundDataPathIsInAlwaysCook() const;
	void RemoveSoundDataFromAlwaysStageAsUFS(const FString& SoundDataPath);
	void EnsurePluginContentIsInAlwaysCook() const;
	void InitAkGeometryMap();
	void DecayAuxBusMapChanged();
	void SortDecayKeys();
	static float MinimumDecayKeyDistance;
#endif

protected:
#if WITH_EDITOR
	virtual void PostEditChangeProperty( struct FPropertyChangedEvent& PropertyChangedEvent ) override;
#if UE_4_25_OR_LATER
	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;
#else
	virtual void PreEditChange(UProperty* PropertyAboutToChange) override;
#endif
#endif

private:
#if WITH_EDITOR
	FString PreviousWwiseProjectPath;
	FString PreviousWwiseSoundBankFolder;
	bool bTextureMapInitialized = false;
	TMap< UPhysicalMaterial*, UAkAcousticTexture* > TextureMapInternal;
	FAssetRegistryModule* AssetRegistryModule;

	void OnAssetAdded(const FAssetData& NewAssetData);
	void OnAssetRemoved(const struct FAssetData& AssetData);
	void FillAkGeometryMap(const TArray<FAssetData>& PhysicalMaterials, const TArray<FAssetData>& AcousticTextureAssets);
	void UpdateAkGeometryMap();
	void RemoveSoundDataFromAlwaysCook(const FString& SoundDataPath);
	void AddSoundDataToAlwaysStageAsUFS();
	void SplitOrMergeMedia();

	bool bAkGeometryMapInitialized = false;
	TMap< UPhysicalMaterial*, UAkAcousticTexture* > PhysicalMaterialAcousticTextureMap;
	TMap< UPhysicalMaterial*, float > PhysicalMaterialOcclusionMap;

	// This is used to track which key has changed and restrict its value between the two neighbouring keys
	TMap<float, TSoftObjectPtr<class UAkAuxBus>> PreviousDecayAuxBusMap;

#if AK_SUPPORT_WAAPI
	TMap<FGuid, TArray<uint64>> WaapiTextureSubscriptions;
	TMap<FGuid, uint64> WaapiTextureColorSubscriptions;
	TMap<FGuid, uint64> WaapiTextureColorOverrideSubscriptions;
	FDelegateHandle WaapiProjectLoadedHandle;
	FDelegateHandle WaapiConnectionLostHandle;
#endif
#endif

public:
	bool bRequestRefresh = false;
	const FAkAcousticTextureParams* GetTextureParams(const uint32& shortID) const;
#if WITH_EDITOR
	mutable ActivatedNewAssetManagement OnActivatedNewAssetManagement;
	mutable SoundDataFolderChanged OnSoundDataFolderChanged;
	void ClearAkRoomDecayAuxBusMap();
	void InsertDecayKeyValue(const float& decayKey);
	void SetAcousticTextureParams(const FGuid& textureID, const FAkAcousticTextureParams& params);
	void ClearTextureParamsMap();
#if AK_SUPPORT_WAAPI
	void WaapiProjectLoaded();
	void WaapiDisconnected();
	void RegisterWaapiTextureCallback(const FGuid& textureID);
	void UnregisterWaapiTextureCallback(const FGuid& textureID);
	void ClearWaapiTextureCallbacks();
	/** Use WAAPI to query the absorption params for a given texture and store them in the texture params map. */
	void UpdateTextureParams(const FGuid& textureID);
	/** Use WAAPI to query the color for a given texture and Update the corresponding UAkAcousticTexture asset. */
	void UpdateTextureColor(const FGuid& textureID);
	mutable AcousticTextureParamsChanged OnTextureParamsChanged;
#endif // AK_SUPPORT_WAAPI
#endif // WITH_EDITOR

#if WITH_EDITORONLY_DATA
	// Visualize rooms and portals in the viewport. This requires 'realtime' to be enabled in the viewport.
	UPROPERTY(Config, EditAnywhere, Category = "Viewports")
	bool VisualizeRoomsAndPortals = false;
	ShowRoomsPortalsChanged OnShowRoomsPortalsChanged;
	AuxBusAssignmentMapChanged OnAuxBusAssignmentMapChanged;
	ReverbRTPCChanged OnReverbRTPCChanged;
#endif

	/** Get the associated AuxBus for the given environment decay value.
	 * Return the AuxBus associated to the next highest decay value in the EnvironmentDecayAuxBusMap, after the given value. 
	 */
	void GetAuxBusForDecayValue(float decay, class UAkAuxBus*& auxBus);

	void GetAudioInputEvent(class UAkAudioEvent*& OutInputEvent);

};

