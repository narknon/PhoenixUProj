#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/PrimitiveComponent.h"
#include "ConjurationSurfaceMeshBuildParams.h"
#include "ConjurationSurfaceMeshComponent.generated.h"

class UConjurationSurfaceShapeComponent;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UConjurationSurfaceMeshComponent : public UPrimitiveComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConjurationSurfaceMeshBuildParams BuildParams;
    
    UConjurationSurfaceMeshComponent();
    UFUNCTION(BlueprintCallable)
    void RemoveShapeComponent(UConjurationSurfaceShapeComponent* InShapeComponent);
    
    UFUNCTION(BlueprintCallable)
    void RemoveShape(int32 ShapeID);
    
    UFUNCTION(BlueprintCallable)
    void MoveShape(int32 ShapeID, FTransform InNewTransform);
    
    UFUNCTION(BlueprintCallable)
    bool DoesShapeFitBP(TArray<FVector> InVertices, FTransform InTransform);
    
    UFUNCTION(BlueprintCallable)
    bool DoesShapeComponentFitBP(const UConjurationSurfaceShapeComponent* InShape);
    
    UFUNCTION(BlueprintCallable)
    void BuildMesh();
    
    UFUNCTION(BlueprintCallable)
    TArray<int32> AddShapeComponent(UConjurationSurfaceShapeComponent* InShapeComponent, const FTransform& InTransform);
    
    UFUNCTION(BlueprintCallable)
    int32 AddShape(TArray<FVector> InVertices, FTransform InTransform);
    
};

