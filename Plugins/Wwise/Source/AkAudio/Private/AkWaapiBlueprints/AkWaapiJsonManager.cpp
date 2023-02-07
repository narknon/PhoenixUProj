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



/*=============================================================================
	AkAudioClasses.cpp:
=============================================================================*/

#include "AkWaapiBlueprints/AkWaapiJsonManager.h"
#include "AkAudioDevice.h"
#include "EngineUtils.h"
#include "Model.h"
#include "UObject/UObjectIterator.h"
#include "Engine/GameEngine.h"
#include "AkWaapiClient.h"


/*-----------------------------------------------------------------------------
	AkWaapiJsonManager.
-----------------------------------------------------------------------------*/

UAkWaapiJsonManager::UAkWaapiJsonManager(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Property initialization
}

FAKWaapiJsonObject UAkWaapiJsonManager::SetStringField(const FAkWaapiFieldNames& FieldName, const FString& FieldValue, FAKWaapiJsonObject  target)
{
	if (!FieldName.FieldName.IsEmpty() && !FieldValue.IsEmpty() && target.WaapiJsonObj.IsValid())
	{
		target.WaapiJsonObj->SetStringField(FieldName.FieldName, FieldValue);
	}
	return target;
}

FAKWaapiJsonObject UAkWaapiJsonManager::SetBoolField(const FAkWaapiFieldNames& FieldName, bool FieldValue, FAKWaapiJsonObject target)
{
	if (!FieldName.FieldName.IsEmpty() && target.WaapiJsonObj.IsValid())
	{
		target.WaapiJsonObj->SetBoolField(FieldName.FieldName, FieldValue);
	}
	return target;
}

FAKWaapiJsonObject UAkWaapiJsonManager::SetNumberField(const FAkWaapiFieldNames& FieldName, float FieldValue, FAKWaapiJsonObject target)
{
	if (!FieldName.FieldName.IsEmpty() && target.WaapiJsonObj.IsValid())
	{
		target.WaapiJsonObj->SetNumberField(FieldName.FieldName, FieldValue);
	}
	return target;
}

FAKWaapiJsonObject UAkWaapiJsonManager::SetObjectField(const FAkWaapiFieldNames& FieldName, FAKWaapiJsonObject FieldValue, FAKWaapiJsonObject target)
{
	if (!FieldName.FieldName.IsEmpty() && FieldValue.WaapiJsonObj.IsValid() && target.WaapiJsonObj.IsValid())
	{
		target.WaapiJsonObj->SetObjectField(FieldName.FieldName, FieldValue.WaapiJsonObj);
	}
	return target;
}

FAKWaapiJsonObject UAkWaapiJsonManager::SetArrayStringFields(const FAkWaapiFieldNames& FieldName, const TArray< FString >& FieldStringValues, FAKWaapiJsonObject target)
{
	if (!FieldName.FieldName.IsEmpty() && FieldStringValues.Num() && target.WaapiJsonObj.IsValid())
	{
		TArray<TSharedPtr<FJsonValue>> JsonArray;
		for (FString Field : FieldStringValues)
		{
			JsonArray.Add(MakeShareable(new FJsonValueString(Field)));
		}
		target.WaapiJsonObj->SetArrayField(FieldName.FieldName, JsonArray);
	}
	return target;
}

FAKWaapiJsonObject UAkWaapiJsonManager::SetArrayObjectFields(const FAkWaapiFieldNames& FieldName, const TArray< FAKWaapiJsonObject >& FieldObjectValues, FAKWaapiJsonObject target)
{
	if (!FieldName.FieldName.IsEmpty() && FieldObjectValues.Num() && target.WaapiJsonObj.IsValid())
	{
		TArray<TSharedPtr<FJsonValue>> JsonArray;
		for (FAKWaapiJsonObject Field : FieldObjectValues)
		{
			if (Field.WaapiJsonObj.IsValid())
			{
				JsonArray.Add(MakeShareable(new FJsonValueObject(Field.WaapiJsonObj)));
			}
		}
		target.WaapiJsonObj->SetArrayField(FieldName.FieldName, JsonArray);
	}
	return target;
}

