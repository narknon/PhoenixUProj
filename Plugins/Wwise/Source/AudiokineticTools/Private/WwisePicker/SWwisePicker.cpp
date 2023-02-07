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
	SWwisePicker.cpp
------------------------------------------------------------------------------------*/

#include "WwisePicker/SWwisePicker.h"

#include "AkAudioBankGenerationHelpers.h"
#include "AkAudioDevice.h"
#include "AkAudioStyle.h"
#include "AkAudioType.h"
#include "AkSettings.h"
#include "AkSettingsPerUser.h"
#include "AkUnrealHelper.h"
#include "AkWaapiClient.h"
#include "AssetData.h"
#include "AssetManagement/AkAssetDatabase.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "DirectoryWatcherModule.h"
#include "DragAndDrop/AssetDragDropOp.h"
#include "Editor/UnrealEd/Public/PackageTools.h"
#include "IDirectoryWatcher.h"
#include "Misc/ScopedSlowTask.h"
#include "Widgets/Input/SHyperlink.h"
#include "Widgets/Input/SSearchBox.h"
#include "Widgets/Layout/SSeparator.h"
#include "Widgets/Layout/SSpacer.h"
#include "WwisePicker/WwiseAssetDragDropOp.h"
#include "WwisePicker/WwiseEventDragDropOp.h"
#include "WwisePickerBuilderVisitor.h"

#define LOCTEXT_NAMESPACE "AkAudio"

const FName SWwisePicker::WwisePickerTabName = "WwisePicker";

namespace SWwisePicker_Helper
{
	const FName DirectoryWatcherModuleName = "DirectoryWatcher";
}

SWwisePicker::SWwisePicker()
{
	AllowTreeViewDelegates = true;
	isPickerVisible = !FAkWaapiClient::IsProjectLoaded();

	builderVisitor = MakeUnique<WwisePickerBuilderVisitor>();

	workUnitParser.SetVisitor(builderVisitor.Get());
}

void SWwisePicker::RemoveClientCallbacks()
{
	auto pWaapiClient = FAkWaapiClient::Get();
	if (pWaapiClient != nullptr)
	{
		if (ProjectLoadedHandle.IsValid())
		{
			pWaapiClient->OnProjectLoaded.Remove(ProjectLoadedHandle);
			ProjectLoadedHandle.Reset();
		}
		if (ConnectionLostHandle.IsValid())
		{
			pWaapiClient->OnConnectionLost.Remove(ConnectionLostHandle);
			ConnectionLostHandle.Reset();
		}
	}
}

void SWwisePicker::UpdateDirectoryWatcher()
{
	FString OldProjectFolder = ProjectFolder;
	auto WwiseProjectPath = AkUnrealHelper::GetWwiseProjectPath();
	ProjectFolder = FPaths::GetPath(WwiseProjectPath);
	ProjectName = FPaths::GetCleanFilename(AkUnrealHelper::GetWwiseProjectPath());

	auto& DirectoryWatcherModule = FModuleManager::LoadModuleChecked<FDirectoryWatcherModule>(SWwisePicker_Helper::DirectoryWatcherModuleName);
	if (ProjectDirectoryModifiedDelegateHandle.IsValid())
	{
		DirectoryWatcherModule.Get()->UnregisterDirectoryChangedCallback_Handle(OldProjectFolder, ProjectDirectoryModifiedDelegateHandle);
	}

	if (FPaths::FileExists(WwiseProjectPath))
	{
		DirectoryWatcherModule.Get()->RegisterDirectoryChangedCallback_Handle(
			ProjectFolder
			, IDirectoryWatcher::FDirectoryChanged::CreateRaw(this, &SWwisePicker::OnProjectDirectoryChanged)
			, ProjectDirectoryModifiedDelegateHandle
		);
	}
}

