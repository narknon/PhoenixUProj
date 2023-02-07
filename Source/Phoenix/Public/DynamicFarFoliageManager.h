#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldFoliageData.h"
#include "DynamicFarFoliageManager.generated.h"

class AInstancedFoliageActor;
class UFoliageInstancedStaticMeshComponent;

UCLASS(Blueprintable)
class ADynamicFarFoliageManager : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AInstancedFoliageActor* HostInstancedFoliageActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFoliageInstancedStaticMeshComponent*> HostInstancedFoliageComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> ComponentsInstanceCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorldFoliageData> WorldFoliageData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TotalInstancesCount;
    
    ADynamicFarFoliageManager();
    UFUNCTION(BlueprintCallable)
    void MainProcessIteration(float DeltaTime);
    
};

