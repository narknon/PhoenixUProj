#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Components/SplineComponent.h"
#include "Construction_Interface.h"
#include "SplinePointEvents.h"
#include "TriggerEventDelegate.h"
#include "WorldEventSpline.generated.h"

class AActor;
class UBoxComponent;
class UPrimitiveComponent;
class UTextRenderComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UWorldEventSpline : public USplineComponent, public IConstruction_Interface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSplinePointEvents> SplinePointEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UBoxComponent*> SplineTriggerBoxes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTextRenderComponent*> EventTexts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TextOffset;
    
public:
    UWorldEventSpline();
    UFUNCTION(BlueprintCallable)
    void UnbindAllFromEvent(const FString& TriggerEventName);
    
    UFUNCTION(BlueprintCallable)
    void UnbindAll();
    
    UFUNCTION(BlueprintCallable)
    void Unbind(const FString& TriggerEventName, const FTriggerEvent Event);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void FindEventsAtSplinePoint(const int32 SplinePointIndex, const TArray<FSplinePointEvents>& InSplinePointEvents, TArray<FString>& OutFoundEventNames) const;
    
    UFUNCTION(BlueprintCallable)
    void EnableTriggerEvents(bool Enable);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Construct(const FTransform& Transform);
    
    UFUNCTION(BlueprintCallable)
    void Bind(const FString& TriggerEventName, const FTriggerEvent Event);
    
protected:
    UFUNCTION(BlueprintCallable)
    UTextRenderComponent* AddTextAtSplinePoint(const int32 SplinePointIndex, const TArray<FSplinePointEvents>& InSplinePointEvents, const FVector Offset, const USplineComponent* InSplineComponent);
    
    UFUNCTION(BlueprintCallable)
    UBoxComponent* AddBoxColliderAtSplinePoint(const int32 SplinePointIndex, const USplineComponent* InSplineComponent);
    
    
    // Fix for true pure virtual functions not being implemented
};

