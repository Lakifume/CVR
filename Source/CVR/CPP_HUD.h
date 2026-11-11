// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/Widget.h"
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CPP_HUD.generated.h"

class UUserWidget;
class ULocalPlayer;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWidgetAdded, UUserWidget*, Widget, ULocalPlayer*, LocalPlayer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWidgetRemoved, UUserWidget*, Widget);

/**
 * 
 */
UCLASS()
class CVR_API ACPP_HUD : public AHUD
{
	GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category = "Viewport")
    FOnWidgetAdded OnWidgetAdded;

    UPROPERTY(BlueprintAssignable, Category = "Viewport")
    FOnWidgetRemoved OnWidgetRemoved;

protected:
    virtual void BeginPlay() override;

    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    void WidgetAddedEvent(UWidget* Widget, ULocalPlayer* LocalPlayer);

    void WidgetRemovedEvent(UWidget* Widget);

    FDelegateHandle WidgetAddedHandle;

    FDelegateHandle WidgetRemovedHandle;
};
