#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "RaceGate.generated.h"

class ARace;

UCLASS(Blueprintable)
class ARaceGate : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARace* OwningRace;
    
public:
    ARaceGate();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRaceFinished(bool bNewBestTime);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnMissGate(bool& bSuccess);
    
    UFUNCTION(BlueprintCallable)
    void OnHitGate(bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnGateDeactivated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnGateActivated();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGateActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetSplineTrackOffset();
    
};

