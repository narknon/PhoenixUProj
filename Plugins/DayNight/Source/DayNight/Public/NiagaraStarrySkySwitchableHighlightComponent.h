#pragma once
#include "CoreMinimal.h"
#include "ESwitchableStarrySkyMode.h"
#include "NiagaraStarrySkyComponent.h"
#include "StarrySkyHighlightParameters.h"
#include "StarrySkyHighlights.h"
#include "NiagaraStarrySkySwitchableHighlightComponent.generated.h"

class UNiagaraSystem;
class UObject;
class UStarCatalog;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DAYNIGHT_API UNiagaraStarrySkySwitchableHighlightComponent : public UNiagaraStarrySkyComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStarCatalog* StarCatalog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FStarrySkyHighlights CurrentHighlights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HighlightModulate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FStarrySkyHighlightParameters CurrentHighlightParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* HighlightStarrySkySystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCameraAsOriginForHighlighting;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ESwitchableStarrySkyMode CurrentMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bHighlightForDefocus;
    
public:
    UNiagaraStarrySkySwitchableHighlightComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void SupportedHighlightConstellations(int32& Constellations);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool StarrySkyStartHighlightings(UObject* WorldContextObject, TArray<FName> HighlightConstellationNames, FName HighlightStarName, float InitialModulate);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool StarrySkyStartHighlighting(UObject* WorldContextObject, FName HighlightConstellationName, FName HighlightStarName, float InitialModulate);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool StarrySkySetHighlightParameters(UObject* WorldContextObject, FStarrySkyHighlightParameters Parameters);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool StarrySkySetHighlightModulate(UObject* WorldContextObject, float Modulate);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool StarrySkyEndHighlighting(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    void SetMode(ESwitchableStarrySkyMode Mode);
    
    UFUNCTION(BlueprintCallable)
    void SetHighlightSystem(UNiagaraSystem* NiagaraSystem);
    
    UFUNCTION(BlueprintCallable)
    void SetHighlightStar(FName StarName);
    
    UFUNCTION(BlueprintCallable)
    void SetHighlights(TArray<FName> ConstellationNames, FName StarName);
    
    UFUNCTION(BlueprintCallable)
    void SetHighlightConstellations(TArray<FName> ConstellationNames);
    
    UFUNCTION(BlueprintCallable)
    void SetHighlightConstellation(FName ConstellationName);
    
    UFUNCTION(BlueprintCallable)
    void SetHighlight(FName ConstellationName, FName StarName);
    
    UFUNCTION(BlueprintCallable)
    void LoadHighlightSystem(TSoftObjectPtr<UNiagaraSystem> NiagaraSystem);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHighlightLoadedSystem(TSoftObjectPtr<UNiagaraSystem> NiagaraSystem) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetMode(ESwitchableStarrySkyMode& Mode);
    
    UFUNCTION(BlueprintCallable)
    void ClearHighlights();
    
    UFUNCTION(BlueprintCallable)
    void ClearHighlightConstellations();
    
};

