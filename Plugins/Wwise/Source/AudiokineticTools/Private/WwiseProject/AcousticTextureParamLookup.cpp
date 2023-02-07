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

#include "AcousticTextureParamLookup.h"
#include "XmlNode.h"
#include "AkSettings.h"
#include "AkAcousticTexture.h"
#include "AssetManagement/AkAssetDatabase.h"

void AcousticTextureVisitor::EnterAcousticTexture(const FGuid& Id, const FXmlNode* CurrentNode, const FString& Name, const FString& RelativePath)
{
	const FXmlNode* PropNode = nullptr;
	const FXmlNode* FXmlPropListNode = CurrentNode->FindChildNode("PropertyList");
	if (FXmlPropListNode != nullptr)
		PropNode = FXmlPropListNode->FindChildNode("Property");
	float absorptionLow = 0.0f;
	float absorptionMidLow = 0.0f;
	float absorptionMidHigh = 0.0f;
	float absorptionHigh = 0.0f;
	int colorIndex = -1;
	bool overrideColor = false;
	UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
	while (PropNode != nullptr && PropNode->GetTag() == TEXT("Property"))
	{
		FString CurrentName = PropNode->GetAttribute(TEXT("Name"));
		if (CurrentName == TEXT("AbsorptionLow"))
		{
			absorptionLow = FCString::Atof(*PropNode->GetAttribute(TEXT("Value")));
		}
		else if (CurrentName == TEXT("AbsorptionMidLow"))
		{
			absorptionMidLow = FCString::Atof(*PropNode->GetAttribute(TEXT("Value")));
		}
		else if (CurrentName == TEXT("AbsorptionMidHigh"))
		{
			absorptionMidHigh = FCString::Atof(*PropNode->GetAttribute(TEXT("Value")));
		}
		else if (CurrentName == TEXT("AbsorptionHigh"))
		{
			absorptionHigh = FCString::Atof(*PropNode->GetAttribute(TEXT("Value")));
		}
		else if (CurrentName == TEXT("Color"))
		{
			colorIndex = FCString::Atoi(*PropNode->GetAttribute(TEXT("Value")));
		}
		else if (CurrentName == TEXT("OverrideColor"))
		{
			overrideColor = PropNode->GetAttribute(TEXT("Value")).Equals(TEXT("True"));
		}
		PropNode = PropNode->GetNextNode();
	}
	
	// If OverrideColor is disabled, revert to the default color.
	if (!overrideColor)
		colorIndex = -1;
	
	if (AkSettings != nullptr)
	{
		AkSettings->SetTextureColor(Id, colorIndex);

		auto& akAssetDatabase = AkAssetDatabase::Get();
		uint32 textureShortID = 0;
		if (auto texture = akAssetDatabase.AcousticTextureMap.FindLiveAsset(Id))
		{
			textureShortID = texture->ShortID;
		}

		AkSettings->SetAcousticTextureParams(Id, { FVector4(FVector(absorptionLow, absorptionMidLow, absorptionMidHigh), absorptionHigh) / 100.0f, textureShortID });
	}
}

AkAcousticTextureParamLookup::AkAcousticTextureParamLookup()
{
	Parser.SetVisitor(&Visitor);
}

void AkAcousticTextureParamLookup::UpdateParamsMap()
{
	UAkSettings* AkSettings = GetMutableDefault<UAkSettings>();
	if (AkSettings != nullptr)
	{
		AkSettings->ClearTextureParamsMap();
		Parser.Parse();
	}
}
