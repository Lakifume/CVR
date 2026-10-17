// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_GameInstance.h"
#include "RenderingThread.h"

void UCPP_GameInstance::Shutdown()
{
    FlushRenderingCommands();
    Super::Shutdown();
}
