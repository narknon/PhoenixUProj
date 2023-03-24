using UnrealBuildTool;

public class AnimationArchitectRuntime : ModuleRules {
    public AnimationArchitectRuntime(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AnimationBudgetAllocator",
            "AnimGraphRuntime",
            "AnimationCore",
            "Chaos",
            "ClothingSystemRuntimeCommon",
            "ClothingSystemRuntimeInterface",
            "Core",
            "CoreUObject",
            "CustomizableCharacter",
            "DeveloperSettings",
            "Engine",
            "GameplayTags",
            "MovieScene",
            "Niagara",
            "NiagaraCore",
            "NiagaraShader",
            "PhysicsCore",
            "SlateCore",
        });
    }
}
