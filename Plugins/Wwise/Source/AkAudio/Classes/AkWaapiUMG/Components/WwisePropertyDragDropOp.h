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

#include "CoreMinimal.h"
#include "Input/DragAndDrop.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Text/STextBlock.h"
#include "WaapiPicker/WwiseTreeItem.h"
#include "AkAudioStyle.h"

class AKAUDIO_API FWwisePropertyDragDropOp : public FDragDropOperation
{
public:

	DRAG_DROP_OPERATOR_TYPE(FWwisePropertyDragDropOp, FDragDropOperation)

	static TSharedRef<FWwisePropertyDragDropOp> New(const TArray<TSharedPtr<FString>>& in_Wwiseproperties)
	{
		TSharedRef<FWwisePropertyDragDropOp> Operation = MakeShareable(new FWwisePropertyDragDropOp);
#if WITH_EDITOR
		Operation->MouseCursor = EMouseCursor::GrabHandClosed;
#else 
		Operation->MouseCursor = EMouseCursor::None;
#endif
		Operation->Wwiseproperties = in_Wwiseproperties;
		Operation->Construct();

		return Operation;
	}
	
	const TArray< TSharedPtr<FString> >& GetWiseProperties() const
	{
		return Wwiseproperties;
	}

public:
	FText GetDecoratorText() const
	{
		FString Text = Wwiseproperties.Num() == 1 ? *Wwiseproperties[0].Get() : TEXT("");

		if (Wwiseproperties.Num() > 1 )
		{
			Text = FString::Printf(TEXT("Can't handle more than one Property"));
		}
		return FText::FromString(Text);
	}

	virtual TSharedPtr<SWidget> GetDefaultDecorator() const override
	{
#if WITH_EDITOR
		return 
			SNew(SBorder)
			.BorderImage(FAkAudioStyle::GetBrush("AudiokineticTools.AssetDragDropTooltipBackground"))
			.Content()
			[
				SNew(SHorizontalBox)
				// slot for the item name.
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				[
					SNew(SHorizontalBox)
					+SHorizontalBox::Slot()
					.AutoWidth()
					.Padding(3,0,3,0)
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock) 
						.Text(this, &FWwisePropertyDragDropOp::GetDecoratorText)
					]
				]
			];
#else 
		return NULL;
#endif
	}

private:
	/** Data for the asset this item represents */
	TArray<TSharedPtr<FString>> Wwiseproperties;
};
