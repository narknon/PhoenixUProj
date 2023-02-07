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

#include "PropertyEditorModule.h"
#include "IDetailCustomization.h"
//////////////////////////////////////////////////////////////////////////
// FAkSurfaceReflectorSetDetailsCustomization

class IDetailCategoryBuilder;
class STextBlock;

class FAkSurfaceReflectorSetDetailsCustomization : public IDetailCustomization
{
public:
	FAkSurfaceReflectorSetDetailsCustomization();
	~FAkSurfaceReflectorSetDetailsCustomization();
	// Makes a new instance of this detail layout class for a specific detail view requesting it
	static TSharedRef<IDetailCustomization> MakeInstance();

	// IDetailCustomization interface
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailLayout) override;
	// End of IDetailCustomization interface

private:
	IDetailLayoutBuilder* MyDetailLayout;
	TSharedPtr<STextBlock> SelectionInfoLabel;
	TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized;
	class UAkSurfaceReflectorSetComponent* ReflectorSetBeingCustomized;
	FReply OnEnableEditModeClicked();
	FReply OnDisableEditModeClicked();
	// In geometry edit mode, when the face selection is changed for an actor, the OnObjectModified delegate is broadcast before the selected faces are updated.
	// For that reason, we use a flag to indicate when an object has been modified this frame.
	// That flag is used in OnRedrawViewports - which happens later - to refresh the details panel in case the selected faces have changed.
	bool SelectedObjectModifiedThisFrame = false;
	void OnObjectModified(UObject* Object);
	void OnRedrawViewports();

	void OnEnableValueChanged();
	void OnGeometryChanged();
	void SetupGeometryModificationHandlers();
};
