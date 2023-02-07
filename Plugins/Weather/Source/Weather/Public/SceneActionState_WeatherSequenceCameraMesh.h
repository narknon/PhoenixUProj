#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequence.h"
#include "SceneActionState_WeatherSequenceCameraMesh.generated.h"

class UMaterialInstanceDynamic;
class UMeshComponent;
class UObject;

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceCameraMesh : public USceneActionState_WeatherSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMeshComponent* MeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> MIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bSpawned;
    
    USceneActionState_WeatherSequenceCameraMesh();
};

