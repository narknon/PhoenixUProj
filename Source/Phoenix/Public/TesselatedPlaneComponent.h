#pragma once
#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "TesselatedPlaneComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTesselatedPlaneComponent : public UProceduralMeshComponent {
    GENERATED_BODY()
public:
    UTesselatedPlaneComponent();
    UFUNCTION(BlueprintCallable)
    void Construct();
    
};

