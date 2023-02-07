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

#include "AkLateReverbComponentDetailsCustomization.h"
#include "AkComponent.h"
#include "AkLateReverbComponent.h"

#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "ScopedTransaction.h"
#include "IPropertyUtilities.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "AudiokineticTools"


//////////////////////////////////////////////////////////////////////////
// FAkLateReverbComponentDetailsCustomization

FAkLateReverbComponentDetailsCustomization::FAkLateReverbComponentDetailsCustomization()
{
}

TSharedRef<IDetailCustomization> FAkLateReverbComponentDetailsCustomization::MakeInstance()
{
	return MakeShareable(new FAkLateReverbComponentDetailsCustomization());
}

void FAkLateReverbComponentDetailsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	DetailLayout.EditCategory("Toggle", FText::GetEmpty(), ECategoryPriority::Important);
	DetailLayout.EditCategory("Late Reverb", FText::GetEmpty(), ECategoryPriority::TypeSpecific);
	MyDetailLayout = &DetailLayout;
	TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized;
	DetailLayout.GetObjectsBeingCustomized(ObjectsBeingCustomized);
	DetailLayout.HideProperty("AuxBusManual");
	for (TWeakObjectPtr<UObject>& Object : ObjectsBeingCustomized)
	{
		UAkLateReverbComponent* LateReverbBeingCustomized = Cast<UAkLateReverbComponent>(Object.Get());
		if (LateReverbBeingCustomized)
		{
			UObject* OuterObj = LateReverbBeingCustomized->GetOuter();
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

	if (ObjectsBeingCustomized.Num() != 1)
	{
		return;
	}

	UAkLateReverbComponent* LateReverbBeingCustomized = Cast<UAkLateReverbComponent>(ObjectsBeingCustomized[0].Get());
	if (LateReverbBeingCustomized)
	{
		IDetailCategoryBuilder& ToggleDetailCategory = DetailLayout.EditCategory("Toggle");
		auto EnableHandle = DetailLayout.GetProperty("bEnable");
		EnableHandle->SetOnPropertyValueChanged(FSimpleDelegate::CreateSP(this, &FAkLateReverbComponentDetailsCustomization::OnEnableValueChanged));

		if (!LateReverbBeingCustomized->bEnable)
		{
			DetailLayout.HideCategory("Late Reverb");
		}
	}
}

void FAkLateReverbComponentDetailsCustomization::OnEnableValueChanged()
{
	MyDetailLayout->ForceRefreshDetails();
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE