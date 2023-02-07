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

using UnrealBuildTool;
using System;
using System.IO;
using System.Collections.Generic;

public class AkUEPlatform_Mac : AkUEPlatform
{
	private string akLibPath = string.Empty;

	public AkUEPlatform_Mac(ReadOnlyTargetRules in_TargetRules, string in_ThirdPartyFolder) : base(in_TargetRules, in_ThirdPartyFolder)
	{
		akLibPath = Path.Combine(ThirdPartyFolder, AkPlatformLibDir, AkConfigurationDir, "lib");
	}

#if !UE_4_24_OR_LATER
	public override string SanitizeLibName(string in_libName)
	{
		return Path.Combine(akLibPath, "lib" + in_libName + ".a");
	}
#endif

	public override string GetLibraryFullPath(string LibName, string LibPath)
	{
		return Path.Combine(LibPath, "lib" + LibName + ".a");
	}

	public override bool SupportsAkAutobahn { get { return Target.Configuration != UnrealTargetConfiguration.Shipping; } }

	public override bool SupportsCommunication { get { return true; } }

	public override bool SupportsDeviceMemory { get { return false; } }

	public override string AkPlatformLibDir { get { return "Mac"; } }

	public override string DynamicLibExtension { get { return "dylib"; } }

	public override List<string> GetAdditionalWwiseLibs()
	{
		return new List<string>
		{
			"AkAACDecoder"
		};
	}
	
	public override List<string> GetPublicSystemLibraries()
	{
		return new List<string>();
	}

	public override List<string> GetPublicDelayLoadDLLs()
	{
		return new List<string>();
	}

	public override List<string> GetPublicDefinitions()
	{
		return new List<string>();
	}

	public override Tuple<string, string> GetAdditionalPropertyForReceipt(string ModuleDirectory)
	{
		return null;
	}

	public override List<string> GetPublicFrameworks()
	{
		return new List<string>
		{
			"AudioUnit",
			"AudioToolbox",
			"CoreAudio"
		};
	}
}