void SWwisePicker::OnProjectDirectoryChanged(const TArray<struct FFileChangeData>& ChangedFiles)
{
	bool bFoundWorkUnit = false;
	bool bProjectChanged = false;

	for(auto& File : ChangedFiles)
	{
		if(File.Filename.EndsWith(FString(".wwu")))
		{
			bFoundWorkUnit = true;
			break;
		}
		if (File.Filename.EndsWith(FString(".wproj")))
		{
			bProjectChanged = true;
			break;
		}
	}
	
	if(bFoundWorkUnit)
	{
		//Parse project, work units and construct tree
		OnPopulateClicked();
	}
	else if (bProjectChanged)
	{
		//only parse project to see if physical folders changed
		workUnitParser.ParsePhysicalFolders();
		ConstructTree();
	}
}

SWwisePicker::~SWwisePicker()
{
	RootItems.Empty();
	RemoveClientCallbacks();
	auto pWaapiClient = FAkWaapiClient::Get();
	if (pWaapiClient != nullptr)
	{
		pWaapiClient->OnClientBeginDestroy.Remove(ClientBeginDestroyHandle);
	}

	if (ProjectDirectoryModifiedDelegateHandle.IsValid())
	{
		auto& DirectoryWatcherModule = FModuleManager::LoadModuleChecked<FDirectoryWatcherModule>(SWwisePicker_Helper::DirectoryWatcherModuleName);
		DirectoryWatcherModule.Get()->UnregisterDirectoryChangedCallback_Handle(ProjectFolder, ProjectDirectoryModifiedDelegateHandle);
	}
}

