#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "GameFramework/Actor.h"
#include "ConjurationSurfaceMeshBuildParams.h"
#include "ConjurationSurfaceMeshActor.generated.h"

class UBoxComponent;
class UConjurationSurfaceMeshComponent;

UCLASS(Blueprintable)
class AConjurationSurfaceMeshActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* VolumeComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UConjurationSurfaceMeshComponent* SurfaceMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SurfaceTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConjurationSurfaceMeshBuildParams BuildParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo RequiredLockID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo ProhibitedLockID;
    
    AConjurationSurfaceMeshActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void BuildMesh();
    
};

