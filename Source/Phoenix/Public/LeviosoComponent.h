#pragma once
#include "CoreMinimal.h"
#include "LeviosoData.h"
#include "StateEffectComponent.h"
#include "LeviosoComponent.generated.h"

class AActor;
class AMunitionType_Base;
class UCurveFloat;
class UCurveVector;
class UPrimitiveComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ULeviosoComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLeviosoData LeviosoData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AMunitionType_Base* ActiveMunition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* SavedPhysMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* SavedHoverTargetOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveVector* SavedHoverTargetRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> IgnoreActors;
    
public:
    ULeviosoComponent();
    UFUNCTION(BlueprintCallable)
    void SetIgnoreActors(TArray<AActor*> i_Ingores);
    
    UFUNCTION(BlueprintCallable)
    void SetFloorHeight(float Height);
    
    UFUNCTION(BlueprintCallable)
    void SetData(FLeviosoData InData);
    
};

