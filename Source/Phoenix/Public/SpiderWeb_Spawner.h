#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "SpiderWeb_Spawner.generated.h"

class ADynamicObjectVolume;
class UPrimitiveComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ASpiderWeb_Spawner : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ADynamicObjectVolume* SpawnerVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyOnSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString IgnoreTypeName;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBurning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFrozen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpawnGroupName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpawnNum;
    
public:
    ASpiderWeb_Spawner();
private:
    UFUNCTION(BlueprintCallable)
    bool WebThaw();
    
    UFUNCTION(BlueprintCallable)
    void WebHit();
    
    UFUNCTION(BlueprintCallable)
    void WebFreeze();
    
    UFUNCTION(BlueprintCallable)
    void WebBurn();
    
    UFUNCTION(BlueprintCallable)
    void SpawnSpiders();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetSpawner(ADynamicObjectVolume* newSpawner);
    
private:
    UFUNCTION(BlueprintCallable)
    bool OnSpawnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    bool OnSpawnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSpider(AActor* checkActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetRelativeTransform(UStaticMeshComponent* StaticMesh, FVector FireLocation);
    
};

