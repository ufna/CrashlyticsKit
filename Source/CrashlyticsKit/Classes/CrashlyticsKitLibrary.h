// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "CrashlyticsKitLibrary.generated.h"


UCLASS()
class CRASHLYTICSKIT_API UCrashlyticsKitLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/** */
	UFUNCTION(BlueprintCallable, Category = CrashlyticsKit, BlueprintPure)
	static UCrashlyticsKitProxy* GetCrashlyticsProxy();
};
