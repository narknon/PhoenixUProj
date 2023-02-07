#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileableFrameActor.generated.h"

class UInstancedStaticMeshComponent;
class USceneComponent;
class UStaticMesh;

UCLASS(Blueprintable)
class ATileableFrameActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* InstRectTileMid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* InstRectTileCorner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* RectangularFrameTile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* RectangularFrameCorner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HorizontalTileCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 VerticalTileCount;
    
    ATileableFrameActor();
    UFUNCTION(BlueprintCallable)
    void MakeFrame();
    
};

