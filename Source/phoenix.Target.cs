using UnrealBuildTool;

public class phoenixTarget : TargetRules {
	public phoenixTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Game;
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
