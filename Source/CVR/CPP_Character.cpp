// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Character.h"
#include "Components/CapsuleComponent.h"

void ACPP_Character::ForceUpdatePhysicsVolume()
{
    if (GetCapsuleComponent())
    {
        GetCapsuleComponent()->UpdatePhysicsVolume(true);
    }
}
