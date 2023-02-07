#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStatesBaseComponent.h"
#include "MaterialSwapRules.h"
#include "MaterialSwapMeshStatesFireAndForgetComponent.generated.h"

class AActor;
class UMaterialSwapMeshState;
class UMaterialSwapMeshStatesFireAndForgetComponent;

UCLASS(Blueprintable, Transient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MATERIALPERMUTER_API UMaterialSwapMeshStatesFireAndForgetComponent : public UMaterialSwapMeshStatesBaseComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> OwningActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapRules Rules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseRules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeChildren;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdateOnTick;
    
    UMaterialSwapMeshStatesFireAndForgetComponent();
    UFUNCTION(BlueprintCallable)
    void RestartMeshStates(const TArray<UMaterialSwapMeshState*>& MeshStates);
    
    UFUNCTION(BlueprintCallable)
    static UMaterialSwapMeshStatesFireAndForgetComponent* CreateMeshStatesFireAndForgetComponentRules(AActor* Owner, AActor* Target, const TArray<UMaterialSwapMeshState*>& MeshStates, FMaterialSwapRules UseRules, bool bAutoUpdate, FName Tag);
    
    UFUNCTION(BlueprintCallable)
    static UMaterialSwapMeshStatesFireAndForgetComponent* CreateMeshStatesFireAndForgetComponent(AActor* Owner, AActor* Target, const TArray<UMaterialSwapMeshState*>& MeshStates, bool bShouldIncludeChildren, bool bAutoUpdate, FName Tag);
    
};

