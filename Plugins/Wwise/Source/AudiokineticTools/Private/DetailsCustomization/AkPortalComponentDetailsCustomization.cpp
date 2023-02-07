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

#include "AkPortalComponentDetailsCustomization.h"
#include "AkAcousticPortal.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"

#define LOCTEXT_NAMESPACE "AudiokineticTools"


//////////////////////////////////////////////////////////////////////////
// FAkPortalComponentDetailsCustomization

FAkPortalComponentDetailsCustomization::FAkPortalComponentDetailsCustomization()
{
}

TSharedRef<IDetailCustomization> FAkPortalComponentDetailsCustomization::MakeInstance()
{
	return MakeShareable(new FAkPortalComponentDetailsCustomization());
}

void FAkPortalComponentDetailsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized;
	DetailLayout.GetObjectsBeingCustomized(ObjectsBeingCustomized);

	DetailLayout.EditCategory("AkPortalComponent", FText::GetEmpty(), ECategoryPriority::TypeSpecific);
	DetailLayout.EditCategory("Fit To Geometry", FText::GetEmpty(), ECategoryPriority::TypeSpecific);
	
	for (TWeakObjectPtr<UObject>& Object : ObjectsBeingCustomized)
	{
		UAkPortalComponent* PortalBeingCustomized = Cast<UAkPortalComponent>(Object.Get());
		if (PortalBeingCustomized)
		{
			UObject* OuterObj = PortalBeingCustomized->GetOuter();
			UActorComponent* OuterComponent = Cast<UActorComponent>(OuterObj);
			AActor* OuterActor = Cast<AActor>(OuterObj);
			// Do not hide the transform if the component has been created from within a component or actor, as this will hide the transform for that component / actor as well
			// (i.e. - only hide the transform if the component has been added to the hierarchy of a blueprint class or actor instance from the editor)
			if (OuterComponent == nullptr && OuterActor == nullptr)
			{
				IDetailCategoryBuilder& TransformCategory = DetailLayout.EditCategory("TransformCommon", LOCTEXT("TransformCommonCategory", "Transform"), ECategoryPriority::Transform);
				TransformCategory.SetCategoryVisibility(false);
				break;
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE