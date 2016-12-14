// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#include "CrashlyticsKitPrivatePCH.h"

#include "ISettingsModule.h"

#define LOCTEXT_NAMESPACE "CrashlyticsKit"

class FCrashlyticsKit : public ICrashlyticsKit
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override
	{
		KitSettings = NewObject<UCrashlyticsKitSettings>(GetTransientPackage(), "CrashlyticsKitSettings", RF_Standalone);
		KitSettings->AddToRoot();

		// We need to manually load the config properties here, as this module is loaded before the UObject system is setup to do this
		GConfig->GetBool(TEXT("/Script/CrashlyticsKit.CrashlyticsKitSettings"), TEXT("CrashlyticsManualInit"), KitSettings->bCrashlyticsManualInit, GEngineIni);

		// Register settings
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			SettingsModule->RegisterSettings("Project", "Plugins", "VaFabricTools",
				LOCTEXT("RuntimeSettingsName", "Crashlytics Kit"),
				LOCTEXT("RuntimeSettingsDescription", "Configure API keys for Crashlytics"),
				KitSettings
			);
		}

		// Proxy class depends on platform
		UClass* KitPlatformClass = UCrashlyticsKitProxy::StaticClass();
#if WITH_CRASHLYTICS
#if PLATFORM_IOS
		KitPlatformClass = UCrashlyticsKit_iOS::StaticClass();
#elif PLATFORM_ANDROID
		KitPlatformClass = UCrashlyticsKit_Android::StaticClass();
#endif
#endif

		// Create crashlytics kit proxy and initalize module by default
		CrashlyticsKit = NewObject<UCrashlyticsKitProxy>(GetTransientPackage(), KitPlatformClass);
		CrashlyticsKit->SetFlags(RF_Standalone);
		CrashlyticsKit->AddToRoot();

		// Check for manual kit initialization
		if (KitSettings->bCrashlyticsManualInit == false)
		{
			CrashlyticsKit->InitCrashlytics();
		}
	}

	virtual void ShutdownModule() override
	{
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
		{
			SettingsModule->UnregisterSettings("Project", "Plugins", "VaFabricTools");
		}

		if (!GExitPurge)
		{
			// If we're in exit purge, this object has already been destroyed
			CrashlyticsKit->RemoveFromRoot();
			KitSettings->RemoveFromRoot();
		}
		else
		{
			CrashlyticsKit = nullptr;
			KitSettings = nullptr;
		}
	}

private:
	/** Holds the kit settings */
	UCrashlyticsKitSettings* KitSettings;

};

IMPLEMENT_MODULE(FCrashlyticsKit, CrashlyticsKit)

DEFINE_LOG_CATEGORY(LogVftCrashlytics);

#undef LOCTEXT_NAMESPACE
