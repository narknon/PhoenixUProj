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

#include "CookAkSoundDataTask.h"

#include "Settings/EditorLoadingSavingSettings.h"
#include "ToolBehavior/AkToolBehavior.h"
#include "Async/Async.h"

CookAkSoundDataTask::CookAkSoundDataTask(const AkSoundDataBuilder::InitParameters& InitParameters)
{
	_dataSource = AkToolBehavior::Get()->CookAkSoundDataTask_CreateBuilder(InitParameters);
	_dataSource->Init();
}

CookAkSoundDataTask::~CookAkSoundDataTask()
{
}

void CookAkSoundDataTask::ExecuteForEditorPlatform()
{
	AkSoundDataBuilder::InitParameters initParameters;
	initParameters.Platforms = { FPlatformProperties::IniPlatformName() };

	ExecuteTask(initParameters);
}

void CookAkSoundDataTask::ExecuteTask(const AkSoundDataBuilder::InitParameters& InitParameters)
{

	AsyncTask(ENamedThreads::Type::AnyBackgroundThreadNormalTask, [InitParameters]
	{
		auto task = new FAsyncTask<CookAkSoundDataTask>(InitParameters);
		task->StartSynchronousTask();
		task->EnsureCompletion();
		AsyncTask(ENamedThreads::GameThread, [task]
		{
			delete task;
		});

	});
}

void CookAkSoundDataTask::DoWork()
{
	//Disable autosave during sound data generation
	UEditorLoadingSavingSettings* LoadingSavingSettings = GetMutableDefault<UEditorLoadingSavingSettings>();
	const bool bOldAutoSaveState = LoadingSavingSettings->bAutoSaveEnable;
	LoadingSavingSettings->bAutoSaveEnable = false;
	_dataSource->DoWork();
	LoadingSavingSettings->bAutoSaveEnable = bOldAutoSaveState;
}
