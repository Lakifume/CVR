// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "CPP_Character.generated.h"

/**
 * 
 */
UCLASS()
class CVR_API ACPP_Character : public APaperZDCharacter
{
	GENERATED_BODY()

public:
    // Expose UpdatePhysicsVolume to Blueprints
    UFUNCTION(BlueprintCallable, Category = "Physics")
    void ForceUpdatePhysicsVolume();
};
