// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "/Epic Games/UE_5.4/Engine/Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSprite.h"
#include "Paper2DExposedData.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType)
struct FSpriteRuntimeData
{
	GENERATED_BODY()

	//Texture that the sprite should be rendered with
	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Sprite Texture", Keywords = "Source Texture Sprite"), Category = "Paper2DExposedData")
	UTexture2D* BakedTexture;

	//Size of sprite in texture space
	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Sprite Source UV", Keywords = "Source Texture Sprite"), Category = "Paper2DExposedData")
	FVector2D SpriteSizeUV;

	//Size of sprite in world space
	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Sprite Source Dimensions", Keywords = "Source Texture Sprite"), Category = "Paper2DExposedData")
	FVector2D SpriteSizeWorld;


	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Sprite Render Bounds Origin", Keywords = "Source Texture Sprite"), Category = "Paper2DExposedData")
	FVector RenderBoundsOrigin;


	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Sprite Render Bounds Extent", Keywords = "Source Texture Sprite"), Category = "Paper2DExposedData")
	FVector RenderBoundsExtent;


	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Sprite Pixels Per Unreal Unit", Keywords = "Source Texture Sprite"), Category = "Paper2DExposedData")
	float PixelsPerUnrealUnit;


	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Sprite Default Material", Keywords = "Source Texture Sprite"), Category = "Paper2DExposedData")
	UMaterialInterface* DefaultMaterial;


	//Provides the location of the pivot point in texture space
	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Sprite Pivot Texture Postion", Keywords = "Source Texture Sprite"), Category = "Paper2DExposedData")
	FVector2D PivotTexturePosition;

	// Calculated pivot position from Render Bounds Extent and Origin
	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Sprite Pivot World Position", Keywords = "Source Texture Sprite"), Category = "Paper2DExposedData")
	FVector2D PivotWorldPosition;

	// Baked render data (triangle vertices, stored as XY UV tuples)
	// XY is the XZ position in world space, relative to the pivot
	// UV is normalized (0..1)
	// There should always be a multiple of three elements in this array
	UPROPERTY(BlueprintReadOnly, meta = (DisplayName = "Sprite Render Data", Keywords = "Source Texture Sprite"), Category = "Paper2DExposedData")
	TArray<FVector4> RenderData;

};



UCLASS()
class UPaper2DExposedData : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Paper2DExposedData")
	static FSpriteRuntimeData GetSpriteRuntimeData(UPaperSprite* Sprite);

	
};

