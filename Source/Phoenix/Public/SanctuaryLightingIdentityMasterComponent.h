#pragma once
#include "CoreMinimal.h"
#include "EphemerisComputer.h"
#include "TimeController.h"
#include "Components/ActorComponent.h"
#include "ESanctuaryIdentity.h"
#include "OnLightingIdentityBlendUpdateDelegate.h"
#include "OnLightingIdentityChangedDelegate.h"
#include "SanctuaryLightingIdentityMasterComponent.generated.h"

class UObject;
class USanctuaryIdentitySettingsAsset;
class USanctuaryLightingIdentityMasterComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API USanctuaryLightingIdentityMasterComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLightingIdentityChanged OnLightingIdentityChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLightingIdentityBlendUpdate OnLightingIdentityBlendUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESanctuaryIdentity, USanctuaryIdentitySettingsAsset*> IdentitySettings;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ESanctuaryIdentity CurrentIdentity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ESanctuaryIdentity PreviousIdentity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimeController TimeController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEphemerisComputer EphemerisComputer;
    
public:
    USanctuaryLightingIdentityMasterComponent();
    UFUNCTION(BlueprintCallable)
    void SetIdentity(ESanctuaryIdentity InNewIdentity, float InBlendDuration);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ESanctuaryIdentity GetPreviousIdentity() const;
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static USanctuaryLightingIdentityMasterComponent* GetLightingIdentityMaster(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetIdentityBlendWeight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ESanctuaryIdentity GetCurrentIdentity() const;
    
};

