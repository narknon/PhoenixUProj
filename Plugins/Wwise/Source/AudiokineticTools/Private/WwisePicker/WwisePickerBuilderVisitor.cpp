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

#include "WwisePickerBuilderVisitor.h"

#include "AkUnrealHelper.h"

WwisePickerBuilderVisitor::WwisePickerBuilderVisitor()
{
	projectRootFolder = FPaths::GetPath(AkUnrealHelper::GetWwiseProjectPath()) + TEXT("/");
}

void WwisePickerBuilderVisitor::ForceInit()
{
	treeItems.Empty();
}

void WwisePickerBuilderVisitor::OnBeginPhysicalFolderParse()
{
	TypeTreeRoots.Empty();
	foundPhysicalFolders.Empty();
}

void WwisePickerBuilderVisitor::EnterWorkUnit(const WwiseWorkUnitParser::WorkUnitInfo& wwuInfo, const FString& RelativePath, EWwiseItemType::Type ItemType)
{
	WwuPathToGuid.Add(wwuInfo.wwuPath, wwuInfo.wwuGuid);
	TSharedPtr<FWwiseTreeItem> newWwuItem;
	TSharedPtr<FWwiseTreeItem> parentPointer = nullptr;
	bool isKnown = treeItems.Contains(wwuInfo.wwuGuid);
	if ( TypeTreeRoots.Contains(ItemType) )
	{
		//Get parent physical folder from relativepath
		if (wwuInfo.isStandalone)
		{
			TArray<FString> splitPaths;
			RelativePath.ParseIntoArray(splitPaths, TEXT("/"), true);
			splitPaths.Pop();
			auto parentPath = FString::Join(splitPaths, TEXT("/"));

			if (PhysicalPathToGuid.Contains(parentPath)) 
			{
				auto parentId = PhysicalPathToGuid[parentPath];
				parentPointer = treeItems[parentId];
			}
			else
			{
				parentPointer = TypeTreeRoots[ItemType];
			}
		}
		else
		{
			if (rootTreeItemStack.Num() > 0) 
			{
				parentPointer = rootTreeItemStack.Top().Pin();
			}
			else if (isKnown)
			{
				//If the parent changed, it would be on the stack
				parentPointer = treeItems[wwuInfo.wwuGuid]->Parent.Pin();
			}
		}
	}

	//Update known workUnit
	if (isKnown)
	{
		newWwuItem = treeItems[wwuInfo.wwuGuid];
		if (newWwuItem->Parent.IsValid() && newWwuItem->Parent.Pin()->ItemId != parentPointer->ItemId)
		{
			newWwuItem->Parent.Pin()->RemoveChild(wwuInfo.wwuGuid);
		}
		newWwuItem->EmptyChildren();
	}
	else
	{
		auto workUnitType = wwuInfo.isStandalone? EWwiseItemType::StandaloneWorkUnit : EWwiseItemType::NestedWorkUnit;
		newWwuItem = MakeShared<FWwiseTreeItem>(wwuInfo.wwuName, RelativePath, parentPointer, workUnitType, wwuInfo.wwuGuid);
		treeItems.Add(wwuInfo.wwuGuid, newWwuItem);
	}
	if (parentPointer.IsValid())
	{
		if (isKnown)
		{
			parentPointer->RemoveChild(wwuInfo.wwuGuid);
		}
		parentPointer->AddChild(newWwuItem);
		parentPointer->SortChildren();
	}
	rootTreeItemStack.Push(newWwuItem);
}

void WwisePickerBuilderVisitor::EnterEvent(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createChildTreeItem(Name, RelativePath,  EWwiseItemType::Type::Event, Id);
}

void WwisePickerBuilderVisitor::EnterAcousticTexture(const FGuid& Id, const class FXmlNode* CurrentNode, const FString& Name, const FString& RelativePath)
{
	createChildTreeItem(Name, RelativePath, EWwiseItemType::AcousticTexture, Id);
}

void WwisePickerBuilderVisitor::EnterAuxBus(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createParentTreeItem(Name, RelativePath, EWwiseItemType::AuxBus, Id);
}

void WwisePickerBuilderVisitor::ExitAuxBus()
{
	exitParent();
}

void WwisePickerBuilderVisitor::EnterFolderOrBus(const FGuid& Id, const FString& Name, const FString& RelativePath,  EWwiseItemType::Type ItemType)
{
	if (ItemType == EWwiseItemType::PhysicalFolder) 
	{
		createPhysicalFolderItem(Name, RelativePath, Id);
	}
	else
	{
		createParentTreeItem(Name, RelativePath, ItemType, Id);
	}
}

void WwisePickerBuilderVisitor::ExitFolderOrBus()
{
	exitParent();
}

void WwisePickerBuilderVisitor::EnterStateGroup(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createParentTreeItem(Name, RelativePath, EWwiseItemType::StateGroup, Id);
}

void WwisePickerBuilderVisitor::ExitStateGroup()
{
	exitParent();
}

void WwisePickerBuilderVisitor::EnterState(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createChildTreeItem(Name, RelativePath, EWwiseItemType::State, Id);
}

