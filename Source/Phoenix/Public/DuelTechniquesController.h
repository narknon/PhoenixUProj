#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DuelTechniqueEncounterState.h"
#include "EncounterDuelTechniqueOverride.h"
#include "DuelTechniquesController.generated.h"

class UCombatVolumeGroup;
class UDuelTechnique;

UCLASS(Blueprintable)
class UDuelTechniquesController : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UDuelTechnique*> SelectedDuelTechniques;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UCombatVolumeGroup>, FDuelTechniqueEncounterState> StashedDuelTechniquesProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FEncounterDuelTechniqueOverride> SelectionOverridesCheat;
    
public:
    UDuelTechniquesController();
    UFUNCTION(BlueprintCallable)
    void OnCombatVolumeGroupDestroyed(const UCombatVolumeGroup* Group);
    
};

