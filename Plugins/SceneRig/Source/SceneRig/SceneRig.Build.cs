using UnrealBuildTool;

public class SceneRig : ModuleRules {
    public SceneRig(ReadOnlyTargetRules Target) : base(Target) {
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
            "BinkMediaPlayer",
            "CameraStack",
            "Chaos",
            "CinematicCamera",
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
            "PhoenixSignificanceManager",
            "PhysicsCore",
            "PropertyPath",
            "RigVM",
            "Slate",
            "SlateCore",
            "TimeRig",
            "UMG",
            "UtilitiesRuntime",
        });
    }
}
