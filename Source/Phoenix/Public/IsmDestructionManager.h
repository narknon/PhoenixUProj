#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "IsmDesInstance.h"
#include "IsmDestructionManager.generated.h"

class AActor;
class AMunitionType_Base;
class UIsmDestructionManager;
class UStaticMesh;

UCLASS(Blueprintable)
class UIsmDestructionManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FIsmDesInstance> PendingInstances;
    
public:
    UIsmDestructionManager();
    UFUNCTION(BlueprintCallable)
    void RegisterMapping(const TSoftObjectPtr<UStaticMesh>& InStaticMesh, const TSoftClassPtr<AActor>& InDestructibleActor);
    
    UFUNCTION(BlueprintCallable)
    static UIsmDestructionManager* Get();
    
    UFUNCTION(BlueprintCallable)
    bool ConvertInstanceIfNecessary(AActor* HitTarget, const FBox& Box, float Damage, const FHitResult& HitResult, AActor* Instigator, AMunitionType_Base* Munition);
    
};

