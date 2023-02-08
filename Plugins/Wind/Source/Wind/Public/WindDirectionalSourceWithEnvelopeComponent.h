#pragma once
#include "CoreMinimal.h"
#include "Components/WindDirectionalSourceComponent.h"
#include "WindSourceEnvelopeRetriggerDelegate.h"
#include "WindDirectionalSourceWithEnvelopeComponent.generated.h"

class UWindEnvelopeController;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WIND_API UWindDirectionalSourceWithEnvelopeComponent : public UWindDirectionalSourceComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWindEnvelopeController* Envelope;
    
    /*UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    EWindDirectionalEnvelopeAffects EnvelopeAffects;*/
    
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
    UWindDirectionalSourceWithEnvelopeComponent();
    /*UFUNCTION(BlueprintCallable)
    void SetEnvelopeAffects(EWindDirectionalEnvelopeAffects InNewEnvelopeAffects);*/
    
    UFUNCTION(BlueprintCallable)
    void SetEnvelope(const UWindEnvelopeController* InNewEnvelope);
    
    UFUNCTION(BlueprintCallable)
    void SetAutoKillAfterEnvelope(bool bInNewAutoKillAfterEnvelope);
    
};

