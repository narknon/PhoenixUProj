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

public abstract class AkUEPlatform_Windows : AkUEPlatform
{
	bool bIsDebugBuild = false;

	public AkUEPlatform_Windows(ReadOnlyTargetRules in_TargetRules, string in_ThirdPartyFolder) : base(in_TargetRules, in_ThirdPartyFolder) {}

	public abstract string PlatformPrefix { get; }

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

	public override bool SupportsAkAutobahn { get { return Target.Configuration != UnrealTargetConfiguration.Shipping && !bIsDebugBuild ; } }

	public override bool SupportsCommunication { get { return true; } }

	public override bool SupportsDeviceMemory { get { return false; } }

	public override bool SupportsOpus { get { return !bIsDebugBuild; } }

	public override string AkPlatformLibDir { get { return PlatformPrefix + "_" + GetVisualStudioVersion(); } }

	public override string DynamicLibExtension { get { return "dll"; } }

	public override List<string> GetPublicLibraryPaths()
	{
		var confDir = bIsDebugBuild && Target.Configuration == UnrealTargetConfiguration.Debug ? "Debug" : AkConfigurationDir;
		return new List<string> { Path.Combine(ThirdPartyFolder, AkPlatformLibDir, confDir, "lib") };
	}

	public override List<string> GetAdditionalWwiseLibs()
	{
		return new List<string>();
	}
	
	public override List<string> GetPublicSystemLibraries()
	{
		return new List<string> 
		{
			"dsound.lib",
			"dxguid.lib",
			"Msacm32.lib",
			"XInput.lib",
			"dinput8.lib"
		};
	}

	public override List<string> GetPublicDelayLoadDLLs()
	{
		return new List<string>();
	}

	public override List<string> GetPublicDefinitions()
	{
		return new List<string>
		{
			"AK_WINDOWS_VS_VERSION=\"" + GetVisualStudioVersion() + "\""
		};
	}

	public override Tuple<string, string> GetAdditionalPropertyForReceipt(string ModuleDirectory)
	{
		return null;
	}

	public override List<string> GetPublicFrameworks()
	{
		return new List<string>();
	}

	private static void CheckCompilerVersion(ref string Version, WindowsCompiler Compiler, string LongVersionName, string ShortVersionName)
	{
		try
		{
			if (Compiler == (WindowsCompiler)Enum.Parse(typeof(WindowsCompiler), LongVersionName))
				Version = ShortVersionName;
		}
		catch
		{
		}
	}

	private string GetVisualStudioVersion()
	{
		string VSVersion = "vc150";
		var Compiler = Target.WindowsPlatform.Compiler;
		CheckCompilerVersion(ref VSVersion, Compiler, "VisualStudio2019", "vc160");
		CheckCompilerVersion(ref VSVersion, Compiler, "VisualStudio2017", "vc150");
		CheckCompilerVersion(ref VSVersion, Compiler, "VisualStudio2015", "vc140");
		CheckCompilerVersion(ref VSVersion, Compiler, "VisualStudio2013", "vc120");
		return VSVersion;
	}
}

public class AkUEPlatform_Win32 : AkUEPlatform_Windows
{
	public AkUEPlatform_Win32(ReadOnlyTargetRules in_TargetRules, string in_ThirdPartyFolder) : base(in_TargetRules, in_ThirdPartyFolder) {}
	public override string PlatformPrefix { get { return "Win32"; } }
}

public class AkUEPlatform_Win64 : AkUEPlatform_Windows
{
	public AkUEPlatform_Win64(ReadOnlyTargetRules in_TargetRules, string in_ThirdPartyFolder) : base(in_TargetRules, in_ThirdPartyFolder) {}
	public override string PlatformPrefix { get { return "x64"; } }
}
