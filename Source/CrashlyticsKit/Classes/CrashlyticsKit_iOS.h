// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "CrashlyticsKit_iOS.generated.h"

UCLASS()
class CRASHLYTICSKIT_API UCrashlyticsKit_iOS : public UCrashlyticsKitProxy
{
	GENERATED_UCLASS_BODY()

	// Begin ICrashlyticsKitProxyInterface
	virtual void InitCrashlytics() override;
	virtual void ForceCrash() override;
	virtual void ForceException() override;
	virtual void SetUserIdentifier(FString UserIdentifier) override;
	virtual void SetUserEmail(FString UserEmail) override;
	virtual void SetUserName(FString UserName) override;
	virtual void WriteLog(FString Log) override;
	// End ICrashlyticsKitProxyInterface
};
