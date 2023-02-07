#include "ConjurationSurfaceMeshComponent.h"

class UConjurationSurfaceShapeComponent;

void UConjurationSurfaceMeshComponent::RemoveShapeComponent(UConjurationSurfaceShapeComponent* InShapeComponent) {
}

void UConjurationSurfaceMeshComponent::RemoveShape(int32 ShapeID) {
}

void UConjurationSurfaceMeshComponent::MoveShape(int32 ShapeID, FTransform InNewTransform) {
}

bool UConjurationSurfaceMeshComponent::DoesShapeFitBP(TArray<FVector> InVertices, FTransform InTransform) {
    return false;
}

bool UConjurationSurfaceMeshComponent::DoesShapeComponentFitBP(const UConjurationSurfaceShapeComponent* InShape) {
    return false;
}

void UConjurationSurfaceMeshComponent::BuildMesh() {
}

TArray<int32> UConjurationSurfaceMeshComponent::AddShapeComponent(UConjurationSurfaceShapeComponent* InShapeComponent, const FTransform& InTransform) {
    return TArray<int32>();
}

int32 UConjurationSurfaceMeshComponent::AddShape(TArray<FVector> InVertices, FTransform InTransform) {
    return 0;
}

UConjurationSurfaceMeshComponent::UConjurationSurfaceMeshComponent() {
}

