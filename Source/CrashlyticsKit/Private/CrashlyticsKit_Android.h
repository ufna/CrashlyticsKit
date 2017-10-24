// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "CrashlyticsKit_Android.generated.h"

UCLASS()
class UCrashlyticsKit_Android : public UCrashlyticsKitProxy
{
	GENERATED_UCLASS_BODY()

#if WITH_CRASHLYTICS && PLATFORM_ANDROID
	// Begin UCrashlyticsKitProxy interface
	virtual void InitCrashlytics() override;
	virtual void ForceCrash() override;
	virtual void ForceException() override;
	virtual void SetUserIdentifier(FString UserIdentifier) override;
	virtual void SetUserEmail(FString UserEmail) override;
	virtual void SetUserName(FString UserName) override;
	virtual void WriteLog(FString Log) override;
	virtual void WriteError(FString Log, int32 Code) override;
	// End UCrashlyticsKitProxy interface
#endif // WITH_CRASHLYTICS && PLATFORM_ANDROID

};
