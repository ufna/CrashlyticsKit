// Copyright 2016 Vladimir Alyamkin. All Rights Reserved.

#include "CrashlyticsKitPrivatePCH.h"

#if WITH_CRASHLYTICS && PLATFORM_ANDROID
	#include "Android/AndroidJNI.h"
	#include "Android/AndroidApplication.h"
	#include <android_native_app_glue.h>
#endif // WITH_CRASHLYTICS && PLATFORM_ANDROID

UCrashlyticsKit_Android::UCrashlyticsKit_Android(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

#if WITH_CRASHLYTICS && PLATFORM_ANDROID

void UCrashlyticsKit_Android::InitCrashlytics()
{
	UE_LOG(LogVftCrashlytics, Warning, TEXT("%s: Initialize Crashlytics Kit with Android SDK"), *VA_FUNC_LINE);

	if (bCrashlyticsInitialized)
	{
		UE_LOG(LogVftCrashlytics, Error, TEXT("%s: Trying to initialize Crashlytics when it's already been initialized!"), *VA_FUNC_LINE);
		return;
	}

	bCrashlyticsInitialized = true;
}

void UCrashlyticsKit_Android::ForceCrash()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ForceCrash", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
}

void UCrashlyticsKit_Android::ForceException()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ForceException", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
}

void UCrashlyticsKit_Android::SetUserIdentifier(FString UserIdentifier)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring IdentifierJava = Env->NewStringUTF(TCHAR_TO_UTF8(*UserIdentifier));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_SetUserIdentifier", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, IdentifierJava);
		Env->DeleteLocalRef(IdentifierJava);
	}
}

void UCrashlyticsKit_Android::SetUserEmail(FString UserEmail)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring UserEmailJava = Env->NewStringUTF(TCHAR_TO_UTF8(*UserEmail));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_SetUserEmail", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, UserEmailJava);
		Env->DeleteLocalRef(UserEmailJava);
	}
}

void UCrashlyticsKit_Android::SetUserName(FString UserName)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring UserNameJava = Env->NewStringUTF(TCHAR_TO_UTF8(*UserName));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_SetUserName", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, UserNameJava);
		Env->DeleteLocalRef(UserNameJava);
	}
}

void UCrashlyticsKit_Android::WriteLog(FString Log)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring LogJava = Env->NewStringUTF(TCHAR_TO_UTF8(*Log));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_WriteLog", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, LogJava);
		Env->DeleteLocalRef(LogJava);
	}
}

void UCrashlyticsKit_Android::WriteError(FString Log, int32 Code)
{
	
}

#endif // WITH_CRASHLYTICS && PLATFORM_ANDROID
