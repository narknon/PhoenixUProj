#include "MaterialPermuter.h"

class AActor;
class UMaterialInterface;
class UMeshComponent;
class UObject;

void UMaterialPermuter::MaterialPermuterSetBaseMaterial(UMeshComponent* Mesh, int32 Index, UMaterialInterface* Material, bool& Success) {
}

void UMaterialPermuter::MaterialPermuterPrepareSetBaseMaterials(UMeshComponent* Mesh, bool& Success) {
}

void UMaterialPermuter::MaterialPermuterIsMeshSwapped(UMeshComponent* Mesh, bool& bIsSwapped) {
}

void UMaterialPermuter::MaterialPermuterGetMeshSwapOwner(UMeshComponent* Mesh, UObject*& SwapOwner) {
}

void UMaterialPermuter::MaterialPermuterClearMeshSwap(UMeshComponent* Mesh, bool& bSuccess) {
}

void UMaterialPermuter::MaterialPermuterClearAllSwaps(AActor* Actor, bool& bSuccess) {
}

UMaterialPermuter::UMaterialPermuter() {
}

