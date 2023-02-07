#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/PrimitiveComponent.h"
#include "ConjurationSurfaceMeshBuildParams.h"
#include "ConjurationGroundPlacementAreaComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UConjurationGroundPlacementAreaComponent : public UPrimitiveComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConjurationSurfaceMeshBuildParams BuildParams;
    
    UConjurationGroundPlacementAreaComponent();
    UFUNCTION(BlueprintCallable)
    bool DoesShapeFitBP(TArray<FVector> InVertices, FTransform InTransform);
    
    UFUNCTION(BlueprintCallable)
    void BuildMesh();
    
};

