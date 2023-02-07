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
using System.Reflection;

// Platform-specific files implement this interface, returning their particular dependencies, defines, etc.
public abstract class AkUEPlatform
{
	protected ReadOnlyTargetRules Target;
	protected string ThirdPartyFolder;

	public AkUEPlatform(ReadOnlyTargetRules in_Target, string in_ThirdPartyFolder)
	{
		Target = in_Target;
		ThirdPartyFolder = in_ThirdPartyFolder;
	}

	public static AkUEPlatform GetAkUEPlatformInstance(ReadOnlyTargetRules Target, string ThirdPartyFolder)
	{
		var AkUEPlatformType = System.Type.GetType("AkUEPlatform_" + Target.Platform.ToString());
		if (AkUEPlatformType == null)
		{
			throw new BuildException("Wwise does not support platform " + Target.Platform.ToString());
		}

		var PlatformInstance = Activator.CreateInstance(AkUEPlatformType, Target, ThirdPartyFolder) as AkUEPlatform;
		if (PlatformInstance == null)
		{
			throw new BuildException("Wwise could not instantiate platform " + Target.Platform.ToString());
		}

		return PlatformInstance;
	}

	protected static List<string> GetAllLibrariesInFolder(string LibFolder, string Extension, bool RemoveLibPrefix = true, bool GetFullPath = false)
	{
		List<string> ret = null;
		var FoundLibs = Directory.GetFiles(LibFolder, "*."+Extension);

		if (GetFullPath)
		{
			ret = new List<string>(FoundLibs);
		}
		else
		{
			ret = new List<string>();
			foreach (var Library in FoundLibs)
			{
				var LibName = Path.GetFileNameWithoutExtension(Library);
				if (RemoveLibPrefix && LibName.StartsWith("lib"))
				{
					LibName = LibName.Remove(0, 3);
				}
				ret.Add(LibName);
			}

		}
		return ret;
	}

	public virtual string AkConfigurationDir
	{
		get
		{
			switch (Target.Configuration)
			{
				case UnrealTargetConfiguration.Debug:
					var akConfiguration = Target.bDebugBuildsActuallyUseDebugCRT ? "Debug" : "Profile";
					return akConfiguration;

				case UnrealTargetConfiguration.Development:
				case UnrealTargetConfiguration.Test:
				case UnrealTargetConfiguration.DebugGame:
					return "Profile";
				default:
					return "Release";
			}
		}
	}
	
	public abstract string GetLibraryFullPath(string LibName, string LibPath);
	public abstract bool SupportsAkAutobahn { get; }
	public abstract bool SupportsCommunication { get; }
	public abstract bool SupportsDeviceMemory { get; }
	public abstract string AkPlatformLibDir { get; }
	public abstract string DynamicLibExtension { get; }
	public virtual bool SupportsOpus { get { return true; } }

	public virtual List<string> GetPublicLibraryPaths()
	{
		return new List<string>
		{
			Path.Combine(ThirdPartyFolder, AkPlatformLibDir, AkConfigurationDir, "lib")
		};
	}

	public virtual List<string> GetRuntimeDependencies()
	{
		return GetAllLibrariesInFolder(Path.Combine(ThirdPartyFolder, AkPlatformLibDir, AkConfigurationDir, "bin"), DynamicLibExtension, false, true);
	}

	public abstract List<string> GetAdditionalWwiseLibs();
	public abstract List<string> GetPublicSystemLibraries();
	public abstract List<string> GetPublicDelayLoadDLLs();
	public abstract List<string> GetPublicDefinitions();
	public abstract Tuple<string, string> GetAdditionalPropertyForReceipt(string ModuleDirectory);
	public abstract List<string> GetPublicFrameworks();
	
#if UE_4_24_OR_LATER
	public virtual List<string> GetSanitizedAkLibList(List<string> AkLibs)
	{
		List<string> SanitizedLibs = new List<string>();
		foreach(var lib in AkLibs)
		{
			foreach(var libPath in GetPublicLibraryPaths())
			{
				SanitizedLibs.Add(GetLibraryFullPath(lib, libPath));
			}
		}
		
		return SanitizedLibs;
	}
#else
	public abstract string SanitizeLibName(string in_libName);
	public virtual List<string> GetSanitizedAkLibList(List<string> AkLibs)
	{
		List<string> SanitizedLibs = new List<string>();
		foreach(var lib in AkLibs)
		{
			SanitizedLibs.Add(SanitizeLibName(lib));
		}
		
		return SanitizedLibs;
	}
#endif

}

public class AkAudio : ModuleRules
{
	private static AkUEPlatform AkUEPlatformInstance;
	private List<string> AkLibs = new List<string> 
	{
		"AkSoundEngine",
		"AkMemoryMgr",
		"AkStreamMgr",
		"AkMusicEngine",
		"AkSpatialAudio",
		"AkAudioInputSource",
		"AkVorbisDecoder",
		"AkMeterFX", // AkMeter does not have a dedicated DLL
	};
	
