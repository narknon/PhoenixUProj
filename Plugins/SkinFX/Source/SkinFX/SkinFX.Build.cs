using UnrealBuildTool;

public class SkinFX : ModuleRules {
    public SkinFX(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AvaRenderTech",
            "Chaos",
            "Core",
            "CoreUObject",
            "DeveloperSettings",
            "Engine",
            "MaterialPermuter",
            "MovieScene",
            "Niagara",
            "NiagaraCore",
            "NiagaraShader",
            "PhysicsCore",
        });
    }
}
