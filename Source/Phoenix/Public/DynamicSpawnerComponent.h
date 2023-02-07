#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnInfoGroup.h"
#include "DynamicSpawnerComponent.generated.h"

class AActor;
class ADynamicObjectVolume;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDynamicSpawnerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSpawnInfoGroup> SpawnObjectInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowRealTimeSpawnerGeneration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ADynamicObjectVolume* MyDynamicVolume;
    
    UDynamicSpawnerComponent();
    UFUNCTION(BlueprintCallable)
    void OnSpawnFinished(const FName& GroupName);
    
    UFUNCTION(BlueprintCallable)
    void OnActorSpawned(AActor* SpawnedActor, const FName& GroupName);
    
};

