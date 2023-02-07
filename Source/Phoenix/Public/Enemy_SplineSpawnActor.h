#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "MultiFX2Handle.h"
#include "Enemy_SplineSpawnActorData.h"
#include "SpawnArrivedEventDelegate.h"
#include "SpawnDoneEventDelegate.h"
#include "Enemy_SplineSpawnActor.generated.h"

class UMultiFX2_Base;

UCLASS(Blueprintable)
class AEnemy_SplineSpawnActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_SplineSpawnActorData Data;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DestroyDelayTime;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnArrivedEvent ArrivedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnDoneEvent DoneEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> ArrivedFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> LandingFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFX2Handle ArrivedFX2Handle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFX2Handle LandingFXHandle2;
    
    AEnemy_SplineSpawnActor();
    UFUNCTION(BlueprintCallable)
    void StartLandingVFX(FVector StartLocation);
    
    UFUNCTION(BlueprintCallable)
    void StartArrivedVFX();
    
    UFUNCTION(BlueprintCallable)
    void Start();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasArrived() const;
    
    UFUNCTION(BlueprintCallable)
    void BroadcastDone(AActor* pActor);
    
    UFUNCTION(BlueprintCallable)
    void BroadcastArrived(AActor* pActor, FVector Loc);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ApplyStopFX();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ApplyStartFX();
    
};