FString UAkWaapiJsonManager::GetStringField(const FAkWaapiFieldNames& FieldName, FAKWaapiJsonObject target)
{
	FString result;
	if (!FieldName.FieldName.IsEmpty() && target.WaapiJsonObj.IsValid())
	{
		target.WaapiJsonObj->TryGetStringField(FieldName.FieldName, result);
	}
	return result;
}

bool UAkWaapiJsonManager::GetBoolField(const FAkWaapiFieldNames& FieldName, FAKWaapiJsonObject target)
{
	bool result = true;
	if (!FieldName.FieldName.IsEmpty() && target.WaapiJsonObj.IsValid())
	{
		target.WaapiJsonObj->TryGetBoolField(FieldName.FieldName, result);
	}
	return result;
}

float UAkWaapiJsonManager::GetNumberField(const FAkWaapiFieldNames& FieldName, FAKWaapiJsonObject target)
{
	double result = TNumericLimits<float>::Min();
	if (!FieldName.FieldName.IsEmpty() && target.WaapiJsonObj.IsValid())
	{
		target.WaapiJsonObj->TryGetNumberField(FieldName.FieldName, result);
	}
	return result;
}

int32 UAkWaapiJsonManager::GetIntegerField(const FAkWaapiFieldNames& FieldName, FAKWaapiJsonObject target)
{
	int32 result = INT32_MIN;
	if (!FieldName.FieldName.IsEmpty() && target.WaapiJsonObj.IsValid())
	{
		target.WaapiJsonObj->TryGetNumberField(FieldName.FieldName, result);
	}
	return result;
}

FAKWaapiJsonObject UAkWaapiJsonManager::GetObjectField(const FAkWaapiFieldNames& FieldName, FAKWaapiJsonObject target)
{
	FAKWaapiJsonObject outResult = FAKWaapiJsonObject();
	const TSharedPtr<FJsonObject> *outJsonResult = nullptr;
	if (!FieldName.FieldName.IsEmpty() && target.WaapiJsonObj.IsValid())
	{
		outResult.WaapiJsonObj = target.WaapiJsonObj->GetObjectField(FieldName.FieldName);
	}
	return outResult;
}

const TArray<FAKWaapiJsonObject > UAkWaapiJsonManager::GetArrayField(const FAkWaapiFieldNames& FieldName, FAKWaapiJsonObject target)
{
	TArray<FAKWaapiJsonObject> WaapiJsonArrayResult;
	if (!FieldName.FieldName.IsEmpty() && target.WaapiJsonObj.IsValid())
	{
		TArray<TSharedPtr<FJsonValue>> JsonArray = target.WaapiJsonObj->GetArrayField(FieldName.FieldName);
		for (TSharedPtr<FJsonValue> JObj : JsonArray)
		{
			FAKWaapiJsonObject WaapiJsonObj = FAKWaapiJsonObject();
			WaapiJsonObj.WaapiJsonObj = JObj->AsObject();
			WaapiJsonArrayResult.Add(WaapiJsonObj);
		}
	}
	return WaapiJsonArrayResult;
}

FString UAkWaapiJsonManager::Conv_FAKWaapiJsonObjectToString(FAKWaapiJsonObject INAKWaapiJsonObject)
{
	FString ResultAsString;
	FAkWaapiClient::JsonObjectToString(INAKWaapiJsonObject.WaapiJsonObj.ToSharedRef(), ResultAsString);
	return ResultAsString;
}

FText UAkWaapiJsonManager::Conv_FAKWaapiJsonObjectToText(FAKWaapiJsonObject INAKWaapiJsonObject)
{
	return FText::FromString(*Conv_FAKWaapiJsonObjectToString(INAKWaapiJsonObject));
}
