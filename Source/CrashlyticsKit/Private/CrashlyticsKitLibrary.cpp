// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#include "CrashlyticsKitPrivatePCH.h"
#include "CrashlyticsKitLibrary.h"

UCrashlyticsKitLibrary::UCrashlyticsKitLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UCrashlyticsKitProxy* UCrashlyticsKitLibrary::GetCrashlyticsProxy()
{
	return ICrashlyticsKit::Get().CrashlyticsKit;
}
