#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MaterialSwapMeshStatesAndData.h"
#include "MaterialSwapMeshStatesBaseComponent.generated.h"

class AActor;
class UMaterialSwapMeshStatesBaseComponent;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MATERIALPERMUTER_API UMaterialSwapMeshStatesBaseComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialSwapMeshStatesAndData MeshStatesAndData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName MeshStatesTag;
    
public:
    UMaterialSwapMeshStatesBaseComponent();
    UFUNCTION(BlueprintCallable)
    static void KillMaterialSwapMeshStatesComponent(UMaterialSwapMeshStatesBaseComponent* MaterialSwapMeshStatesComponent, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    static void KillAllMaterialSwapMeshStatesComponentsByTag(AActor* Target, FName Tag, int32& CountOfDestroyed);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void CountAllMaterialSwapMeshStatesComponentsByTag(AActor* Target, FName Tag, int32& ActiveCount);
    
};

