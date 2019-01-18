// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "CrashlyticsKitProxy.generated.h"

UCLASS()
class CRASHLYTICSKIT_API UCrashlyticsKitProxy : public UObject
{
	GENERATED_UCLASS_BODY()

	/////////////////////////////////////////////////////////////////////////
	// Setup

	/** Initialize Crashlytics global object */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Setup")
	virtual void InitCrashlytics();

	/** Force crash */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Setup")
	virtual void ForceCrash();

	/** Force exception */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Setup")
	virtual void ForceException();

	/** */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Setup")
	virtual void SetUserIdentifier(FString UserIdentifier);

	/** */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Setup")
	virtual void SetUserEmail(FString UserEmail);

	/** */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Setup")
	virtual void SetUserName(FString UserName);

	/** */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Setup")
	virtual void WriteLog(FString Log);

	/** */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Setup")
	virtual void WriteError(FString Log, int32 Code);

	/** Write string stat */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Setup")
	virtual void WriteStat(FString Label, FString Value);

	/** */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Setup")
	bool IsInitialized() const;

protected:
	/** */
	bool bCrashlyticsInitialized;

	/** */
	uint64 LastFrameNumber;

	/////////////////////////////////////////////////////////////////////////
	// Crashlytics Keys

public:
	/** */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Keys")
	virtual void SetObjectValue(FString Key, FString Value);

	/** */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Keys")
	virtual void SetIntValue(FString Key, int32 Value);

	/** */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Keys")
	virtual void SetBoolValue(FString Key, bool Value);

	/** */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Keys")
	virtual void SetFloatValue(FString Key, float Value);

	/////////////////////////////////////////////////////////////////////////
	// Answers Events

public:
	/** @todo Event: Purchases */
	/** @todo Event: Add to Cart */
	/** @todo Event: Start Checkout */
	/** @todo Event: Content View */
	/** @todo Event: Search */
	/** @todo Event: Share */
	/** @todo Event: Rated Content */

	/** Event: Sign Up */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Answers")
	virtual void EventSignUp(FString Method, bool bSuccess, FString CustomAttributesJSON = "");

	/** Event: Log In */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Answers")
	virtual void EventLogIn(FString Method, bool bSuccess, FString CustomAttributesJSON = "");

	/** @todo Event: Invite */
	/** @todo Event: Level Start */
	/** @todo Event: Level End */

	/** Event: Custom Event */
	UFUNCTION(BlueprintCallable, Category = "Crashlytics|Answers", meta = (DisplayName = "Custom Event"))
	virtual void EventCustom(FString EventName, FString CustomAttributesJSON = "");
};