void WwisePickerBuilderVisitor::EnterSwitchGroup(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createParentTreeItem(Name, RelativePath, EWwiseItemType::SwitchGroup, Id);
}

void WwisePickerBuilderVisitor::ExitSwitchGroup()
{
	exitParent();
}

void WwisePickerBuilderVisitor::EnterSwitch(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createChildTreeItem(Name, RelativePath, EWwiseItemType::Switch, Id);
}

void WwisePickerBuilderVisitor::EnterGameParameter(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createChildTreeItem(Name, RelativePath, EWwiseItemType::GameParameter, Id);
}

void WwisePickerBuilderVisitor::EnterTrigger(const FGuid& Id, const FString& Name, const FString& RelativePath)
{
	createChildTreeItem(Name, RelativePath, EWwiseItemType::Trigger, Id);
}

void WwisePickerBuilderVisitor::ExitChildrenList()
{
	if (rootTreeItemStack.Num() > 0)
	{
		rootTreeItemStack.Top().Pin()->SortChildren();
	}
}

void WwisePickerBuilderVisitor::RemoveWorkUnit(const FString& WorkUnitPath)
{
	if (WwuPathToGuid.Contains(WorkUnitPath))
	{
		auto workUnitGuid = WwuPathToGuid[WorkUnitPath];
		removeTreeItem(workUnitGuid);
		WwuPathToGuid.Remove(WorkUnitPath);
	}
}

void WwisePickerBuilderVisitor::removeTreeItem(FGuid Id)
{
	if (TSharedPtr<FWwiseTreeItem>* itemPtr = treeItems.Find(Id) )
	{
		if (itemPtr->IsValid()) 
		{
			auto treeItem = *itemPtr;
			if (treeItem.IsValid())
			{
				if (treeItem->Parent.IsValid())
				{
					treeItem->Parent.Pin()->RemoveChild(treeItem->ItemId);
				}
				removeTreeItemRecursive(treeItem);
			}
		}
	}
}

void WwisePickerBuilderVisitor::removeTreeItemRecursive(TSharedPtr<FWwiseTreeItem> treeItem)
{
	if (treeItem.IsValid()) 
	{
		for (auto child : treeItem->GetChildren())
		{
			removeTreeItemRecursive(child);
		}
		treeItem->EmptyChildren();
		if (treeItems.Contains(treeItem->ItemId))
		{
			treeItems.Remove(treeItem->ItemId);
		}
	}
}


TSharedPtr<FWwiseTreeItem> WwisePickerBuilderVisitor::GetTree(TSharedPtr<StringFilter> SearchBoxFilter, TSharedPtr<FWwiseTreeItem> CurrentTreeRootItem,  EWwiseItemType::Type ItemType)
{
	if (!TypeTreeRoots.Contains(ItemType)) 
	{
		return nullptr;
	}
	FString CurrentFilterText = SearchBoxFilter->GetRawFilterText().ToString();
	if (!CurrentFilterText.IsEmpty() && CurrentTreeRootItem.IsValid())
	{

		TSharedPtr<FWwiseTreeItem> FilteredTreeRootItem = MakeShared<FWwiseTreeItem>(EWwiseItemType::ItemNames[ItemType], 
		    TypeTreeRoots[ItemType]->FolderPath, nullptr, EWwiseItemType::PhysicalFolder, FGuid(TypeTreeRoots[ItemType]->ItemId));

		if (!OldFilterText.IsEmpty() && CurrentFilterText.StartsWith(OldFilterText))
		{
			CopyTree(CurrentTreeRootItem, FilteredTreeRootItem);
		}
		else
		{
			CopyTree(TypeTreeRoots[ItemType], FilteredTreeRootItem);
		}

		FilterTree(FilteredTreeRootItem, SearchBoxFilter);
		OldFilterText = CurrentFilterText;
		return FilteredTreeRootItem;
	}

	return TypeTreeRoots[ItemType];
}

void WwisePickerBuilderVisitor::CopyTree(TSharedPtr<FWwiseTreeItem> SourceTreeItem, TSharedPtr<FWwiseTreeItem> DestTreeItem)
{
	for (int32 i = 0; i < SourceTreeItem->GetChildren().Num(); i++)
	{
		TSharedPtr<FWwiseTreeItem> CurrItem = SourceTreeItem->GetChildren()[i];
		TSharedPtr<FWwiseTreeItem> NewItem = MakeShared<FWwiseTreeItem>(CurrItem->DisplayName, CurrItem->FolderPath, CurrItem->Parent.Pin(), CurrItem->ItemType, CurrItem->ItemId);
		DestTreeItem->AddChild(NewItem);

		CopyTree(CurrItem, NewItem);
	}
}

