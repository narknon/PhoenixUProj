/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/

/*=============================================================================
	AkDrawPortalComponent.h:
=============================================================================*/
#pragma once

#if WITH_EDITOR
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "AkAcousticPortal.h"
#endif // WITH_EDITOR

#include "Components/PrimitiveComponent.h"
#include "AkDrawPortalComponent.generated.h"

/**
 *	Utility component for drawing a portal in a scene.
 */

UCLASS(collapsecategories, hidecategories = Object, editinlinenew, MinimalAPI)
class UDrawPortalComponent : public UPrimitiveComponent
{
	GENERATED_UCLASS_BODY()

#if WITH_EDITOR
public:
	void DrawPortalOutline(const FSceneView* View, FPrimitiveDrawInterface* PDI, FMeshElementCollector& Collector, int32 ViewIndex) const;
	const UAkPortalComponent* GetPortalParent() const;

private:
	virtual class FPrimitiveSceneProxy* CreateSceneProxy() override;
	virtual FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;

#endif // WITH_EDITOR
};