// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "CrashlyticsKitProxy.h"
#include "CrashlyticsKit_iOS.generated.h"

UCLASS()
class UCrashlyticsKit_iOS : public UCrashlyticsKitProxy
{
	GENERATED_UCLASS_BODY()

#if WITH_CRASHLYTICS && PLATFORM_IOS
	// Begin UCrashlyticsKitProxy interface
	virtual void InitCrashlytics() override;
	virtual void ForceCrash() override;
	virtual void ForceException() override;
	virtual void SetUserIdentifier(FString UserIdentifier) override;
	virtual void SetUserEmail(FString UserEmail) override;
	virtual void SetUserName(FString UserName) override;
	virtual void WriteLog(FString Log) override;
	virtual void WriteError(FString Log, int32 Code) override;

	virtual void SetObjectValue(FString Key, FString Value) override;
	virtual void SetIntValue(FString Key, int32 Value) override;
	virtual void SetBoolValue(FString Key, bool Value) override;
	virtual void SetFloatValue(FString Key, float Value) override;

	virtual void EventSignUp(FString Method, bool bSuccess, FString CustomAttributesJSON) override;
	virtual void EventLogIn(FString Method, bool bSuccess, FString CustomAttributesJSON) override;
	virtual void EventCustom(FString EventName, FString CustomAttributesJSON) override;
	// End UCrashlyticsKitProxy interface

	/////////////////////////////////////////////////////////////////////////
	// Helpers
private:
	static NSDictionary* GetNSDictionaryFromJSONString(const FString& JSONString);

#endif // WITH_CRASHLYTICS && PLATFORM_IOS
};
