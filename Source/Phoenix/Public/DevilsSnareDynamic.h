#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "DevilsSnareDynamic.generated.h"

class UPrimitiveComponent;
class USphereComponent;

UCLASS(Blueprintable)
class ADevilsSnareDynamic : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* SphereComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> LightActorsInArea;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bPlayerIsUsingLumos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SphereRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OnFireRadiusExtension;
    
    ADevilsSnareDynamic(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool UnslowPlayer();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TickDeactivated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TickActivated();
    
    UFUNCTION(BlueprintCallable)
    bool SlowPlayer(float SpeedLimit);
    
    UFUNCTION(BlueprintCallable)
    void PlayerLumosStart();
    
    UFUNCTION(BlueprintCallable)
    void PlayerLumosEnd();
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapSphereEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapSphereBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool FindClosestLightSourcePos(const FVector& SnarePos, FVector& OutPos);
    
private:
    UFUNCTION(BlueprintCallable)
    void BeginPlayDelayed();
    
};

