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

public class AudiokineticTools : ModuleRules
{
#if WITH_FORWARDED_MODULE_RULES_CTOR
    public AudiokineticTools(ReadOnlyTargetRules Target) : base(Target)
#else
    public AudiokineticTools(TargetInfo Target)
#endif
    {
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PrivateIncludePaths.Add("AudiokineticTools/Private");
        PrivateIncludePaths.Add("AkAudio/Classes/GTE");
        PrivateIncludePathModuleNames.AddRange(
            new string[]
            {
                "TargetPlatform",
                "MainFrame",
				"MovieSceneTools"
            });

        PublicIncludePathModuleNames.AddRange(
            new string[] 
            { 
                "AssetTools",
                "ContentBrowser",
#if UE_4_24_OR_LATER
                "ToolMenus"
#endif
            });

        PublicDependencyModuleNames.AddRange(
            new string[] 
            { 
                "AkAudio",
                "Core",
                "InputCore",
                "CoreUObject",
                "Engine",
                "UnrealEd",
                "Slate",
                "SlateCore",
                "EditorStyle",
				"Json",
				"XmlParser",
				"WorkspaceMenuStructure",
				"DirectoryWatcher",
                "Projects",
				"Sequencer",
                "PropertyEditor",
                "SharedSettingsWidgets",
                "ContentBrowser",
#if UE_5_0_OR_LATER
                "DeveloperToolSettings",
#endif

#if UE_4_26_OR_LATER
                "ContentBrowserData",
#endif
#if UE_4_24_OR_LATER
                "ToolMenus"
#endif
            });

        PrivateDependencyModuleNames.AddRange(
            new string[]
			{
				"MovieScene",
				"DesktopPlatform",
				"MovieSceneTools",
				"MovieSceneTracks",
				"RenderCore",
				"SourceControl",
                "LevelEditor",
#if UE_5_0_OR_LATER
                "EditorFramework"
#endif
            });

#if UE_4_26_OR_LATER
        PrivateDependencyModuleNames.Add("RHI");
#endif
    }
}