void WwisePickerBuilderVisitor::FilterTree(TSharedPtr<FWwiseTreeItem> TreeItem, TSharedPtr<StringFilter> SearchBoxFilter)
{
	TArray<TSharedPtr<FWwiseTreeItem>> ItemsToRemove;
	for (int32 i = 0; i < TreeItem->GetChildren().Num(); i++)
	{
		TSharedPtr<FWwiseTreeItem> CurrItem = TreeItem->GetChildren()[i];
		FilterTree(CurrItem, SearchBoxFilter);

		if (!SearchBoxFilter->PassesFilter(CurrItem->DisplayName) && CurrItem->GetChildren().Num() == 0)
		{
			ItemsToRemove.Add(CurrItem);
		}
	}

	for (int32 i = 0; i < ItemsToRemove.Num(); i++)
	{
		TreeItem->RemoveChild(ItemsToRemove[i]);
	}
}

void WwisePickerBuilderVisitor::createChildTreeItem(const FString& Name, const FString& RelativePath,  EWwiseItemType::Type ItemType, const FGuid& Id)
{
	if (rootTreeItemStack.Num() > 0)
	{
		auto child = MakeShared<FWwiseTreeItem>(Name, RelativePath, rootTreeItemStack.Top().Pin(), ItemType, Id);
		rootTreeItemStack.Top().Pin()->AddChild(child);
		treeItems.Add(Id, child);
	}
}

void WwisePickerBuilderVisitor::createParentTreeItem(const FString& Name, const FString& RelativePath,  EWwiseItemType::Type ItemType, const FGuid& Id)
{
	TSharedPtr<FWwiseTreeItem> folderItem = MakeShared<FWwiseTreeItem>(Name, RelativePath, rootTreeItemStack.Top().Pin(), ItemType, Id);
	treeItems.Add(Id, folderItem);

	if (rootTreeItemStack.Num() > 0)
	{
		rootTreeItemStack.Top().Pin()->AddChild(folderItem);
	}

	rootTreeItemStack.Push(folderItem);
}

void WwisePickerBuilderVisitor::createPhysicalFolderItem(const FString& Name, const FString& RelativePath, const FGuid& Id)
{
	TArray<FString> splitPaths;
	RelativePath.ParseIntoArray(splitPaths, TEXT("/"), true);
	TSharedPtr<FWwiseTreeItem> parent = nullptr;
	auto isRootFolder = splitPaths.Num() < 2;
	auto exists = treeItems.Contains(Id);
	
	//Get parent folder if nested
	if (!isRootFolder)
	{
		splitPaths.Pop();
		auto parentPath = FString::Join(splitPaths, TEXT("/"));
		auto parentId = PhysicalPathToGuid[parentPath];
		parent = treeItems[parentId];
	}

	TSharedPtr<FWwiseTreeItem> folderItem = MakeShared<FWwiseTreeItem>(Name, RelativePath, parent, EWwiseItemType::PhysicalFolder, Id);

	if (exists)
	{
		auto oldItem  = treeItems[Id];
		auto lastParent = oldItem->Parent;
		if (lastParent.IsValid()) 
		{
			lastParent.Pin()->RemoveChild(Id);
		}
		for (auto child : oldItem->GetChildren()) 
		{
			folderItem->AddChild(child);
		}
		treeItems.Remove(Id);
	}

	if (parent.IsValid()) 
	{
		if (exists) 
		{
			parent->RemoveChild(Id);
		}
		parent->AddChild(folderItem);
		parent->SortChildren();
	}

	PhysicalPathToGuid.Add(RelativePath, Id);
	foundPhysicalFolders.Add(Id);
	treeItems.Add(Id, folderItem);

	if (isRootFolder)
	{
		auto folderType = EWwiseItemType::FromFolderName(RelativePath);
		//Set root folder name to predetermined display name
		if (folderItem->DisplayName != EWwiseItemType::ItemNames[folderType])
		{
			folderItem->DisplayName = EWwiseItemType::ItemNames[folderType];
		}
		TypeTreeRoots.Add(folderType, folderItem);
	}
}

void WwisePickerBuilderVisitor::ExitWorkUnit(bool IsStandaloneWorkUnit) 
{
	exitParent();
}

void WwisePickerBuilderVisitor::exitParent()
{
	if (rootTreeItemStack.Num() > 0)
	{
		rootTreeItemStack.Pop();
	}
}

FString WwisePickerBuilderVisitor::FindRelativePath(const FString& WorkUnitPath,const FGuid& Id, EWwiseItemType::Type ItemType)
{
	if (TypeTreeRoots.Contains(ItemType) && treeItems.Contains(Id)){
		auto wwuItem = treeItems[Id];
		return wwuItem->FolderPath;
	}
	return {};
};

TSet<FGuid> WwisePickerBuilderVisitor::getKnownPhysicalFolders()
{
	TSet<FGuid> knownFolders;
	for (auto const& item : treeItems) 
	{
		if ( item.Value.IsValid() && item.Value.Get()->ItemType == EWwiseItemType::PhysicalFolder )
		{
			knownFolders.Add(item.Key);
		}
	}
	return knownFolders;
}

void WwisePickerBuilderVisitor::EndPhysicalFolderParse() 
{
	auto knownFolders = getKnownPhysicalFolders();
	for (auto folder : knownFolders)
	{
		if (!foundPhysicalFolders.Contains(folder))
		{
			removeTreeItem(folder);
		}
	}
}
