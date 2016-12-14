// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

using System.IO;

namespace UnrealBuildTool.Rules
{
    public class CrashlyticsKit : ModuleRules
    {
        public CrashlyticsKit(TargetInfo Target)
        {
            const bool bEnableCrashlyticsKit = true;
            Definitions.Add("WITH_CRASHLYTICS=" + (bEnableCrashlyticsKit ? "1" : "0"));

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
            }
        }
    }
}