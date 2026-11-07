// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CPP_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CVR_API UCPP_GameInstance : public UGameInstance
{
	GENERATED_BODY()

	TMap<FKey, EUINavigationAction> DefaultActionRules;

	TMap<FKey, EUINavigation> DefaultEventRules;

public:

	UFUNCTION(BlueprintCallable, Category = "Navigation")
	void SetNavigationEnabled(bool bEnabled);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Navigation")
	TMap<FKey, EUINavigationAction> GetNavigationActions();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Navigation")
	TMap<FKey, EUINavigation> GetNavigationDirections();

	UFUNCTION(BlueprintCallable, Category = "Navigation")
	void AddNavigationActionKeys(const FKey& Accept, const FKey& Back);

	UFUNCTION(BlueprintCallable, Category = "Navigation")
	void AddNavigationDirectionKeys(const FKey& Left, const FKey& Right, const FKey& Down, const FKey& Up);

	UFUNCTION(BlueprintCallable, Category = "Navigation")
	void ResetNavigationActionRules();

	UFUNCTION(BlueprintCallable, Category = "Navigation")
	void ResetNavigationDirectionRules();

	virtual void Init() override;

	virtual void Shutdown() override;
};
