// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#include "CrashlyticsKitProxy.h"
#include "CrashlyticsKitCommon.h"

UCrashlyticsKitProxy::UCrashlyticsKitProxy(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCrashlyticsInitialized = false;
}

/////////////////////////////////////////////////////////////////////////
// Setup

void UCrashlyticsKitProxy::InitCrashlytics()
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: Null proxy used"), *VA_FUNC_LINE);
}

void UCrashlyticsKitProxy::ForceCrash()
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: Null proxy used"), *VA_FUNC_LINE);
}

void UCrashlyticsKitProxy::ForceException()
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: Null proxy used"), *VA_FUNC_LINE);
}

void UCrashlyticsKitProxy::SetUserIdentifier(FString UserIdentifier)
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: %s"), *VA_FUNC_LINE, *UserIdentifier);
}

void UCrashlyticsKitProxy::SetUserEmail(FString UserEmail)
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: %s"), *VA_FUNC_LINE, *UserEmail);
}

void UCrashlyticsKitProxy::SetUserName(FString UserName)
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: %s"), *VA_FUNC_LINE, *UserName);
}

void UCrashlyticsKitProxy::WriteLog(FString Log)
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: %s"), *VA_FUNC_LINE, *Log);
}

void UCrashlyticsKitProxy::WriteError(FString Log, int32 Code)
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: %s (%d)"), *VA_FUNC_LINE, *Log, Code);
}

bool UCrashlyticsKitProxy::IsInitialized() const
{
	return bCrashlyticsInitialized;
}


/////////////////////////////////////////////////////////////////////////
// Crashlytics Keys

void UCrashlyticsKitProxy::SetObjectValue(FString Key, FString Value)
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: %s -- %s"), *VA_FUNC_LINE, *Key, *Value);
}

void UCrashlyticsKitProxy::SetIntValue(FString Key, int32 Value)
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: %s -- %d"), *VA_FUNC_LINE, *Key, Value);
}

void UCrashlyticsKitProxy::SetBoolValue(FString Key, bool Value)
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: %s -- %d"), *VA_FUNC_LINE, *Key, (int32)Value);
}

void UCrashlyticsKitProxy::SetFloatValue(FString Key, float Value)
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: %s -- %f"), *VA_FUNC_LINE, *Key, Value);
}


/////////////////////////////////////////////////////////////////////////
// Answers Events

void UCrashlyticsKitProxy::EventSignUp(FString Method, bool bSuccess, FString CustomAttributesJSON)
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: %s (%d) -- %s"), *VA_FUNC_LINE, *Method, (int32)bSuccess, *CustomAttributesJSON);
}

void UCrashlyticsKitProxy::EventLogIn(FString Method, bool bSuccess, FString CustomAttributesJSON)
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: %s (%d) -- %s"), *VA_FUNC_LINE, *Method, (int32)bSuccess, *CustomAttributesJSON);
}

void UCrashlyticsKitProxy::EventCustom(FString EventName, FString CustomAttributesJSON)
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: %s -- %s"), *VA_FUNC_LINE, *EventName, *CustomAttributesJSON);
}
