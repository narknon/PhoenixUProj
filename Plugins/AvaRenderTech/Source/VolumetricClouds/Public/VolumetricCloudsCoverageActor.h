#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VolumetricCloudsCoverageActor.generated.h"

class UVolumetricCloudsCoverageComponent;

UCLASS(Blueprintable)
class VOLUMETRICCLOUDS_API AVolumetricCloudsCoverageActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVolumetricCloudsCoverageComponent* CoverageComponent;
    
    AVolumetricCloudsCoverageActor(const FObjectInitializer& ObjectInitializer);
};

