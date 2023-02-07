using UnrealBuildTool;

public class DesignerHelper : ModuleRules {
    public DesignerHelper(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "EditorCustomizationHelper",
            "Engine",
        });
    }
}