void SWwisePicker::Construct(const FArguments& InArgs)
{
	if(isPickerVisible)
		UpdateDirectoryWatcher();

	SearchBoxFilter = MakeShareable( new StringFilter( StringFilter::FItemToStringArray::CreateSP( this, &SWwisePicker::PopulateSearchStrings ) ) );
	SearchBoxFilter->OnChanged().AddSP( this, &SWwisePicker::FilterUpdated );

    UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
    AkSettings->bRequestRefresh = false;
    
	ChildSlot
	[
		SNew(SBorder)
		.Padding(4)
		.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
		[
			SNew(SOverlay)

			// Picker
			+ SOverlay::Slot()
			.VAlign(VAlign_Fill)
			[
				SNew(SVerticalBox)
				.Visibility(this, &SWwisePicker::isPickerAllowed)

				// Search
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0, 1, 0, 3)
				[
					SNew(SHorizontalBox)

					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						InArgs._SearchContent.Widget
					]

					+ SHorizontalBox::Slot()
					.FillWidth(1.0f)
					[
						SNew(SSearchBox)
						.HintText( LOCTEXT( "WwisePickerSearchTooltip", "Search Wwise Item" ) )
						.OnTextChanged( this, &SWwisePicker::OnSearchBoxChanged )
						.SelectAllTextWhenFocused(false)
						.DelayChangeNotificationsWhileTyping(true)
					]
				]

				// Tree title
				+SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.Padding(3.0f)
					[
						SNew(SImage) 
						.Image(FAkAudioStyle::GetBrush(EWwiseItemType::Project))
					]

					+ SHorizontalBox::Slot()
					.AutoWidth()
					.Padding(0,0,3,0)
					[
						SNew(STextBlock)
						.Font( FEditorStyle::GetFontStyle("ContentBrowser.SourceTitleFont") )
						.Text( this, &SWwisePicker::GetProjectName )
						.Visibility(InArgs._ShowTreeTitle ? EVisibility::Visible : EVisibility::Collapsed)
					]

					+ SHorizontalBox::Slot()
					.FillWidth(1)
					[
						SNew( SSpacer )
					]

					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SButton)
						.Text(LOCTEXT("AkPickerPopulate", "Populate"))
						.OnClicked(this, &SWwisePicker::OnPopulateClicked)
					]
					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SButton)
						.Text(LOCTEXT("AkPickerGenerate", "Generate Sound Data..."))
						.OnClicked(this, &SWwisePicker::OnGenerateSoundBanksClicked)
					]
				]

				// Separator
				+SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0, 0, 0, 1)
				[
					SNew(SSeparator)
					.Visibility( ( InArgs._ShowSeparator) ? EVisibility::Visible : EVisibility::Collapsed )
				]
				
				// Tree
				+SVerticalBox::Slot()
				.FillHeight(1.f)
				[
					SAssignNew(TreeViewPtr, STreeView< TSharedPtr<FWwiseTreeItem> >)
					.TreeItemsSource(&RootItems)
					.OnGenerateRow( this, &SWwisePicker::GenerateRow )
					//.OnItemScrolledIntoView( this, &SPathView::TreeItemScrolledIntoView )
					.ItemHeight(18)
					.SelectionMode(InArgs._SelectionMode)
					.OnSelectionChanged(this, &SWwisePicker::TreeSelectionChanged)
					.OnExpansionChanged(this, &SWwisePicker::TreeExpansionChanged)
					.OnGetChildren( this, &SWwisePicker::GetChildrenForTree )
					//.OnSetExpansionRecursive( this, &SPathView::SetTreeItemExpansionRecursive )
					//.OnContextMenuOpening(this, &SPathView::MakePathViewContextMenu)
					.ClearSelectionOnClick(false)
				]
			]

			// Empty Picker
			+ SOverlay::Slot()
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				.AutoHeight()
				[
					SNew(STextBlock)
					.Visibility(this, &SWwisePicker::isWarningVisible)
					.AutoWrapText(true)
					.Justification(ETextJustify::Center)
					.Text(LOCTEXT("EmptyWwiseTree", "WAAPI connection available; the Wwise Picker has been disabled. Please use the WAAPI Picker."))
				]
				+ SVerticalBox::Slot()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				.AutoHeight()
				[
					SNew(SHyperlink)
					.Visibility(this, &SWwisePicker::isWarningVisible)
					.Text(LOCTEXT("WaapiDucumentation", "For more informaton, please Visit Waapi Documentation."))
					.ToolTipText(LOCTEXT("WaapiDucumentationTooltip", "Opens Waapi documentation in a new browser window"))
					.OnNavigate_Lambda([=]() { FPlatformProcess::LaunchURL(*FString("https://www.audiokinetic.com/library/?source=SDK&id=waapi.html"), nullptr, nullptr); })
				]
			]
		]
	];

	auto pWaapiClient = FAkWaapiClient::Get();
	if (pWaapiClient)
	{
		/* Empty the tree when we have the same project */
		ProjectLoadedHandle = pWaapiClient->OnProjectLoaded.AddLambda([this]()
		{
			isPickerVisible = false;
			RootItems.Empty();
			ConstructTree();
		});
		/* Construct the tree when we have different projects */
		ConnectionLostHandle = pWaapiClient->OnConnectionLost.AddLambda([this]()
		{
			isPickerVisible = true;
			ForceRefresh();
		});
		ClientBeginDestroyHandle = pWaapiClient->OnClientBeginDestroy.AddLambda([this]()
		{
			RemoveClientCallbacks();
		});
	}

	InitialParse();
}

EVisibility SWwisePicker::isPickerAllowed() const
{
	if (isPickerVisible)
		return EVisibility::Visible;
	return EVisibility::Hidden;
}

EVisibility SWwisePicker::isWarningVisible() const
{
	if (!isPickerVisible)
		return EVisibility::Visible;
	return EVisibility::Hidden;
}

void SWwisePicker::Tick( const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime )
{
	UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
    if(AkSettings->bRequestRefresh)
    {
        ForceRefresh();
        AkSettings->bRequestRefresh = false;
    }
}

void SWwisePicker::ForceRefresh()
{
	workUnitParser.ForceParse();
	UpdateDirectoryWatcher();
	ConstructTree();
}

void SWwisePicker::InitialParse()
{
	OnPopulateClicked();
	TreeViewPtr->RequestTreeRefresh();
	ExpandFirstLevel();
}

FText SWwisePicker::GetProjectName() const
{
	return FText::FromString(ProjectName);
}

FReply SWwisePicker::OnPopulateClicked()
{
	workUnitParser.Parse();
	ConstructTree();
	return FReply::Handled();
}

