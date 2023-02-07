using UnrealBuildTool;

public class TimeRig : ModuleRules {
    public TimeRig(ReadOnlyTargetRules Target) : base(Target) {
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
            "ControlRig",
            "Core",
            "CoreUObject",
            "CustomizableCharacter",
            "DeveloperSettings",
            "Engine",
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
