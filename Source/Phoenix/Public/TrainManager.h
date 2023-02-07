#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TrainManager.generated.h"

class ATrain;
class UTrainManager;
class UTrainNavigationSplineComponent;
class UTrainSettings;

UCLASS(Blueprintable, NotPlaceable)
class UTrainManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTrainSettings* TrainSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ATrain* TrainEngine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ATrain* CoalCar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ATrain*> PassengerCars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTrainNavigationSplineComponent* NavigationSpline;
    
public:
    UTrainManager();
    UFUNCTION(BlueprintCallable)
    void SetupTrain();
    
    UFUNCTION(BlueprintCallable)
    void SetTrainSpeed(float Speed);
    
    UFUNCTION(BlueprintCallable)
    void SetTrainPositionAlongTrack(FVector Position);
    
    UFUNCTION(BlueprintCallable)
    void SetTrainDistanceAlongTrack(float Distance);
    
    UFUNCTION(BlueprintCallable)
    static UTrainManager* Get();
    
    UFUNCTION(BlueprintCallable)
    void CleanupTrain();
    
};

