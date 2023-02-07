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

#include "AkAcousticTexture.h"
#include "AkUEFeatures.h"
#include "AssetThumbnail.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/SCompoundWidget.h"
#include "Editor.h"

#if WITH_EDITOR
#if UE_4_25_OR_LATER
#define GEOMETRY_EDIT_DISPLAY_NAME "Brush Editing Mode"
#else
#define GEOMETRY_EDIT_DISPLAY_NAME "Geometry Editing Mode"
#endif
#endif

class UAkSurfaceReflectorSetComponent;
class IDetailLayoutBuilder;
class IDetailCategoryBuilder;
class UTransBuffer;
class STextBlock;
struct FAkSurfacePoly;

class SAcousticSurfacesLabels : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAcousticSurfacesLabels) {}
	SLATE_END_ARGS()

	AUDIOKINETICTOOLS_API void Construct(const FArguments& InArgs, TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized);
private:
	TArray<TWeakObjectPtr<UObject>> ComponentsBeingCustomized;
	// Transmission Loss and Enable Surface Visibility
	EVisibility TransmissionLossEnableSurfaceVisibility();
};

class SAcousticSurfacesController : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAcousticSurfacesController) {}
	SLATE_END_ARGS()

	AUDIOKINETICTOOLS_API void Construct(const FArguments& InArgs
		,TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized
		,IDetailLayoutBuilder* InLayoutBuilder
	);
	
	~SAcousticSurfacesController();

private:
	void BuildSlate();

	/** The details layout in the editor */
	IDetailLayoutBuilder* LayoutBuilder;
	/** The list of objects being customized. This is stored because we need to change which faces to use when notified that the editor mode is changing.
	(See OnEditorModeChanged, OnEditorModeExited).
	*/
	TArray<TWeakObjectPtr<UObject>> ComponentsToEdit;
	/** Map of UAkSurfaceReflectorSetComponents to sets of selected face indices. */
	typedef TMap<UAkSurfaceReflectorSetComponent*, TSet<int>> ReflectorSetsSelectedFaces;
	ReflectorSetsSelectedFaces ReflectorSetsFacesToEdit;
	void InitReflectorSetsFacesToEdit();
	/** Helper function to get an acoustic surface, with assert for indexing.  */
	FAkSurfacePoly& GetAcousticSurfaceChecked(UAkSurfaceReflectorSetComponent* reflectorSet, int faceIndex);
	/** Refresh the viewport and details panel in the editor. If reinitVisualizers = true, update the edge map and recreate the text visualizers on the selected USurfaceReflectorSetComponents */
	void RefreshEditor(bool reinitVisualizers = false) const;
	void BeginModify(FText TransactionText);
	void EndModify();

	FDelegateHandle OnPropertyChangedHandle;
	void OnPropertyChanged(UObject* ObjectBeingModified, FPropertyChangedEvent& PropertyChangedEvent);
	
	int NumFacesSelected = 0;
	FText GetSelectionText() const;
	FText GetSelectionTextTooltip() const;
	/** Determines whether we should apply the changes to all faces in the AkSurfaceReflectorComponent or just those that are selected.
	Ideally we could just check if geometry mode is enabled during Construct, and refresh the details panel when the mode is changed. 
	However, the notifications are sent before the active modes are updated in the GLevelEditorModeTools, so this wouldn't work. */
	bool ApplyToAllFaces = false;
	void OnEditorModeChanged(const FEditorModeID& InEditorModeID, bool bIsEnteringMode);

	/** Update the current collective texture, occlusion, and enablement for all considered faces on the component(s) */
	void UpdateCurrentValues();

	// Texture state and controls
	bool TexturesDiffer = false;
	UAkAcousticTexture* CurrentTexture = nullptr;

	EVisibility OverrideTextureControlsVisibility();
	FReply OnOverrideTextureButtonClicked();

	UAkAcousticTexture* GetCollectiveTexture(bool& ValuesDiffer);
	void OnTextureAssetChanged(const FAssetData& InAssetData);
	FString GetSelectedTextureAssetPath() const;

	// Transmission Loss and Enable Surface Visibility
	EVisibility TransmissionLossEnableSurfaceVisibility();

	// Occlusion state and controls
	bool OcclusionsDiffer = false;
	float CurrentOcclusion = 0.0f;

	EVisibility OverrideOcclusionControlsVisibility();
	FReply OnOverrideOcclusionButtonClicked();

	float GetCollectiveOcclusion(bool& ValuesDiffer);
	TOptional<float> GetOcclusionSliderValue() const;
	void OnOcclusionSliderChanged(float NewValue, ETextCommit::Type Commit);

	// Enable Surface state and controls
	bool EnablementsDiffer = false;
	bool CurrentEnablement = false;

	bool GetCollectiveEnableSurface(bool& ValuesDiffer);
	ECheckBoxState GetEnableSurfaceCheckBoxState() const;
	void OnEnableCheckboxChanged(ECheckBoxState NewState);

#if AK_SUPPORT_WAAPI
	// Register a pre-delete WAAPI callback for the acoustic texture asset (if it is valid) 
	void RegisterTextureDeletedCallback();
	// Remove the existing pre-delete WAAPI callback for the acoustic texture asset.
	void RemoveTextureDeletedCallback();
	uint64 TextureDeleteSubscriptionID;
#endif
};