#include "NativeSplitterBlueprintLibrary.h"

class UActorComponent;
class UStaticMeshComponent;

bool UNativeSplitterBlueprintLibrary::RequiresOverrideVertexColorsFixup(UStaticMeshComponent* StaticMeshComponent) {
    return false;
}

bool UNativeSplitterBlueprintLibrary::RemoveInstanceVertexColorsFromLOD(UStaticMeshComponent* StaticMeshComponent, int32 LODToRemoveColorsFrom) {
    return false;
}

bool UNativeSplitterBlueprintLibrary::RemoveInstanceVertexColors(UStaticMeshComponent* StaticMeshComponent) {
    return false;
}

bool UNativeSplitterBlueprintLibrary::FixupOverrideColorsIfNecessary(UStaticMeshComponent* StaticMeshComponent, bool bRebuildingStaticMesh) {
    return false;
}

bool UNativeSplitterBlueprintLibrary::CopyProperties(UActorComponent* SourceComponent, UActorComponent* TargetComponent) {
    return false;
}

bool UNativeSplitterBlueprintLibrary::CopyInstanceVertexColorsIfCompatible(UStaticMeshComponent* SourceComponent, UStaticMeshComponent* TargetComponent) {
    return false;
}

bool UNativeSplitterBlueprintLibrary::CachePaintedDataIfNecessary(UStaticMeshComponent* StaticMeshComponent) {
    return false;
}

UNativeSplitterBlueprintLibrary::UNativeSplitterBlueprintLibrary() {
}

