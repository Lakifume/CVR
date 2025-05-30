// Fill out your copyright notice in the Description page of Project Settings.

#include "Paper2DExposedData.h"
#include "UObject/UnrealType.h"
#include "Engine/Engine.h"
#include "/Epic Games/UE_5.4/Engine/Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSprite.h"


FSpriteRuntimeData UPaper2DExposedData::GetSpriteRuntimeData(UPaperSprite* Sprite)
{
    FSpriteRuntimeData SpriteData;

    if (Sprite)
    {

        //Texture that the sprite should be rendered with
        SpriteData.BakedTexture = Sprite->GetBakedTexture();


        //Get sprite render bounds
        FBoxSphereBounds RenderBounds = Sprite->GetRenderBounds();
        SpriteData.RenderBoundsOrigin = RenderBounds.Origin;
        SpriteData.RenderBoundsExtent = RenderBounds.BoxExtent;
        SpriteData.SpriteSizeUV = FVector2D ((RenderBounds.BoxExtent.X * 2.0f) / SpriteData.BakedTexture->GetSizeX(), (RenderBounds.BoxExtent.Z * 2.0f) / SpriteData.BakedTexture->GetSizeY());
        SpriteData.SpriteSizeWorld = FVector2D((RenderBounds.BoxExtent.X * 2.0f), (RenderBounds.BoxExtent.Z * 2.0f));


        //Get pixels per unit
        SpriteData.PixelsPerUnrealUnit = Sprite->GetPixelsPerUnrealUnit();
        

        //Gets the material applied originally
        SpriteData.DefaultMaterial = Sprite->GetDefaultMaterial();
        

        //Get the triiangle verts in world space and texture space
        SpriteData.RenderData = Sprite->BakedRenderData;
        
        // Estimate the pivot position
        FVector2D PivotPosition = FVector2D::ZeroVector;
        if (SpriteData.RenderData.Num() > 0)
        {
            for (const FVector4& Vertex : SpriteData.RenderData)
            {
                PivotPosition.X += Vertex.X;
                PivotPosition.Y += Vertex.Z; // Assuming Z is the correct component for Y-axis in 2D
            }

            PivotPosition /= SpriteData.RenderData.Num();
        }

        // Transform the pivot position from world coordinates to texture coordinates
        SpriteData.PivotTexturePosition = FVector2D(
            (PivotPosition.X - RenderBounds.Origin.X) / (RenderBounds.BoxExtent.X * 2.0f),
            (PivotPosition.Y - RenderBounds.Origin.Z) / (RenderBounds.BoxExtent.Z * 2.0f)
        );

        // Set the pivot position
        SpriteData.PivotWorldPosition = PivotPosition;

    }
    
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid Sprite reference."));
    }

    return SpriteData;
}
