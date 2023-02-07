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

#pragma once

#include "AkAudioDevice.h"
#include "Modules/ModuleManager.h"
#include "Containers/Ticker.h"

/**
 * The public interface to this module.  In most cases, this interface is only public to sibling modules 
 * within this plugin.
 */
class IAkAudioModule : public IModuleInterface
{

public:
	/**
	 * Singleton-like access to this module's interface.  This is just for convenience!
	 * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline IAkAudioModule& Get()
	{
		return FModuleManager::LoadModuleChecked< IAkAudioModule >(TEXT("AkAudio"));
	}

	/**
	 * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded(TEXT("AkAudio"));
	}
};

class FAkAudioModule : public IAkAudioModule
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	FAkAudioDevice * GetAkAudioDevice();

	static FAkAudioModule* AkAudioModuleInstance;

private:
	FAkAudioDevice * AkAudioDevice;

	/** Call to update AkAudioDevice. */
	FTickerDelegate OnTick;

	/** Handle for OnTick. */
	FTickerDelegateHandle TickDelegateHandle;
};