FReply SWwisePicker::OnGenerateSoundBanksClicked()
{
	AkAudioBankGenerationHelper::CreateGenerateSoundDataWindow();
	return FReply::Handled();
}

void SWwisePicker::ConstructTree()
{
	if (!FAkWaapiClient::IsProjectLoaded())
	{
		RootItems.Empty(EWwiseItemType::LastWwiseDraggable - EWwiseItemType::Event + 1);
		for (int i = EWwiseItemType::Event; i <= EWwiseItemType::LastWwiseDraggable; ++i)
		{
			TSharedPtr<FWwiseTreeItem> NewRoot = builderVisitor->GetTree(SearchBoxFilter, RootItems.Num() > i ? RootItems[i] : nullptr, static_cast<EWwiseItemType::Type>(i));
			RootItems.Add(NewRoot);
		}		
	}
	RestoreTreeExpansion(RootItems);
	TreeViewPtr->RequestTreeRefresh();
}

void SWwisePicker::ExpandFirstLevel()
{
	// Expand root items and first-level work units.
	for(int32 i = 0; i < RootItems.Num(); i++)
	{
		TreeViewPtr->SetItemExpansion(RootItems[i], true);
	}
}

void SWwisePicker::ExpandParents(TSharedPtr<FWwiseTreeItem> Item)
{
	if(Item->Parent.IsValid())
	{
		ExpandParents(Item->Parent.Pin());
		TreeViewPtr->SetItemExpansion(Item->Parent.Pin(), true);
	}
}

TSharedRef<ITableRow> SWwisePicker::GenerateRow( TSharedPtr<FWwiseTreeItem> TreeItem, const TSharedRef<STableViewBase>& OwnerTable )
{
	check(TreeItem.IsValid());

	auto RowVisibility = TreeItem->IsVisible ? EVisibility::Visible : EVisibility::Collapsed;
	TSharedPtr<ITableRow> NewRow = SNew(STableRow< TSharedPtr<FWwiseTreeItem> >, OwnerTable)
		.OnDragDetected(this, &SWwisePicker::OnDragDetected)
		.Visibility(RowVisibility)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 1, 2, 1)
			.VAlign(VAlign_Center)
			[
				SNew(SImage) 
				.Image(FAkAudioStyle::GetBrush(TreeItem->ItemType))
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(FText::FromString(TreeItem->DisplayName))
				.HighlightText(this, &SWwisePicker::GetHighlightText)
			]
		];

	TreeItem->TreeRow = NewRow;

	return NewRow.ToSharedRef();
}

void SWwisePicker::GetChildrenForTree(TSharedPtr< FWwiseTreeItem > TreeItem, TArray< TSharedPtr<FWwiseTreeItem> >& OutChildren)
{
	if (TreeItem)
	{
		OutChildren = TreeItem->GetChildren();
	}
}

FReply SWwisePicker::OnDragDetected(const FGeometry& Geometry, const FPointerEvent& MouseEvent)
{
	return DoDragDetected(MouseEvent, TreeViewPtr->GetSelectedItems());
}

FReply SWwisePicker::DoDragDetected(const FPointerEvent& MouseEvent, const TArray<TSharedPtr<FWwiseTreeItem>>& SelectedItems)
{
	if (!MouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		return FReply::Unhandled();
	}

	if (SelectedItems.Num() == 0)
	{
		return FReply::Unhandled();
	}

	auto AkSettings = GetDefault<UAkSettings>();
	auto AkSettingsPerUser = GetDefault<UAkSettingsPerUser>();
	if (AkSettings && AkSettings->UseEventBasedPackaging && AkSettingsPerUser && AkSettingsPerUser->EnableAutomaticAssetSynchronization)
	{
		TArray<FAssetData> Assets;
		for (auto& Item : SelectedItems)
		{
			if (auto AkAssetPtr = AkAssetDatabase::Get().AudioTypeMap.Find(Item->ItemId))
			{
				Assets.Add(*AkAssetPtr);
			}
		}

		if (Assets.Num() == 0)
		{
			return FReply::Unhandled();
		}

		return FReply::Handled().BeginDragDrop(FWwiseAssetDragDropOp::New(Assets));
	}
	else
	{
		return FReply::Handled().BeginDragDrop(FWwiseEventDragDropOp::New(SelectedItems));
	}
}

