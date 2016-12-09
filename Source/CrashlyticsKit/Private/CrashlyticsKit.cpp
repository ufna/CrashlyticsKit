// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#include "CrashlyticsKitPrivatePCH.h"

#include "ISettingsModule.h"

#define LOCTEXT_NAMESPACE "CrashlyticsKit"

class FCrashlyticsKit : public ICrashlyticsKit
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override
	{
		// Register settings
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			SettingsModule->RegisterSettings("Project", "Plugins", "VaFabricTools",
				LOCTEXT("RuntimeSettingsName", "Crashlytics Kit"),
				LOCTEXT("RuntimeSettingsDescription", "Configure API keys for Crashlytics"),
				GetMutableDefault<UCrashlyticsKitSettings>()
			);
		}
	}

	virtual void ShutdownModule() override
	{

	}
};

IMPLEMENT_MODULE( FCrashlyticsKit, CrashlyticsKit )

DEFINE_LOG_CATEGORY(LogCrashlytics);

#undef LOCTEXT_NAMESPACE
