// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

using System.IO;

namespace UnrealBuildTool.Rules
{
	public class CrashlyticsKit : ModuleRules
	{
		public CrashlyticsKit(TargetInfo Target)
		{
			PrivateIncludePaths.AddRange(
				new string[] {
					"CrashlyticsKit/Private",
					// ... add other private include paths required here ...
				});

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine"
					// ... add other public dependencies that you statically link with here ...
				});
		}
	}
}