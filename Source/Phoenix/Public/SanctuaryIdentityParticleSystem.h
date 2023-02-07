#pragma once
#include "CoreMinimal.h"
#include "ESanctuaryIdentity.h"
#include "StreamingPlaceholderBase.h"
#include "SanctuaryIdentityParticleSystem.generated.h"

class UParticleSystem;
class UParticleSystemComponent;

UCLASS(Blueprintable)
class ASanctuaryIdentityParticleSystem : public AStreamingPlaceholderBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESanctuaryIdentity, TSoftObjectPtr<UParticleSystem>> IdentityOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UParticleSystem> DefaultParticleSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoSwapWhenIdentityChanges;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* ParticleSystemComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* LoadedAsset;
    
public:
    ASanctuaryIdentityParticleSystem();
protected:
    UFUNCTION(BlueprintCallable)
    void OnIdentityChanged(ESanctuaryIdentity OldIdentity, ESanctuaryIdentity NewIdentity);
    
};

