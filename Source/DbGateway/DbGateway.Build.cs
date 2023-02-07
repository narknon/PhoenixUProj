using UnrealBuildTool;

public class DbGateway : ModuleRules {
    public DbGateway(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "CISQLite3",
            "Core",
            "CoreUObject",
            "Engine",
        });
    }
}
