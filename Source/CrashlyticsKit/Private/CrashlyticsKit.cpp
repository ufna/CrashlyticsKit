// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#include "CrashlyticsKitPrivatePCH.h"

class FCrashlyticsKit : public ICrashlyticsKit
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override
	{

	}

	virtual void ShutdownModule() override
	{

	}
};

IMPLEMENT_MODULE( FCrashlyticsKit, CrashlyticsKit )

DEFINE_LOG_CATEGORY(LogCrashlytics);
