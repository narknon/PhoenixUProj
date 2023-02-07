#pragma once
#include "CoreMinimal.h"
#include "NiagaraStarrySkyComponent.h"
#include "StarrySkyHighlightParameters.h"
#include "StarrySkyHighlights.h"
#include "NiagaraStarrySkyHighlightComponent.generated.h"

class UStarCatalog;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DAYNIGHT_API UNiagaraStarrySkyHighlightComponent : public UNiagaraStarrySkyComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStarCatalog* StarCatalog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStarrySkyHighlights Highlights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HighlightModulate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStarrySkyHighlightParameters HighlightParameters;
    
    UNiagaraStarrySkyHighlightComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void SupportedHighlightConstellations(int32& Constellations);
    
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
    void ClearHighlights();
    
    UFUNCTION(BlueprintCallable)
    void ClearHighlightConstellations();
    
};

