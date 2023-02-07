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
	AkJsonFactory.cpp:
=============================================================================*/
#include "Factories/AkJsonFactory.h"

#include "AkAudioEvent.h"
#include "AkSettings.h"
#include "Misc/Paths.h"

/*------------------------------------------------------------------------------
	UAkJsonFactory.
------------------------------------------------------------------------------*/
UAkJsonFactory::UAkJsonFactory(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UAkAudioEvent::StaticClass();
	Formats.Add(TEXT("json;Audiokinetic SoundBank Metadata"));
	bCreateNew = true;
	bEditorImport = true;
	ImportPriority = 101;
}

UObject* UAkJsonFactory::FactoryCreateNew( UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn )
{
	return nullptr;
}

bool UAkJsonFactory::FactoryCanImport(const FString& Filename)
{
	//check extension
	if (FPaths::GetExtension(Filename) == TEXT("json"))
	{
		const UAkSettings* AkSettings = GetDefault<UAkSettings>();

		if (Filename.Contains(AkSettings ? AkSettings->WwiseSoundDataFolder.Path : UAkSettings::DefaultSoundDataFolder))
		{
			return true;
		}
	}

	return false;
}

bool UAkJsonFactory::ShouldShowInNewMenu() const
{
	return false;
}
