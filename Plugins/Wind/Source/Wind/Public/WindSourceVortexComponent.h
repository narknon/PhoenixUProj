#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=WindSourceComponentBaseData -FallbackName=WindSourceComponentBaseData
#include "EWindVortexEnvelopeAffects.h"
#include "WindSourceComponentBaseData.h"
#include "WindSourceEnvelopeRetriggerDelegate.h"
#include "WindSourceVortexComponent.generated.h"

class UWindEnvelopeController;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WIND_API UWindSourceVortexComponent : public UWindSourceComponentBaseData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Height;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float InnerRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Strength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Speed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWindEnvelopeController* Envelope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    int32 EnvelopeAffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bAutoKillAfterEnvelope;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWindSourceEnvelopeRetrigger TriggerEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float StartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bActive;
    
public:
    UWindSourceVortexComponent();
    UFUNCTION(BlueprintCallable)
    void UnsetEnvelopeAffects(EWindVortexEnvelopeAffects InNewEnvelopeAffects);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void TestEnvelopeAffects(EWindVortexEnvelopeAffects InNewEnvelopeAffects, bool& bIsSet) const;
    
    UFUNCTION(BlueprintCallable)
    void SetStrength(float InNewStrength);
    
    UFUNCTION(BlueprintCallable)
    void SetSpeed(float InNewSpeed);
    
    UFUNCTION(BlueprintCallable)
    void SetRadius(float InNewRadius);
    
    UFUNCTION(BlueprintCallable)
    void SetInnerRadius(float InNewInnerRadius);
    
    UFUNCTION(BlueprintCallable)
    void SetHeight(float InNewHeight);
    
    UFUNCTION(BlueprintCallable)
    void SetEnvelopeAffects(EWindVortexEnvelopeAffects InNewEnvelopeAffects);
    
    UFUNCTION(BlueprintCallable)
    void SetEnvelope(const UWindEnvelopeController* InNewEnvelope);
    
    UFUNCTION(BlueprintCallable)
    void SetAutoKillAfterEnvelope(bool bInNewAutoKillAfterEnvelope);
    
    UFUNCTION(BlueprintCallable)
    void ClearEnvelopeAffects();
    
};

