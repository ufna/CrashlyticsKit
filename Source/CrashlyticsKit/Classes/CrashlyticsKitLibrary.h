// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "CrashlyticsKitLibrary.generated.h"

#if WITH_CRASHLYTICS && PLATFORM_IOS
#import <Fabric/Fabric.h>
#import <Crashlytics/Crashlytics.h>
#endif // WITH_CRASHLYTICS && PLATFORM_IOS

#if WITH_CRASHLYTICS && PLATFORM_IOS
	#define CLSLOG(Text) if(UCrashlyticsKitLibrary::GetCrashlyticsProxy()->IsInitialized()) CLS_LOG(@"%@", FString(Text).GetNSString());
#else
	#define CLSLOG(Text) if(UCrashlyticsKitLibrary::GetCrashlyticsProxy()->IsInitialized()) UCrashlyticsKitLibrary::GetCrashlyticsProxy()->WriteLog(Text);
#endif

#define CLSERROR(Text, Code) if(UCrashlyticsKitLibrary::GetCrashlyticsProxy()->IsInitialized()) UCrashlyticsKitLibrary::GetCrashlyticsProxy()->WriteError(Text, Code);

UCLASS()
class CRASHLYTICSKIT_API UCrashlyticsKitLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/** */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit, BlueprintPure)
	static UCrashlyticsKitProxy* GetCrashlyticsProxy();
};
