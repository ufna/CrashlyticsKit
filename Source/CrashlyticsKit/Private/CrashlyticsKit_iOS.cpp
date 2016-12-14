// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#include "CrashlyticsKitPrivatePCH.h"

#if WITH_CRASHLYTICS && PLATFORM_IOS
	#import <Fabric/Fabric.h>
	#import <Crashlytics/Crashlytics.h>
#endif // WITH_CRASHLYTICS && PLATFORM_IOS

UCrashlyticsKit_iOS::UCrashlyticsKit_iOS(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

#if WITH_CRASHLYTICS && PLATFORM_IOS

void UCrashlyticsKit_iOS::InitCrashlytics()
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: Initialize Crashlytics Kit with iOS SDK"), *VA_FUNC_LINE);

	dispatch_async(dispatch_get_main_queue(), ^{
		[Fabric with : @[[Crashlytics class]]];
	});
}

void UCrashlyticsKit_iOS::ForceCrash()
{
	dispatch_async(dispatch_get_main_queue(), ^{
		[CrashlyticsKit crash];
	});
}

void UCrashlyticsKit_iOS::ForceException()
{
	dispatch_async(dispatch_get_main_queue(), ^{
		[CrashlyticsKit throwException];
	});
}

void UCrashlyticsKit_iOS::SetUserIdentifier(FString UserIdentifier)
{
	dispatch_async(dispatch_get_main_queue(), ^{
		[CrashlyticsKit setUserIdentifier : UserIdentifier.GetNSString()];
	});
}

void UCrashlyticsKit_iOS::SetUserEmail(FString UserEmail)
{
	dispatch_async(dispatch_get_main_queue(), ^{
		[CrashlyticsKit setUserEmail : UserEmail.GetNSString()];
	});
}

void UCrashlyticsKit_iOS::SetUserName(FString UserName)
{
	dispatch_async(dispatch_get_main_queue(), ^{
		[CrashlyticsKit setUserName : UserName.GetNSString()];
	});
}

void UCrashlyticsKit_iOS::WriteLog(FString Log)
{
	dispatch_async(dispatch_get_main_queue(), ^{
		CLS_LOG(@"%@", Log.GetNSString());
	});
}

#endif // WITH_CRASHLYTICS && PLATFORM_IOS