	public AkAudio(ReadOnlyTargetRules Target) : base(Target)
	{
		string ThirdPartyFolder = Path.Combine(ModuleDirectory, "../../ThirdParty");
		AkUEPlatformInstance = AkUEPlatform.GetAkUEPlatformInstance(Target, ThirdPartyFolder);
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		bAllowConfidentialPlatformDefines = true;

		PrivateIncludePathModuleNames.AddRange(new[] { "Settings", "UMG", "TargetPlatform"});

		PublicDependencyModuleNames.AddRange(new[] { "UMG", "PhysX", "APEX" });

		PrivateDependencyModuleNames.AddRange(new[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"SlateCore",
			"NetworkReplayStreaming",
			"MovieScene",
			"MovieSceneTracks",
			"Projects",
			"Json",
			"Slate",
			"InputCore",
			"Projects",
			"AudioMixer",
        });

#if UE_4_26_OR_LATER
		PrivateDependencyModuleNames.Add("Chaos");
		PrivateDependencyModuleNames.Add("PhysicsCore");
#endif

		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"UnrealEd",
					"DesktopPlatform",
					"TargetPlatform",
					"SharedSettingsWidgets",
					"RenderCore",
					"SourceControl",
				});

#if UE_4_25_OR_LATER
			PrivateDependencyModuleNames.Add("GeometryMode");
#endif

			PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"EditorStyle",
#if UE_5_0_OR_LATER
				"DeveloperToolSettings"
#endif
			});

			foreach (var Platform in GetAvailablePlatforms(ModuleDirectory))
			{
				PublicDefinitions.Add("AK_PLATFORM_" + Platform.ToUpper());
			}
		}

		PrivateIncludePaths.Add("AkAudio/Private");
        PrivateIncludePaths.Add("AkAudio/Classes/GTE");
        PublicIncludePaths.Add(Path.Combine(ThirdPartyFolder, "include"));

		PublicDefinitions.Add("AK_UNREAL_MAX_CONCURRENT_IO=32");
		PublicDefinitions.Add("AK_UNREAL_IO_GRANULARITY=32768");
		if (Target.Configuration == UnrealTargetConfiguration.Shipping)
		{
			PublicDefinitions.Add("AK_OPTIMIZED");
		}

		if (Target.Configuration != UnrealTargetConfiguration.Shipping && AkUEPlatformInstance.SupportsCommunication)
		{
			AkLibs.Add("CommunicationCentral");
			PublicDefinitions.Add("AK_ENABLE_COMMUNICATION=1");
		}
		else
		{
			PublicDefinitions.Add("AK_ENABLE_COMMUNICATION=0");
		}

		if (AkUEPlatformInstance.SupportsAkAutobahn)
		{
			AkLibs.Add("AkAutobahn");
			PublicDefinitions.Add("AK_SUPPORT_WAAPI=1");
		}
		else
		{
			PublicDefinitions.Add("AK_SUPPORT_WAAPI=0");
		}

		if (AkUEPlatformInstance.SupportsOpus)
		{
			AkLibs.Add("AkOpusDecoder");
			PublicDefinitions.Add("AK_SUPPORT_OPUS=1");
		}
		else
		{
			PublicDefinitions.Add("AK_SUPPORT_OPUS=0");
		}

		if (AkUEPlatformInstance.SupportsDeviceMemory)
		{
			PublicDefinitions.Add("AK_SUPPORT_DEVICE_MEMORY=1");
		}
		else
		{
			PublicDefinitions.Add("AK_SUPPORT_DEVICE_MEMORY=0");
		}

		// Platform-specific dependencies
#if UE_4_24_OR_LATER
		PublicSystemLibraries.AddRange(AkUEPlatformInstance.GetPublicSystemLibraries());
#else
		PublicLibraryPaths.AddRange(AkUEPlatformInstance.GetPublicLibraryPaths());
		PublicAdditionalLibraries.AddRange(AkUEPlatformInstance.GetPublicSystemLibraries());
#endif
		AkLibs.AddRange(AkUEPlatformInstance.GetAdditionalWwiseLibs());
		PublicDefinitions.AddRange(AkUEPlatformInstance.GetPublicDefinitions());
		PublicDefinitions.Add(string.Format("AK_CONFIGURATION=\"{0}\"", AkUEPlatformInstance.AkConfigurationDir));
		var AdditionalProperty = AkUEPlatformInstance.GetAdditionalPropertyForReceipt(ModuleDirectory);
		if (AdditionalProperty != null)
		{
			AdditionalPropertiesForReceipt.Add(AdditionalProperty.Item1, AdditionalProperty.Item2);
		}

		PublicFrameworks.AddRange(AkUEPlatformInstance.GetPublicFrameworks());
		
		PublicDelayLoadDLLs.AddRange(AkUEPlatformInstance.GetPublicDelayLoadDLLs());
		foreach(var RuntimeDependency in AkUEPlatformInstance.GetRuntimeDependencies())
		{
			RuntimeDependencies.Add(RuntimeDependency);
		}
		PublicAdditionalLibraries.AddRange(AkUEPlatformInstance.GetSanitizedAkLibList(AkLibs));
	}

	private static List<string> GetAvailablePlatforms(string ModuleDir)
	{
		var FoundPlatforms = new List<string>();
		const string StartPattern = "AkAudio_";
		const string EndPattern = ".Build.cs";
		foreach (var BuildCsFile in System.IO.Directory.GetFiles(ModuleDir, "*" + EndPattern))
		{
			if (BuildCsFile.Contains("AkAudio_"))
			{
				int StartIndex = BuildCsFile.IndexOf(StartPattern) + StartPattern.Length;
				int StopIndex = BuildCsFile.IndexOf(EndPattern);
				FoundPlatforms.Add(BuildCsFile.Substring(StartIndex, StopIndex - StartIndex));
			}
		}

		return FoundPlatforms;
	}
}
