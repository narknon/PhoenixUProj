#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=WindPointSourceComponent -FallbackName=WindPointSourceComponent
#include "EWindPointEnvelopeAffects.h"
#include "WindPointSourceComponent.h"
#include "WindSourceEnvelopeRetriggerDelegate.h"
#include "WindPointSourceWithEnvelopeComponent.generated.h"

class UWindEnvelopeController;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WIND_API UWindPointSourceWithEnvelopeComponent : public UWindPointSourceComponent {
    GENERATED_BODY()
public:
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
    UWindPointSourceWithEnvelopeComponent();
    UFUNCTION(BlueprintCallable)
    void UnsetEnvelopeAffects(EWindPointEnvelopeAffects InNewEnvelopeAffects);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void TestEnvelopeAffects(EWindPointEnvelopeAffects InNewEnvelopeAffects, bool& bIsSet) const;
    
    UFUNCTION(BlueprintCallable)
    void SetEnvelopeAffects(EWindPointEnvelopeAffects InNewEnvelopeAffects);
    
    UFUNCTION(BlueprintCallable)
    void SetEnvelope(const UWindEnvelopeController* InNewEnvelope);
    
    UFUNCTION(BlueprintCallable)
    void SetAutoKillAfterEnvelope(bool bInNewAutoKillAfterEnvelope);
    
    UFUNCTION(BlueprintCallable)
    void ClearEnvelopeAffects();
    
};

