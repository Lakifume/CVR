// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_HUD.h"
#include "Blueprint/GameViewportSubsystem.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Engine.h"
#include "Engine/LocalPlayer.h"

void ACPP_HUD::BeginPlay()
{
    Super::BeginPlay();

    if (GEngine)
    {
        if (UGameViewportSubsystem* ViewportSubsystem = GEngine->GetEngineSubsystem<UGameViewportSubsystem>())
        {
            WidgetAddedHandle   = ViewportSubsystem->OnWidgetAdded.AddUObject(this, &ACPP_HUD::WidgetAddedEvent);
            WidgetRemovedHandle = ViewportSubsystem->OnWidgetRemoved.AddUObject(this, &ACPP_HUD::WidgetRemovedEvent);
        }
    }
}

void ACPP_HUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (GEngine)
    {
        if (UGameViewportSubsystem* ViewportSubsystem = GEngine->GetEngineSubsystem<UGameViewportSubsystem>())
        {
            ViewportSubsystem->OnWidgetAdded.Remove(WidgetAddedHandle);
            ViewportSubsystem->OnWidgetRemoved.Remove(WidgetRemovedHandle);
        }
    }
    WidgetAddedHandle.Reset();
    WidgetRemovedHandle.Reset();

    Super::EndPlay(EndPlayReason);
}

void ACPP_HUD::WidgetAddedEvent(UWidget* Widget, ULocalPlayer* LocalPlayer)
{
    if (IsValid(Widget) && Widget->GetWorld() == GetWorld())
    {
        OnWidgetAdded.Broadcast(Cast<UUserWidget>(Widget), LocalPlayer);
    }
}

void ACPP_HUD::WidgetRemovedEvent(UWidget* Widget)
{
    if (IsValid(Widget) && Widget->GetWorld() == GetWorld())
    {
        OnWidgetRemoved.Broadcast(Cast<UUserWidget>(Widget));
    }
}
