// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Character.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void ACPP_Character::ForceUpdatePhysicsVolume()
{
    if (GetCapsuleComponent())
    {
        GetCapsuleComponent()->UpdatePhysicsVolume(true);
    }
}

void ACPP_Character::SetJumpCurrentCount(int32 NewCount)
{
    JumpCurrentCount = NewCount;
}

void ACPP_Character::ResetJumpState()
{
    if (GetCharacterMovement() && !GetCharacterMovement()->NavAgentProps.bCanFly && GetCharacterMovement()->IsFlying())
    {
        bPressedJump = false;
        bWasJumping = false;
        JumpKeyHoldTime = 0.0f;
        JumpForceTimeRemaining = 0.0f;
    }
    else
    {
        Super::ResetJumpState();
    }
}
