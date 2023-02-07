using UnrealBuildTool;

public class BTCustomRuntime : ModuleRules {
    public BTCustomRuntime(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "AnimGraphRuntime",
            "AnimationArchitectRuntime",
            "AnimationCore",
            "AudioMixer",
            "AvaAnimation",
            "Chaos",
            "ClothingSystemRuntimeCommon",
            "ClothingSystemRuntimeInterface",
            "ControlMapper",
            "ControlRig",
            "Core",
            "CoreUObject",
            "CustomizableCharacter",
            "DeveloperSettings",
            "Engine",
            "GameLogicRuntime",
            "GameplayTags",
            "GameplayTasks",
            "InputCore",
            "Landscape",
            "LevelSequence",
            "MediaAssets",
            "MediaUtils",
            "MovieScene",
            "MovieSceneTracks",
            "NavigationSystem",
            "Niagara",
            "NiagaraCore",
            "NiagaraShader",
            "PhysicsCore",
            "PropertyPath",
            "RigVM",
            "Slate",
            "SlateCore",
            "UMG",
            "UtilitiesRuntime",
        });
    }
}
