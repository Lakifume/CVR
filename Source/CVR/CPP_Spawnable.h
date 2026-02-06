// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Misc/Guid.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Spawnable.generated.h"

UCLASS()
class CVR_API ACPP_Spawnable : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, Category = "Spawn", meta=(ExposeOnSpawn="true"))
	FGuid ActorSpawnGuid;
};
