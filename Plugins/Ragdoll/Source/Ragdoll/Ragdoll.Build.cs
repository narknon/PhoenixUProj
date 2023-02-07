using UnrealBuildTool;

public class Ragdoll : ModuleRules {
    public Ragdoll(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AkAudio",
            "Chaos",
            "Core",
            "CoreUObject",
            "DeveloperSettings",
            "Engine",
            "GameplayTags",
            "InputCore",
            "MasterTickThrottler",
            "MovieScene",
            "MovieSceneTracks",
            "PhysicsCore",
            "PropertyPath",
            "Slate",
            "SlateCore",
            "UMG",
        });
    }
}
