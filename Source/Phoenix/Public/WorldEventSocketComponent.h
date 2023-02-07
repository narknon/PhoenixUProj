#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/SceneComponent.h"
#include "GameplayTagContainer.h"
#include "Construction_Interface.h"
#include "WorldEventSocketComponent.generated.h"

class UShapeComponent;
class USplineComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UWorldEventSocketComponent : public USceneComponent, public IConstruction_Interface {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UShapeComponent* ShapeComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer SocketDescriptors;
    
public:
    UWorldEventSocketComponent();
    UFUNCTION(BlueprintCallable)
    void SetSocketOccupied(bool bInOccupied);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSocketOccupied();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USplineComponent* GetSplineComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTagContainer GetSocketDescriptors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UShapeComponent* GetShapeComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Construct(const FTransform& Transform);
    
    
    // Fix for true pure virtual functions not being implemented
};

