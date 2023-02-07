#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnLocationGroup.h"
#include "SpawnerActorSpawnedSignatureDelegate.h"
#include "SpawnerFinishedSpawningSignatureDelegate.h"
#include "SpawnerComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DESIGNERHELPER_API USpawnerComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FSpawnLocationGroup> SpawnLocationGroups;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnerActorSpawnedSignature OnActorSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnerFinishedSpawningSignature OnFinishedSpawning;
    
    USpawnerComponent();
    UFUNCTION(BlueprintCallable)
    void StopSpawning(const FName& GroupName);
    
    UFUNCTION(BlueprintCallable)
    void StartSpawning(const FName& GroupName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSpawning(const FName& GroupName) const;
    
    UFUNCTION(BlueprintCallable)
    void EventOnFinishedSpawningAtSpawnLocation(const FName& GroupName);
    
    UFUNCTION(BlueprintCallable)
    void EventOnActorSpawnedAtSpawnLocation(AActor* SpawnedActor, const FName& GroupName);
    
};

