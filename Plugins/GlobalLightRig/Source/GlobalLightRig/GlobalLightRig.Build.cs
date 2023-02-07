using UnrealBuildTool;

public class GlobalLightRig : ModuleRules {
    public GlobalLightRig(ReadOnlyTargetRules Target) : base(Target) {
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
            "LerpVolumes",
            "MovieScene",
            "Niagara",
            "NiagaraCore",
            "NiagaraShader",
            "PhysicsCore",
            "RenderSettings",
            "VolumetricClouds",
        });
    }
}
