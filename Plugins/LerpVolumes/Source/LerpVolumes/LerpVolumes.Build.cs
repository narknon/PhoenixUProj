using UnrealBuildTool;

public class LerpVolumes : ModuleRules {
    public LerpVolumes(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AnimatedLights",
            "Chaos",
            "ConsoleMacros",
            "Core",
            "CoreUObject",
            "DeveloperSettings",
            "Engine",
            "EnvironmentalGlobals",
            "ExposureConvert",
            "ExposureExpressions",
            "MovieScene",
            "Niagara",
            "NiagaraCore",
            "NiagaraShader",
            "PhysicsCore",
            "RenderSettings",
        });
    }
}
