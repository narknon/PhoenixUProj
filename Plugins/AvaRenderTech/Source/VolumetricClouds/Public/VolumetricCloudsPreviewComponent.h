#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "EPreviewMode.h"
#include "VolumetricCloudsPreviewComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class VOLUMETRICCLOUDS_API UVolumetricCloudsPreviewComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPreviewMode PreviewMode;
    
    UVolumetricCloudsPreviewComponent();
};

