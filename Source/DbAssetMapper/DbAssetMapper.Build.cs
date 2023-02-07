using UnrealBuildTool;

public class DbAssetMapper : ModuleRules {
    public DbAssetMapper(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "CISQLite3",
            "Core",
            "CoreUObject",
            "EditorCustomizationHelper",
            "Engine",
        });
    }
}
