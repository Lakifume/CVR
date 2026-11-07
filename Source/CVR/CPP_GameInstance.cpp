// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_GameInstance.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Application/NavigationConfig.h"
#include "RenderingThread.h"

void UCPP_GameInstance::SetNavigationEnabled(bool bEnabled)
{
    if (FSlateApplication::IsInitialized())
    {
        TSharedRef<FNavigationConfig> NavConfig = FSlateApplication::Get().GetNavigationConfig();
        NavConfig->bKeyNavigation = bEnabled;
    }
}

TMap<FKey, EUINavigationAction> UCPP_GameInstance::GetNavigationActions()
{
    TMap<FKey, EUINavigationAction> OutMap;
    if (FSlateApplication::IsInitialized())
    {
        TSharedRef<FNavigationConfig> NavConfig = FSlateApplication::Get().GetNavigationConfig();
        OutMap = NavConfig->KeyActionRules;
    }
    return OutMap;
}

TMap<FKey, EUINavigation> UCPP_GameInstance::GetNavigationDirections()
{
    TMap<FKey, EUINavigation> OutMap;
    if (FSlateApplication::IsInitialized())
    {
        TSharedRef<FNavigationConfig> NavConfig = FSlateApplication::Get().GetNavigationConfig();
        OutMap = NavConfig->KeyEventRules;
    }
    return OutMap;
}

void UCPP_GameInstance::AddNavigationActionKeys(const FKey& Accept, const FKey& Back)
{
    if (FSlateApplication::IsInitialized())
    {
        TSharedRef<FNavigationConfig> NavConfig = FSlateApplication::Get().GetNavigationConfig();
        NavConfig->KeyActionRules.Emplace(Accept, EUINavigationAction::Accept);
        NavConfig->KeyActionRules.Emplace(Back, EUINavigationAction::Back);
    }
}

void UCPP_GameInstance::AddNavigationDirectionKeys(const FKey& Left, const FKey& Right, const FKey& Down, const FKey& Up)
{
    if (FSlateApplication::IsInitialized())
    {
        TSharedRef<FNavigationConfig> NavConfig = FSlateApplication::Get().GetNavigationConfig();
        NavConfig->KeyEventRules.Emplace(Left, EUINavigation::Left);
        NavConfig->KeyEventRules.Emplace(Right, EUINavigation::Right);
        NavConfig->KeyEventRules.Emplace(Down, EUINavigation::Down);
        NavConfig->KeyEventRules.Emplace(Up, EUINavigation::Up);
    }
}

void UCPP_GameInstance::ResetNavigationActionRules()
{
    if (FSlateApplication::IsInitialized())
    {
        TSharedRef<FNavigationConfig> NavConfig = FSlateApplication::Get().GetNavigationConfig();
        NavConfig->KeyActionRules = DefaultActionRules;
    }
}

void UCPP_GameInstance::ResetNavigationDirectionRules()
{
    if (FSlateApplication::IsInitialized())
    {
        TSharedRef<FNavigationConfig> NavConfig = FSlateApplication::Get().GetNavigationConfig();
        NavConfig->KeyEventRules = DefaultEventRules;
    }
}

void UCPP_GameInstance::Init()
{
    Super::Init();

    if (FSlateApplication::IsInitialized())
    {
        TSharedRef<FNavigationConfig> NavConfig = FSlateApplication::Get().GetNavigationConfig();
        NavConfig->KeyEventRules.Emplace(EKeys::Gamepad_LeftStick_Left,  EUINavigation::Left);
        NavConfig->KeyEventRules.Emplace(EKeys::Gamepad_LeftStick_Right, EUINavigation::Right);
        NavConfig->KeyEventRules.Emplace(EKeys::Gamepad_LeftStick_Down,  EUINavigation::Down);
        NavConfig->KeyEventRules.Emplace(EKeys::Gamepad_LeftStick_Up,    EUINavigation::Up);
        NavConfig->KeyActionRules.Remove(EKeys::Gamepad_FaceButton_Bottom);
        NavConfig->KeyActionRules.Remove(EKeys::Gamepad_FaceButton_Right);
        NavConfig->KeyActionRules.Remove(EKeys::SpaceBar);
        NavConfig->KeyActionRules.Remove(EKeys::Enter);
        NavConfig->bAnalogNavigation = false;
        NavConfig->bTabNavigation = false;
        DefaultActionRules = NavConfig->KeyActionRules;
        DefaultEventRules = NavConfig->KeyEventRules;
    }
}

void UCPP_GameInstance::Shutdown()
{
    FlushRenderingCommands();
    Super::Shutdown();
}
