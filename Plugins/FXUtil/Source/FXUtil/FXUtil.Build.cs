using UnrealBuildTool;

public class FXUtil : ModuleRules {
    public FXUtil(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AkAudio",
            "AvaRenderTech",
            "Chaos",
            "Core",
            "CoreUObject",
            "DeveloperSettings",
            "Engine",
            "Foliage",
            "InputCore",
            "MaterialPermuter",
            "MovieScene",
            "MovieSceneTracks",
            "MultiFX2",
            "Niagara",
            "NiagaraCore",
            "NiagaraShader",
            "PhysicsCore",
            "PropertyPath",
            "SkinFX",
            "Slate",
            "SlateCore",
            "UMG",
        });
    }
}
