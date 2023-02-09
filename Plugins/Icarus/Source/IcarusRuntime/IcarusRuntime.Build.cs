using UnrealBuildTool;

public class IcarusRuntime : ModuleRules {
    public IcarusRuntime(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "AbleCore",
            "AkAudio",
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
            "DeveloperSettings",
            "Engine",
            "GameLogicRuntime",
            "GameplayTags",
            "GameplayTasks",
            "InputCore",
            "Landscape",
            "LevelSequence",
            "MaterialPermuter",
            "MediaAssets",
            "MediaUtils",
            "Mercuna",
            "Mercuna3DMovement",
            "MovieScene",
            "MovieSceneTracks",
            "NavigationSystem",
            "Niagara",
            "NiagaraCore",
            "NiagaraShader",
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
