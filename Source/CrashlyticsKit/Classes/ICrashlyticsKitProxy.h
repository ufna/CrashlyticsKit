// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "ICrashlyticsKitProxy.generated.h"

UINTERFACE(Blueprintable, meta=(CannotImplementInterfaceInBlueprint))
class UCrashlyticsKitProxyInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class CRASHLYTICSKIT_API ICrashlyticsKitProxyInterface
{
	GENERATED_IINTERFACE_BODY()

	/** Initialize Crashlytics global object */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit)
	virtual void InitCrashlytics() = 0;

	/** Force crash */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit)
	virtual void ForceCrash() = 0;

	/** Force exception */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit)
	virtual void ForceException() = 0;

	/** */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit)
	virtual void SetUserIdentifier(FString UserIdentifier) = 0;

	/** */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit)
	virtual void SetUserEmail(FString UserEmail) = 0;

	/** */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit)
	virtual void SetUserName(FString UserName) = 0;

	/** */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit)
	virtual void WriteLog(FString Log) = 0;
};