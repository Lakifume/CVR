// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CPP_AIController.generated.h"

/**
 * 
 */
UCLASS()
class CVR_API ACPP_AIController : public AAIController
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "AI|Logic")
	void PauseLogic();

public:
	UFUNCTION(BlueprintCallable, Category = "AI|Logic")
	void ResumeLogic();
};
