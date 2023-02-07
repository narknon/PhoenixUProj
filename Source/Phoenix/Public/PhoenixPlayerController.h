#pragma once
#include "CoreMinimal.h"
#include "Biped_PlayerController.h"
#include "Templates/SubclassOf.h"
#include "PhoenixPlayerController.generated.h"

class APhoenixHUD;
class UEncounterTracker;
class ULEDEffects;
class ULEDFadeEffect;
class UTriggerEffectManager;

UCLASS(Blueprintable)
class APhoenixPlayerController : public ABiped_PlayerController {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTriggerEffectManager* TriggerEffectManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULEDEffects* LEDEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ULEDFadeEffect> PlayerHouseLEDFadeEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ULEDFadeEffect> DamageTakenLEDEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULEDFadeEffect* pPlayerHouseLEDFadeEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULEDFadeEffect* pDamageTakenLEDEffect;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhoenixHUD* m_pPhoenixHUD;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UEncounterTracker* m_pEncounterTracker;
    
public:
    APhoenixPlayerController();
    UFUNCTION(BlueprintCallable)
    void MapCaptureStart();
    
};

