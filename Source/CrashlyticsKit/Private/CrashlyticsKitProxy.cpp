// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#include "CrashlyticsKitPrivatePCH.h"

UCrashlyticsKitProxy::UCrashlyticsKitProxy(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCrashlyticsInitialized = true;
}

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

bool UCrashlyticsKitProxy::IsInitialized()
{
	return bCrashlyticsInitialized;
}
