// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "CrashlyticsKitSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UCrashlyticsKitSettings : public UObject
{
	GENERATED_UCLASS_BODY()
	
public:
	/** Simple way to turn on/off Crashlytics */
	UPROPERTY(Config, EditAnywhere)
	bool bEnableCrashlytics;

	/** Crashlitycs API Key */
	UPROPERTY(Config, EditAnywhere)
	FString CrashlyticsApiKey;

	/** If yes, you should call Initialize() function for Kit manually */
	UPROPERTY(Config, EditAnywhere)
	bool bCrashlyticsManualInit;
};
