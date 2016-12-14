// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "CrashlyticsKitProxy.generated.h"

UCLASS()
class CRASHLYTICSKIT_API UCrashlyticsKitProxy : public UObject
{
	GENERATED_UCLASS_BODY()

	/** Initialize Crashlytics global object */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit)
	virtual void InitCrashlytics();

	/** Force crash */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit)
	virtual void ForceCrash();

	/** Force exception */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit)
	virtual void ForceException();

	/** */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit)
	virtual void SetUserIdentifier(FString UserIdentifier);

	/** */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit)
	virtual void SetUserEmail(FString UserEmail);

	/** */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit)
	virtual void SetUserName(FString UserName);

	/** */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit)
	virtual void WriteLog(FString Log);
};