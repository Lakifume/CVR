// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Spawnable.generated.h"

UCLASS()
class CVR_API ACPP_Spawnable : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, meta=(ExposeOnSpawn="true"))
	int32 SpawnGroup;
};
