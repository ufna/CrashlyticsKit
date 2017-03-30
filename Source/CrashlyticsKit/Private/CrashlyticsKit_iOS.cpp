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

/////////////////////////////////////////////////////////////////////////
// Setup

void UCrashlyticsKit_iOS::InitCrashlytics()
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: Initialize Crashlytics Kit with iOS SDK"), *VA_FUNC_LINE);

	if (bCrashlyticsInitialized)
	{
		UE_LOG(LogVftCrashlytics, Error, TEXT("%s: Trying to initialize Crashlytics when it's already been initialized!"), *VA_FUNC_LINE);
		return;
	}

	dispatch_async(dispatch_get_main_queue(), ^{
		[Fabric with : @[[Crashlytics class]]];
	});

	bCrashlyticsInitialized = true;
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


/////////////////////////////////////////////////////////////////////////
// Answers Events

void UCrashlyticsKit_iOS::EventSignUp(FString Method, bool bSuccess, FString CustomAttributesJSON)
{
	dispatch_async(dispatch_get_main_queue(), ^{
		[Answers logSignUpWithMethod:Method.GetNSString()
							 success:[NSNumber numberWithBool:bSuccess]
					customAttributes:GetNSDictionaryFromJSONString(CustomAttributesJSON)];
	});
}

void UCrashlyticsKit_iOS::EventLogIn(FString Method, bool bSuccess, FString CustomAttributesJSON)
{
	dispatch_async(dispatch_get_main_queue(), ^{
		[Answers logLoginWithMethod:Method.GetNSString()
							success:[NSNumber numberWithBool:bSuccess]
				   customAttributes:GetNSDictionaryFromJSONString(CustomAttributesJSON)];
	});
}

void UCrashlyticsKit_iOS::EventCustom(FString EventName, FString CustomAttributesJSON)
{
	dispatch_async(dispatch_get_main_queue(), ^{
		[Answers logCustomEventWithName : EventName.GetNSString()
					   customAttributes : GetNSDictionaryFromJSONString(CustomAttributesJSON)];
	});
}


/////////////////////////////////////////////////////////////////////////
// Helpers

NSDictionary* UCrashlyticsKit_iOS::GetNSDictionaryFromJSONString(const FString& JSONString)
{
	if (JSONString.IsEmpty())
	{
		return nil;
	}
	
	NSError *Err = nil;
	NSData* Data = [JSONString.GetNSString() dataUsingEncoding:NSUTF8StringEncoding];
	NSDictionary *Dict = [NSJSONSerialization JSONObjectWithData:Data
														 options:0
														   error:&Err];
	
	if (Err)
	{
		NSLog(@"Error converting string to JSON. String: \"%@\", error: %@", JSONString.GetNSString(), [Err description]);
		return nil;
	}
	
	return Dict;
}

#endif // WITH_CRASHLYTICS && PLATFORM_IOS
