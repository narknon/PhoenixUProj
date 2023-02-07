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

#include "AkIntegrationBehavior.h"

#include "AkUnrealHelper.h"
#include "AkEventBasedIntegrationBehavior.h"
#include "AkLegacyIntegrationBehavior.h"
#include "AkSettings.h"

AkIntegrationBehavior* AkIntegrationBehavior::s_Instance = nullptr;

AkIntegrationBehavior* AkIntegrationBehavior::Get()
{
	if (!s_Instance)
	{
		if (AkUnrealHelper::IsUsingEventBased())
		{
			s_Instance = new AkEventBasedIntegrationBehavior;
		}
		else
		{
			s_Instance = new AkLegacyIntegrationBehavior;
		}
	}

	return s_Instance;
}
