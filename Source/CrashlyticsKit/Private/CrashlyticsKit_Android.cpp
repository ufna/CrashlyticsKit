// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#include "CrashlyticsKitPrivatePCH.h"

UCrashlyticsKit_Android::UCrashlyticsKit_Android(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void UCrashlyticsKit_Android::InitCrashlytics()
{
	UE_LOG(LogVftCrashlytics, Verbose, TEXT("%s: ---"), *VA_FUNC_LINE);
}

void UCrashlyticsKit_Android::ForceCrash()
{
	UE_LOG(LogVftCrashlytics, Verbose, TEXT("%s: ---"), *VA_FUNC_LINE);
}

void UCrashlyticsKit_Android::ForceException()
{
	UE_LOG(LogVftCrashlytics, Verbose, TEXT("%s: ---"), *VA_FUNC_LINE);
}

void UCrashlyticsKit_Android::SetUserIdentifier(FString UserIdentifier)
{
	UE_LOG(LogVftCrashlytics, Verbose, TEXT("%s: ---"), *VA_FUNC_LINE);
}

void UCrashlyticsKit_Android::SetUserEmail(FString UserEmail)
{
	UE_LOG(LogVftCrashlytics, Verbose, TEXT("%s: ---"), *VA_FUNC_LINE);
}

void UCrashlyticsKit_Android::SetUserName(FString UserName)
{
	UE_LOG(LogVftCrashlytics, Verbose, TEXT("%s: ---"), *VA_FUNC_LINE);
}

void UCrashlyticsKit_Android::WriteLog(FString Log)
{
	UE_LOG(LogVftCrashlytics, Verbose, TEXT("%s: ---"), *VA_FUNC_LINE);
}
