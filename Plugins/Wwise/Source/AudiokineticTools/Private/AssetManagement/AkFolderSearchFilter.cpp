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


#include "AkFolderSearchFilter.h"
#include "AkFolder.h"
#if UE_4_26_OR_LATER
#include "ContentBrowserDataFilter.h"
#endif

#define LOCTEXT_NAMESPACE "AkFolderFilter"

//////////////////////////////////////////////////////////////////////////
//

/** A filter that search for assets using a specific gameplay tag */
class FFrontendFilter_AkFolder: public FFrontendFilter
{
public:
	FFrontendFilter_AkFolder(TSharedPtr<FFrontendFilterCategory> InCategory)
		: FFrontendFilter(InCategory) 
	{
		bAreAkFoldersInBaseFilter = false;
		FolderClassName = UAkFolder::StaticClass()->GetFName();
	}

	// FFrontendFilter implementation
	virtual FString GetName() const override { return TEXT("AkFolderFilter"); }
	virtual FText GetDisplayName() const override;
	virtual FText GetToolTipText() const override;
	virtual bool IsInverseFilter() const override { return true; }
#if UE_4_26_OR_LATER
	virtual void SetCurrentFilter(TArrayView<const FName> InSourcePaths, const FContentBrowserDataFilter& InBaseFilter) override;
#else
	virtual void SetCurrentFilter(const FARFilter& InFilter) override;
#endif
	// End of FFrontendFilter implementation

	// IFilter implementation
	virtual bool PassesFilter(FAssetFilterType InItem) const override;

private :
	bool bAreAkFoldersInBaseFilter;
	FName FolderClassName;

};


FText FFrontendFilter_AkFolder::GetDisplayName() const
{
	return LOCTEXT("FrontendFilter_AkFolder", "Show AkFolder Assets");
}

FText FFrontendFilter_AkFolder::GetToolTipText() const
{
	return LOCTEXT("FrontendFilter_AkFolder", "Show assets used to keep track pof the Wwise project folder heirarchy");
}

#if UE_4_26_OR_LATER
void FFrontendFilter_AkFolder::SetCurrentFilter(TArrayView<const FName> InSourcePaths, const FContentBrowserDataFilter& InBaseFilter)
{ 
	const FContentBrowserDataClassFilter* ClassFilter = InBaseFilter.ExtraFilters.FindFilter<FContentBrowserDataClassFilter>();
	bAreAkFoldersInBaseFilter = ClassFilter && ClassFilter->ClassNamesToInclude.Contains(FolderClassName);
}
#else
void FFrontendFilter_AkFolder::SetCurrentFilter(const FARFilter& InFilter)
{
	bAreAkFoldersInBaseFilter = InFilter.ClassNames.Contains(FolderClassName);
}
#endif


#if UE_4_26_OR_LATER
bool FFrontendFilter_AkFolder::PassesFilter(FAssetFilterType InItem) const
{
	FAssetData ItemAssetData;
	if (InItem.Legacy_TryGetAssetData(ItemAssetData))
	{
		if (!bAreAkFoldersInBaseFilter)
		{
			return ItemAssetData.AssetClass != FolderClassName;
		}
	}
	return false;
}

#else
bool FFrontendFilter_AkFolder::PassesFilter(FAssetFilterType InItem) const
{
	// Never hide assets if they are explicitly searched for
	if (!bAreAkFoldersInBaseFilter)
	{
		return InItem.AssetClass != FolderClassName;
	}

	return true;
}
#endif
//////////////////////////////////////////////////////////////////////////
//

void UAkFolderSearchFilter::AddFrontEndFilterExtensions(TSharedPtr<FFrontendFilterCategory> DefaultCategory, TArray< TSharedRef<class FFrontendFilter> >& InOutFilterList) const
{
	InOutFilterList.Add(MakeShareable(new FFrontendFilter_AkFolder(DefaultCategory)));
}

#undef LOCTEXT_NAMESPACE
