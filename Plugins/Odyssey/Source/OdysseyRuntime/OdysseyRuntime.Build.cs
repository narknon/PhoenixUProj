using UnrealBuildTool;

public class OdysseyRuntime : ModuleRules {
    public OdysseyRuntime(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "Core",
            "CoreUObject",
            "DebugPanel",
            "DeveloperSettings",
            "Engine",
            "GameplayTags",
            "GameplayTasks",
            "NavigationSystem",
            "SlateCore",
        });
    }
}
