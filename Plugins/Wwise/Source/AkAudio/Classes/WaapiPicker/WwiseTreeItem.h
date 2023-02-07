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
	WwiseTreeItem.h
------------------------------------------------------------------------------------*/
#pragma once
#include "Engine/GameEngine.h"
#include "Widgets/Views/STableRow.h"
#include "WwiseItemType.h"

/*------------------------------------------------------------------------------------
	WwiseTreeItem
------------------------------------------------------------------------------------*/
struct FWwiseTreeItem : public TSharedFromThis<FWwiseTreeItem>
{
private:
	TArray< TSharedPtr<FWwiseTreeItem> > m_Children;

public:
	/** Name to display */
	FString DisplayName;
	/** The path of the tree item including the name */
	FString FolderPath;
	/** Type of the item */
	EWwiseItemType::Type ItemType = EWwiseItemType::None;
	/** Id of the item */
	FGuid ItemId;

	/** The children of this tree item */
	const TArray< TSharedPtr<FWwiseTreeItem> > GetChildren() { return m_Children;  }
	TArray< TSharedPtr<FWwiseTreeItem> >* GetChildrenMutable() { return &m_Children;  }

	/** The number of children of this tree item requested from Wwise*/
	uint32_t ChildCountInWwise = 0;

	/** The parent folder for this item */
	TWeakPtr<FWwiseTreeItem> Parent;

	/** The row in the tree view associated to this item */
	TWeakPtr<ITableRow> TreeRow;

	/** Should this item be visible? */
	bool IsVisible = true;

	/** Constructor */
	FWwiseTreeItem(FString InDisplayName, FString InFolderPath, TSharedPtr<FWwiseTreeItem> InParent, EWwiseItemType::Type InItemType, const FGuid& InItemId)
		: DisplayName(MoveTemp(InDisplayName))
		, FolderPath(MoveTemp(InFolderPath))
		, ItemType(MoveTemp(InItemType))
		, ItemId(InItemId)
		, ChildCountInWwise(m_Children.Num())
        , Parent(MoveTemp(InParent))
        , IsVisible(true)
	{}

	void AddChild(TSharedPtr<FWwiseTreeItem> child)
	{
		child->Parent = TWeakPtr<FWwiseTreeItem>(this->AsShared());
		m_Children.Add(child);
	}

	void EmptyChildren()
	{
		m_Children.Empty();
	}

	void RemoveChild(const FGuid & childGuid)
	{
		m_Children.RemoveAll([childGuid](TSharedPtr<FWwiseTreeItem> child) { return child->ItemId == childGuid; });
	}

	void RemoveChild(const TSharedPtr< FWwiseTreeItem> child)
	{
		m_Children.Remove(child);
	}
	
	/** Returns true if this item is a child of the specified item */
	bool IsChildOf(const FWwiseTreeItem& InParent)
	{
		auto CurrentParent = Parent.Pin();
		while (CurrentParent.IsValid())
		{
			if (CurrentParent.Get() == &InParent)
			{
				return true;
			}

			CurrentParent = CurrentParent->Parent.Pin();
		}

		return false;
	}

	bool IsOfType(const TArray<EWwiseItemType::Type>& Types)
	{
		for (const auto& Type : Types)
			if (ItemType == Type)
				return true;

		return false;
	}

	bool IsNotOfType(const TArray<EWwiseItemType::Type>& Types)
	{
		for (const auto& Type : Types)
			if (ItemType == Type)
				return false;

		return true;
	}

	/** Returns the child item by name or NULL if the child does not exist */
	TSharedPtr<FWwiseTreeItem> GetChild (const FString& InChildName)
	{
		for ( int32 ChildIdx = 0; ChildIdx < m_Children.Num(); ++ChildIdx )
		{
			if ( m_Children[ChildIdx]->DisplayName == InChildName )
			{
				return m_Children[ChildIdx];
			}
		}

		return TSharedPtr<FWwiseTreeItem>();
	}

	/** Finds the child who's path matches the one specified */
	TSharedPtr<FWwiseTreeItem> FindItemRecursive (const FString& InFullPath)
	{
		if ( InFullPath == FolderPath )
		{
			return SharedThis(this);
		}

		for ( int32 ChildIdx = 0; ChildIdx < m_Children.Num(); ++ChildIdx )
		{
			const TSharedPtr<FWwiseTreeItem>& Item = m_Children[ChildIdx]->FindItemRecursive(InFullPath);
			if ( Item.IsValid() )
			{
				return Item;
			}
		}

		return TSharedPtr<FWwiseTreeItem>(NULL);
	}

	struct FCompareWwiseTreeItem
	{
		template<typename CT>
		inline int StringCompareLogical(const CT* pA1, const CT* pA2) const
		{
			if (pA1 && pA2)
			{
				while (*pA1)
				{
					if (!*pA2)
					{
						// We've iterated through all the characters of the RHS but
						// there are characters left on the LHS
						return 1;
					}
					else if (TChar<CT>::IsDigit(*pA1))
					{
						// LHS is a digit but RHS is not
						if (!TChar<CT>::IsDigit(*pA2))
							return -1;

						// Both sides are digits, parse the numbers and compare them
						CT* pEnd1 = nullptr;
						CT* pEnd2 = nullptr;
						const auto i1 = TCString<CT>::Strtoi(pA1, &pEnd1, 10);
						const auto i2 = TCString<CT>::Strtoi(pA2, &pEnd2, 10);

						if (i1 < i2)
							return -1;
						else if (i1 > i2)
							return 1;

						pA1 = pEnd1;
						pA2 = pEnd2;
					}
					else if (TChar<CT>::IsDigit(*pA2))
					{
						// LHS is not a digit but RHS is
						return 1;
					}
					else
					{
						// Neither side is a digit, do a case-insensitive comparison
						int diff = TChar<CT>::ToLower(*pA1) - TChar<CT>::ToLower(*pA2);
						if (diff > 0)
							return 1;
						else if (diff < 0)
							return -1;

						++pA1;
						++pA2;
					}
				}

				if (*pA2)
				{
					// We've iterated through all the characters of the LHS but
					// there are characters left on the RHS
					return -1;
				}
			}

			return 0;
		}

		FORCEINLINE bool operator()( TSharedPtr<FWwiseTreeItem> A, TSharedPtr<FWwiseTreeItem> B ) const
		{
			// Items are sorted like so:
			// 1- Physical folders, sorted alphabetically
			// 1- WorkUnits, sorted alphabetically
			// 2- Virtual folders, sorted alphabetically
			// 3- Normal items, sorted alphabetically
			if( A->ItemType == B->ItemType)
			{
				return StringCompareLogical(*A->DisplayName, *B->DisplayName) < 0;
			}
			else if( A->ItemType == EWwiseItemType::PhysicalFolder )
			{
				return true;
			}
			else if( B->ItemType == EWwiseItemType::PhysicalFolder )
			{
				return false;
			}
			else if( A->ItemType == EWwiseItemType::StandaloneWorkUnit || A->ItemType == EWwiseItemType::NestedWorkUnit )
			{
				return true;
			}
			else if( B->ItemType == EWwiseItemType::StandaloneWorkUnit || B->ItemType == EWwiseItemType::NestedWorkUnit )
			{
				return false;
			}
			else if( A->ItemType == EWwiseItemType::Folder )
			{
				return true;
			}
			else if( B->ItemType == EWwiseItemType::Folder )
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	};

	/** Sort the children by name */
	void SortChildren ()
	{
		m_Children.Sort( FCompareWwiseTreeItem() );
	}
};
