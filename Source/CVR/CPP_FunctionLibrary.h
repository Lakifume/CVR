// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "Engine/EngineTypes.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CPP_FunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CVR_API UCPP_FunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "SceneComponent")
	static void UpdateComponentChildTransforms(USceneComponent* Component, int32 UpdateTransformFlags, ETeleportType Teleport);

};