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

public class AkUEPlatform_XboxOne : AkUEPlatform
{
	public AkUEPlatform_XboxOne(ReadOnlyTargetRules in_TargetRules, string in_ThirdPartyFolder) : base(in_TargetRules, in_ThirdPartyFolder) {}

#if !UE_4_24_OR_LATER
	public override string SanitizeLibName(string in_libName)
	{
		return in_libName + ".lib";
	}
#endif

	public override string GetLibraryFullPath(string LibName, string LibPath)
	{
		return Path.Combine(LibPath, LibName + ".lib");
	}

	public override bool SupportsAkAutobahn { get { return false; } }

	public override bool SupportsCommunication { get { return true; } }

	public override bool SupportsDeviceMemory { get { return true; } }

	public override string AkPlatformLibDir { get { return "XboxOne_" + GetVisualStudioVersion(); } }

	public override string DynamicLibExtension { get { return "dll"; } }

	public override List<string> GetAdditionalWwiseLibs()
	{
		return new List<string>();
	}
	
	public override List<string> GetPublicSystemLibraries()
	{
		return new List<string>
		{
			"AcpHal.lib",
			"MMDevApi.lib"
		};
	}

	public override List<string> GetPublicDelayLoadDLLs()
	{
		return new List<string>();
	}

	public override List<string> GetPublicDefinitions()
	{
		var Defines = new List<string>
		{
			"_XBOX_ONE",
			"AK_XBOXONE_INIT_COMMS_MANIFEST=1",
			"AK_XBOXONE_VS_VERSION=\"" + GetVisualStudioVersion() + "\"",
			"AK_XBOXONE_NEED_APU_ALLOC",
			"AK_XBOXONE_COMMON"
		};
        
#if UE_4_25_OR_LATER
        Defines.Add("AK_NEED_XBOX_MINAPI=0");
#else
        Defines.Add("AK_NEED_XBOX_MINAPI=1");
#endif

		return Defines;
	}

	public override Tuple<string, string> GetAdditionalPropertyForReceipt(string ModuleDirectory)
	{
		return null;
	}

	public override List<string> GetPublicFrameworks()
	{
		return new List<string>();
	}

	private string GetVisualStudioVersion()
	{
		// Use reflection because the GitHub version of UE is missing things.
		var XboxOnePlatformType = System.Type.GetType("UnrealBuildTool.XboxOnePlatform,UnrealBuildTool", false);
		if (XboxOnePlatformType != null)
		{
			var XboxOneCompilerField = XboxOnePlatformType.GetProperty("Compiler");
			if (XboxOneCompilerField != null)
			{
				var XboxOneCompilerValue = XboxOneCompilerField.GetValue(null);
				switch (XboxOneCompilerValue.ToString())
				{
					case "VisualStudio2012":
						return "vc110";
					case "VisualStudio2017":
						return "vc150";
					case "VisualStudio2015":
					default:
						return "vc140";
				}
			}
		}

		return "vc140";
	}
}