void SWwisePicker::PopulateSearchStrings(const FString& FolderName, OUT TArray< FString >& OutSearchStrings) const
{
	OutSearchStrings.Add(FolderName);
}

void SWwisePicker::OnSearchBoxChanged(const FText& InSearchText)
{
	SearchBoxFilter->SetRawFilterText(InSearchText);
}

FText SWwisePicker::GetHighlightText() const
{
	return SearchBoxFilter->GetRawFilterText();
}

void SWwisePicker::FilterUpdated()
{
	FScopedSlowTask SlowTask(2.f, LOCTEXT("AK_PopulatingPicker", "Populating Wwise Picker..."));
	SlowTask.MakeDialog();
	for (int32 i = 0; i < RootItems.Num(); i++)
	{
		RootItems[i] = builderVisitor->GetTree(SearchBoxFilter, RootItems[i], static_cast<EWwiseItemType::Type>(i));

		AllowTreeViewDelegates = false;
		RestoreTreeExpansion(RootItems);
		AllowTreeViewDelegates = true;
	}
	TreeViewPtr->RequestTreeRefresh();
}

void SWwisePicker::SetItemVisibility(TSharedPtr<FWwiseTreeItem> Item, bool IsVisible)
{
	if (Item.IsValid())
	{
		if (IsVisible)
		{
			// Propagate visibility to parents.
			SetItemVisibility(Item->Parent.Pin(), IsVisible);
		}
		Item->IsVisible = IsVisible;
		if (Item->TreeRow.IsValid())
		{
			TSharedRef<SWidget> wid = Item->TreeRow.Pin()->AsWidget();
			wid->SetVisibility(IsVisible ? EVisibility::Visible : EVisibility::Collapsed);
		}
	}
}

void SWwisePicker::RestoreTreeExpansion(const TArray< TSharedPtr<FWwiseTreeItem> >& Items)
{
	for(int i = 0; i < Items.Num(); i++)
	{
		if (!Items[i])
		{
			continue;
		}

		if( LastExpandedPaths.Contains(Items[i]->FolderPath) )
		{
			TreeViewPtr->SetItemExpansion(Items[i], true);
		}
		RestoreTreeExpansion(Items[i]->GetChildren());
	}
}

void SWwisePicker::TreeSelectionChanged( TSharedPtr< FWwiseTreeItem > TreeItem, ESelectInfo::Type /*SelectInfo*/ )
{
	if (AllowTreeViewDelegates)
	{
		const TArray<TSharedPtr<FWwiseTreeItem>> SelectedItems = TreeViewPtr->GetSelectedItems();

		LastSelectedPaths.Empty();
		for (int32 ItemIdx = 0; ItemIdx < SelectedItems.Num(); ++ItemIdx)
		{
			const TSharedPtr<FWwiseTreeItem> Item = SelectedItems[ItemIdx];
			if (Item.IsValid())
			{
				LastSelectedPaths.Add(Item->FolderPath);
			}
		}
	}
}

void SWwisePicker::TreeExpansionChanged( TSharedPtr< FWwiseTreeItem > TreeItem, bool bIsExpanded )
{
	if (AllowTreeViewDelegates)
	{
		TSet<TSharedPtr<FWwiseTreeItem>> ExpandedItemSet;
		TreeViewPtr->GetExpandedItems(ExpandedItemSet);

		LastExpandedPaths.Empty();
		for (auto ExpandedItemIt = ExpandedItemSet.CreateConstIterator(); ExpandedItemIt; ++ExpandedItemIt)
		{
			const TSharedPtr<FWwiseTreeItem> Item = *ExpandedItemIt;
			if (Item.IsValid())
			{
				// Keep track of the last paths that we broadcasted for expansion reasons when filtering
				LastExpandedPaths.Add(Item->FolderPath);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
