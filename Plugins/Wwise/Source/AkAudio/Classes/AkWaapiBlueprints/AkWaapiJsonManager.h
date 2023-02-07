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
	UAkWaapiCalls.h
=============================================================================*/
#pragma once

#include "AkInclude.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AkWaapiUri.h"
#include "Dom/JsonObject.h"
#include "AkWaapiUtils.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonSerializer.h"
#include "AkWaapiBlueprints/AkWaapiFieldNames.h"
#include "AkWaapiJsonManager.generated.h"

USTRUCT(BlueprintType)
struct AKAUDIO_API FAKWaapiJsonObject
{
	GENERATED_USTRUCT_BODY()
	FAKWaapiJsonObject()
	{
		WaapiJsonObj = MakeShareable(new FJsonObject());	
	}
	TSharedPtr<FJsonObject> WaapiJsonObj;
};

UCLASS()
class AKAUDIO_API UAkWaapiJsonManager : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
	/** Add a String field named FieldName with value of FieldValue */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiJsonManager")
	static FAKWaapiJsonObject SetStringField(const FAkWaapiFieldNames& FieldName, const FString& FieldValue, FAKWaapiJsonObject target);

	/** Set a boolean field named FieldName and value of FieldValue */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiJsonManager")
	static FAKWaapiJsonObject SetBoolField(const FAkWaapiFieldNames& FieldName, bool FieldValue, FAKWaapiJsonObject target);

	/** Add a field named FieldName with Number as FieldValue */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiJsonManager")
	static FAKWaapiJsonObject SetNumberField(const FAkWaapiFieldNames& FieldName, float FieldValue, FAKWaapiJsonObject target);

	/** Set an ObjectField named FieldName and value of FieldValue */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiJsonManager")
	static FAKWaapiJsonObject SetObjectField(const FAkWaapiFieldNames& FieldName, FAKWaapiJsonObject FieldValue, FAKWaapiJsonObject target);

	/** Add an array of String field named FieldName with value of FieldStringValues */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiJsonManager")
	static FAKWaapiJsonObject SetArrayStringFields(const FAkWaapiFieldNames& FieldName, const TArray< FString >& FieldStringValues, FAKWaapiJsonObject target);

	/** Set an array of ObjectField named FieldName and value of FieldObjectValues */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiJsonManager")
	static FAKWaapiJsonObject SetArrayObjectFields(const FAkWaapiFieldNames& FieldName, const TArray< FAKWaapiJsonObject >& FieldObjectValues, FAKWaapiJsonObject target);

	/** Get the field named FieldName as a string. */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiJsonManager")
	static FString GetStringField(const FAkWaapiFieldNames& FieldName, FAKWaapiJsonObject target);

	/** Gets the field with the specified name as a boolean. */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiJsonManager")
	static bool GetBoolField(const FAkWaapiFieldNames& FieldName, FAKWaapiJsonObject target);

	/** Gets the field with the specified name as a number. */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiJsonManager")
	static float GetNumberField(const FAkWaapiFieldNames& FieldName, FAKWaapiJsonObject target);

	/** Gets a numeric field and casts to an int32 */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiJsonManager")
	static int32 GetIntegerField(const FAkWaapiFieldNames& FieldName, FAKWaapiJsonObject target);

	/** Gets the field with the specified name as a Json object. */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiJsonManager")
	static	FAKWaapiJsonObject GetObjectField(const FAkWaapiFieldNames& FieldName, FAKWaapiJsonObject target);

	/** Get the field named FieldName as an array. */
	UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiJsonManager")
	static	const TArray<FAKWaapiJsonObject > GetArrayField(const FAkWaapiFieldNames& FieldName, FAKWaapiJsonObject target);

	/** Converts an AKWaapiJsonObject value to a string */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString (FAKWaapiJsonObject)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_FAKWaapiJsonObjectToString(FAKWaapiJsonObject INAKWaapiJsonObject);

	/** Converts an AKWaapiJsonObject value to a localizable text */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToText (FAKWaapiJsonObject)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|Text")
	static FText Conv_FAKWaapiJsonObjectToText(FAKWaapiJsonObject INAKWaapiJsonObject);
};