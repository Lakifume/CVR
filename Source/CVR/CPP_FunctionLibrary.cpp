// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FunctionLibrary.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFileManager.h"

void UCPP_FunctionLibrary::UpdateComponentChildTransforms(USceneComponent* Component, int32 UpdateTransformFlags, ETeleportType Teleport)
{
	if (Component)
	{
		EUpdateTransformFlags Flags = static_cast<EUpdateTransformFlags>(UpdateTransformFlags);
		Component->UpdateChildTransforms(Flags, Teleport);
	}
}

bool UCPP_FunctionLibrary::ReadExternalBinaryFile(const FString& AbsolutePath, TArray<uint8>& OutBytes)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	if (!PlatformFile.FileExists(*AbsolutePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to read binary file, path does not exist: %s"), *AbsolutePath);
		return false;
	}

	if (FFileHelper::LoadFileToArray(OutBytes, *AbsolutePath))
	{
		UE_LOG(LogTemp, Log, TEXT("Successfully loaded %d bytes from: %s"), OutBytes.Num(), *AbsolutePath);
		return true;
	}

	UE_LOG(LogTemp, Error, TEXT("Failed to read binary file, could not load data from: %s"), *AbsolutePath);
	return false;
}
