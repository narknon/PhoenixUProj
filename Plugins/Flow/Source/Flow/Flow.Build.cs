using UnrealBuildTool;

public class Flow : ModuleRules {
    public Flow(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "AbleCore",
            "AkAudio",
            "Ambulatory",
            "AnimGraphRuntime",
            "AnimationArchitectRuntime",
            "AnimationCore",
            "AudioMixer",
            "AvaAnimation",
            "AvaRenderTech",
            "BTCustomRuntime",
            "Chaos",
            "ClothingSystemRuntimeCommon",
            "ClothingSystemRuntimeInterface",
            "ControlMapper",
            "ControlRig",
            "Core",
            "CoreUObject",
            "CustomizableCharacter",
            "DebugPanel",
            "DeveloperSettings",
            "Engine",
            "GameLogicRuntime",
            "GameplayTags",
            "GameplayTasks",
            "Hermes",
            "InputCore",
            "Landscape",
            "LevelSequence",
            "MaterialPermuter",
            "MediaAssets",
            "MediaUtils",
            "MovieScene",
            "MovieSceneTracks",
            "NavigationSystem",
            "Niagara",
            "NiagaraCore",
            "NiagaraShader",
            "OdysseyRuntime",
            "PhysicsCore",
            "PropertyPath",
            "Ragdoll",
            "RigVM",
            "SkinFX",
            "Slate",
            "SlateCore",
            "StencilManager",
            "UMG",
            "UtilitiesRuntime",
        });
    }
}
