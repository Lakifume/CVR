// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_AIController.h"
#include "BrainComponent.h"

void ACPP_AIController::PauseLogic()
{
    if (BrainComponent)
    {
        BrainComponent->PauseLogic(TEXT("Paused from Blueprint"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PauseLogic: No BrainComponent found on AIController."));
    }
}

void ACPP_AIController::ResumeLogic()
{
    if (BrainComponent)
    {
        BrainComponent->ResumeLogic(TEXT("Unpaused from Blueprint"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("ResumeLogic: No BrainComponent found on AIController."));
    }
}
