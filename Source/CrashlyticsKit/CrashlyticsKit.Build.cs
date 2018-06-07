// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

using System.IO;

namespace UnrealBuildTool.Rules
{
    public class CrashlyticsKit : ModuleRules
    {
        public CrashlyticsKit(ReadOnlyTargetRules Target) : base(Target)
        {
            PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

            bool bEnableCrashlyticsKit = true;

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

            PrivateIncludePathModuleNames.AddRange(
                new string[] {
                    "Settings",
                }
            );

            if (bEnableCrashlyticsKit)
            {
                // Fabric platform libraries
                if (Target.Platform == UnrealTargetPlatform.IOS)
                {
                    PublicAdditionalFrameworks.Add(
                        new UEBuildFramework(
                            "Fabric",
                            "../../ThirdParty/iOS/Fabric.embeddedframework.zip"
                        )
                    );

                    PublicAdditionalFrameworks.Add(
                        new UEBuildFramework(
                            "Crashlytics",
                            "../../ThirdParty/iOS/Crashlytics.embeddedframework.zip"
                        )
                    );
                }
                else if (Target.Platform == UnrealTargetPlatform.Android)
                {
                    PublicDependencyModuleNames.AddRange(
                        new string[]
                        {
                           "Launch"
                        });

                    string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
                    AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "CrashlyticsKit_APL.xml"));
                }
            }
			
			PublicDefinitions.Add("WITH_CRASHLYTICS=" + (bEnableCrashlyticsKit ? "1" : "0"));
        }
    }
}
