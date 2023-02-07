#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VolumetricCloudsPreviewActor.generated.h"

class UVolumetricCloudsPreviewComponent;

UCLASS(Blueprintable)
class VOLUMETRICCLOUDS_API AVolumetricCloudsPreviewActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVolumetricCloudsPreviewComponent* PreviewComponent;
    
    AVolumetricCloudsPreviewActor();
};

