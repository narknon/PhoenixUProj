#include "SaveReceivesWeatherDecalsStateMesh.h"

class AActor;
class UMeshComponent;
class USaveReceivesWeatherDecalsStateMesh;

void USaveReceivesWeatherDecalsStateMesh::SetState(bool ReceivesWeatherDecals, bool markRenderStateDirty) {
}

void USaveReceivesWeatherDecalsStateMesh::RestoreState(bool markRenderStateDirty) {
}

USaveReceivesWeatherDecalsStateMesh* USaveReceivesWeatherDecalsStateMesh::CreateMeshPool(AActor* Owner, bool ReceivesWeatherDecals) {
    return NULL;
}

USaveReceivesWeatherDecalsStateMesh* USaveReceivesWeatherDecalsStateMesh::CreateMeshAutoOwner(UMeshComponent* Mesh, bool ReceivesWeatherDecals, bool markRenderStateDirty) {
    return NULL;
}

USaveReceivesWeatherDecalsStateMesh* USaveReceivesWeatherDecalsStateMesh::CreateMesh(AActor* Owner, UMeshComponent* Mesh, bool ReceivesWeatherDecals, bool markRenderStateDirty) {
    return NULL;
}

void USaveReceivesWeatherDecalsStateMesh::AddMesh(UMeshComponent* Mesh, bool markRenderStateDirty) {
}

USaveReceivesWeatherDecalsStateMesh::USaveReceivesWeatherDecalsStateMesh() {
    this->bReceivesWeatherDecals = false;
}

