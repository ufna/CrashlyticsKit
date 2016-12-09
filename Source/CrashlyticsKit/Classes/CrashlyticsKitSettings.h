// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "CrashlyticsKitSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UCrashlyticsKitSettings : public UObject
{
	GENERATED_UCLASS_BODY()
	
public:
	/** Crashlitycs API Key */
	UPROPERTY(Config, EditAnywhere, meta = (DisplayName = "Crashlytics API Key"))
	FString CrashlyticsApiKey;
};
