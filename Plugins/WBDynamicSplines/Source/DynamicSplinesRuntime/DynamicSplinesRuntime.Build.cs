using UnrealBuildTool;

public class DynamicSplinesRuntime : ModuleRules {
    public DynamicSplinesRuntime(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "Chaos",
            "Core",
            "CoreUObject",
            "DeveloperSettings",
            "Engine",
            "MovieScene",
            "Niagara",
            "NiagaraCore",
            "NiagaraShader",
            "PhysicsCore",
        });
    }
}
