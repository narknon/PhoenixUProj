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

#include "WwisePicker/WwiseAssetDragDropOp.h"

#include "AkAudioType.h"
#include "AkUnrealHelper.h"
#include "AssetManagement/AkAssetDatabase.h"
#include "ContentBrowserModule.h"
#include "Misc/Paths.h"

#define LOCTEXT_NAMESPACE "AkAudio"

TSharedRef<FAssetDragDropOp> FWwiseAssetDragDropOp::New(const FAssetData& InAssetData, UActorFactory* ActorFactory)
{
	TArray<FAssetData> AssetDataArray;
	AssetDataArray.Emplace(InAssetData);
	return New(MoveTemp(AssetDataArray), TArray<FString>(), ActorFactory);
}

TSharedRef<FAssetDragDropOp> FWwiseAssetDragDropOp::New(TArray<FAssetData> InAssetData, UActorFactory* ActorFactory)
{
	return New(MoveTemp(InAssetData), TArray<FString>(), ActorFactory);
}

TSharedRef<FAssetDragDropOp> FWwiseAssetDragDropOp::New(FString InAssetPath)
{
	TArray<FString> AssetPathsArray;
	AssetPathsArray.Emplace(MoveTemp(InAssetPath));
	return New(TArray<FAssetData>(), MoveTemp(AssetPathsArray), nullptr);
}

TSharedRef<FAssetDragDropOp> FWwiseAssetDragDropOp::New(TArray<FString> InAssetPaths)
{
	return New(TArray<FAssetData>(), MoveTemp(InAssetPaths), nullptr);
}

TSharedRef<FAssetDragDropOp> FWwiseAssetDragDropOp::New(TArray<FAssetData> InAssetData, TArray<FString> InAssetPaths, UActorFactory* ActorFactory)
{
	TSharedRef<FAssetDragDropOp> ParentOperation = FAssetDragDropOp::New(InAssetData, InAssetPaths, ActorFactory);

	FWwiseAssetDragDropOp* RawPointer = new FWwiseAssetDragDropOp();
	TSharedRef<FWwiseAssetDragDropOp> Operation = MakeShareable(RawPointer);
	// ugly hack since FAssetDragDropOp data is private
	static_cast<FAssetDragDropOp*>(RawPointer)->operator=(ParentOperation.Get());

	FAssetViewDragAndDropExtender::FOnDropDelegate DropDelegate = FAssetViewDragAndDropExtender::FOnDropDelegate::CreateRaw(RawPointer, &FWwiseAssetDragDropOp::OnAssetViewDrop);
	FAssetViewDragAndDropExtender::FOnDragOverDelegate DragOverDelegate = FAssetViewDragAndDropExtender::FOnDragOverDelegate::CreateRaw(RawPointer, &FWwiseAssetDragDropOp::OnAssetViewDragOver);
	FAssetViewDragAndDropExtender::FOnDragLeaveDelegate DragLeaveDelegate = FAssetViewDragAndDropExtender::FOnDragLeaveDelegate::CreateRaw(RawPointer, &FWwiseAssetDragDropOp::OnAssetViewDragLeave);
	Operation->Extender = new FAssetViewDragAndDropExtender(DropDelegate, DragOverDelegate, DragLeaveDelegate);

	FContentBrowserModule& ContentBrowserModule = FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");
	TArray<FAssetViewDragAndDropExtender>& AssetViewDragAndDropExtenders = ContentBrowserModule.GetAssetViewDragAndDropExtenders();
	AssetViewDragAndDropExtenders.Add(*(Operation->Extender));

	return Operation;
}

FWwiseAssetDragDropOp::~FWwiseAssetDragDropOp()
{
	FContentBrowserModule& ContentBrowserModule = FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");
	TArray<FAssetViewDragAndDropExtender>& AssetViewDragAndDropExtenders = ContentBrowserModule.GetAssetViewDragAndDropExtenders();
	for (int32 i = 0; i < AssetViewDragAndDropExtenders.Num(); i++)
	{
		if (AssetViewDragAndDropExtenders[i].OnDropDelegate.IsBoundToObject(this))
		{
			AssetViewDragAndDropExtenders.RemoveAt(i);
		}
	}

	delete Extender;
}

bool FWwiseAssetDragDropOp::OnAssetViewDrop(const FAssetViewDragAndDropExtender::FPayload& Payload)
{
	return CanDrop;
}

bool FWwiseAssetDragDropOp::OnAssetViewDragOver(const FAssetViewDragAndDropExtender::FPayload& Payload)
{
	if (!Payload.DragDropOp->IsOfType<FWwiseAssetDragDropOp>())
	{
		SetCanDrop(false);
		return false;
	}
	
	auto assetDragDrop = static_cast<FWwiseAssetDragDropOp*>(Payload.DragDropOp.Get());

	auto& assets = assetDragDrop->GetAssets();

	for (int32 assetIndex = 0; assetIndex < assets.Num(); ++assetIndex)
	{
		auto& assetData = assets[assetIndex];

		for (auto& packagePath : Payload.PackagePaths)
		{
			if (!AkAssetDatabase::Get().CanBeDropped(assetData, packagePath, AkAssetDatabase::CanBeDroppedSource::FromPicker))
			{
				SetCanDrop(false);
				return true;
			}
		}
	}

	SetCanDrop(true);

	return false;
}

bool FWwiseAssetDragDropOp::OnAssetViewDragLeave(const FAssetViewDragAndDropExtender::FPayload& Payload)
{
	SetCanDrop(false);
	return false;
}

void FWwiseAssetDragDropOp::SetCanDrop(const bool InCanDrop)
{
	CanDrop = InCanDrop;
	SetTooltipText();

	if (InCanDrop)
	{
		MouseCursor = EMouseCursor::GrabHandClosed;
		SetToolTip(GetTooltipText(), NULL);
	}
	else
	{
		MouseCursor = EMouseCursor::SlashedCircle;
		SetToolTip(GetTooltipText(), FEditorStyle::GetBrush(TEXT("Graph.ConnectorFeedback.Error")));
	}
}

void FWwiseAssetDragDropOp::SetTooltipText()
{
	if (CanDrop)
	{
		auto& assets = GetAssets();
		FString Text = assets.Num() ? assets[0].AssetName.ToString() : TEXT("");

		if (assets.Num() > 1)
		{
			Text += TEXT(" ");
			Text += FString::Printf(TEXT("and %d other(s)"), assets.Num() - 1);
		}
		CurrentHoverText = FText::FromString(Text);
	}
	else
	{
		CurrentHoverText = LOCTEXT("OnDragAkEventsOverFolder_CannotDrop", "Wwise assets can only be dropped in the right folder");
	}
}

FText FWwiseAssetDragDropOp::GetTooltipText() const
{
	return CurrentHoverText;
}

#undef LOCTEXT_NAMESPACE