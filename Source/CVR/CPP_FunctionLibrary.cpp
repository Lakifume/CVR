// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FunctionLibrary.h"

void UCPP_FunctionLibrary::UpdateComponentChildTransforms(USceneComponent* Component, int32 UpdateTransformFlags, ETeleportType Teleport)
{
	if (Component)
	{
		EUpdateTransformFlags Flags = static_cast<EUpdateTransformFlags>(UpdateTransformFlags);
		Component->UpdateChildTransforms(Flags, Teleport);
	}
}
