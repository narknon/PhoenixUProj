using UnrealBuildTool;

public class Cognition : ModuleRules {
    public Cognition(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "AvaRenderTech",
            "Chaos",
            "ControlMapper",
            "Core",
            "CoreUObject",
            "DeveloperSettings",
            "Engine",
            "GameLogicRuntime",
            "GameplayTags",
            "GameplayTasks",
            "MaterialPermuter",
            "MovieScene",
            "NavigationSystem",
            "Niagara",
            "NiagaraCore",
            "NiagaraShader",
            "PhysicsCore",
            "SkinFX",
            "SlateCore",
            "StencilManager",
        });
    }
}
