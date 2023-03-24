#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TesselatedPlane.generated.h"

class UMaterialInstanceDynamic;
class UMaterialInterface;
class UTesselatedPlaneComponent;

UCLASS(Blueprintable)
class ATesselatedPlane : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTesselatedPlaneComponent* PlaneMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* PlaneMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDynamicMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* PlaneDynamicMaterial;
    
    ATesselatedPlane(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Construct();
    
};

