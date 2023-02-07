using UnrealBuildTool;

public class MaterialPermuter : ModuleRules {
    public MaterialPermuter(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AvaRenderTech",
            "Core",
            "CoreUObject",
            "Engine",
        });
    }
}
