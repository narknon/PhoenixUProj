using UnrealBuildTool;

public class phoenixEditorTarget : TargetRules {
	public phoenixEditorTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new string[] {
			"AIPathScheduler",
			"AvaAnimationShim",
			"CreatureBehavior",
			"DbAssetMapper",
			"DbGateway",
			"GameScheduler",
			"OnlineStore",
			"PersistentData",
			"Phoenix",
			"PhoenixSignificanceManager",
			"SceneRigShim",
			"SocialDisplay",
		});
		
		bUseChaos = true;
		bCompileChaos = true;
	}
}
