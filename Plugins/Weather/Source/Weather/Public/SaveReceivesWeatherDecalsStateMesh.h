#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SaveReceivesWeatherDecalsStateMesh.generated.h"

class AActor;
class UMeshComponent;
class USaveReceivesWeatherDecalsStateMesh;

UCLASS(Blueprintable, Transient)
class WEATHER_API USaveReceivesWeatherDecalsStateMesh : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UMeshComponent>, bool> SaveMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bReceivesWeatherDecals;
    
    USaveReceivesWeatherDecalsStateMesh();
    UFUNCTION(BlueprintCallable)
    void SetState(bool ReceivesWeatherDecals, bool markRenderStateDirty);
    
    UFUNCTION(BlueprintCallable)
    void RestoreState(bool markRenderStateDirty);
    
    UFUNCTION(BlueprintCallable)
    static USaveReceivesWeatherDecalsStateMesh* CreateMeshPool(AActor* Owner, bool ReceivesWeatherDecals);
    
    UFUNCTION(BlueprintCallable)
    static USaveReceivesWeatherDecalsStateMesh* CreateMeshAutoOwner(UMeshComponent* Mesh, bool ReceivesWeatherDecals, bool markRenderStateDirty);
    
    UFUNCTION(BlueprintCallable)
    static USaveReceivesWeatherDecalsStateMesh* CreateMesh(AActor* Owner, UMeshComponent* Mesh, bool ReceivesWeatherDecals, bool markRenderStateDirty);
    
    UFUNCTION(BlueprintCallable)
    void AddMesh(UMeshComponent* Mesh, bool markRenderStateDirty);
    
};

