#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequenceCameraMesh.h"
#include "SceneAction_WeatherSequenceCameraStaticMesh.generated.h"

class UStaticMesh;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceCameraStaticMesh : public USceneAction_WeatherSequenceCameraMesh {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> Mesh;
    
    USceneAction_WeatherSequenceCameraStaticMesh();
};

