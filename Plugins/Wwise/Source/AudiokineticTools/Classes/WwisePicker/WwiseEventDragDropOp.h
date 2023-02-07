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


/*------------------------------------------------------------------------------------
	WwiseEventDragDropOp.h
------------------------------------------------------------------------------------*/
#pragma once

#include "WaapiPicker/WwiseTreeItem.h"
#include "DragAndDrop/DecoratedDragDropOp.h"
#include "ContentBrowserDelegates.h"

class FWwiseEventDragDropOp : public FDecoratedDragDropOp
{
public:
	DRAG_DROP_OPERATOR_TYPE(FWwiseEventDragDropOp, FDecoratedDragDropOp)

	const FSlateBrush* Icon;
	
	static TSharedRef<FWwiseEventDragDropOp> New(TArray<TSharedPtr<FWwiseTreeItem>> InAssets);
	~FWwiseEventDragDropOp();
	virtual FCursorReply OnCursorQuery() override;

	void SetCanDrop(const bool CanDrop);
	bool OnAssetViewDrop(const FAssetViewDragAndDropExtender::FPayload& Payload);
	bool OnAssetViewDragOver(const FAssetViewDragAndDropExtender::FPayload& Payload);
	bool OnAssetViewDragLeave(const FAssetViewDragAndDropExtender::FPayload& Payload);
	static UObject* RecurseCreateAssets(const TSharedPtr<FWwiseTreeItem>& Asset, const FString& PackagePath);

	const TArray<TSharedPtr<FWwiseTreeItem>>& GetWiseItems() const;

	void SetTooltipText();
	FText GetTooltipText() const;
	virtual TSharedPtr<SWidget> GetDefaultDecorator() const override;
	FAssetViewDragAndDropExtender* pExtender;

private:	
	
	/** Data for the asset this item represents */
	TArray<TSharedPtr<FWwiseTreeItem>> WwiseAssets;

	bool CanDrop;
};