// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#include "CrashlyticsKitLibrary.generated.h"

#if WITH_CRASHLYTICS && PLATFORM_IOS
#import <Crashlytics/Crashlytics.h>
#import <Fabric/Fabric.h>
#endif // WITH_CRASHLYTICS && PLATFORM_IOS

#define CLSLOG(Text)                                                    \
	if (UCrashlyticsKitLibrary::GetCrashlyticsProxy()->IsInitialized()) \
		UCrashlyticsKitLibrary::GetCrashlyticsProxy()->WriteLog(Text);

#define CLSERROR(Text, Code)                                            \
	if (UCrashlyticsKitLibrary::GetCrashlyticsProxy()->IsInitialized()) \
		UCrashlyticsKitLibrary::GetCrashlyticsProxy()->WriteError(Text, Code);

#define CLSSTAT(Label, Value)                                           \
	if (UCrashlyticsKitLibrary::GetCrashlyticsProxy()->IsInitialized()) \
		UCrashlyticsKitLibrary::GetCrashlyticsProxy()->WriteStat(Label, Value);

UCLASS()
class CRASHLYTICSKIT_API UCrashlyticsKitLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	/** */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit, BlueprintPure)
	static UCrashlyticsKitProxy* GetCrashlyticsProxy();
};
