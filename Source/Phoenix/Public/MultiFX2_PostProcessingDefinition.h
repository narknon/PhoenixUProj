#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/Scene.h"
#include "PostProcessingFXCurveSet.h"
#include "MultiFX2_PostProcessingDefinition.generated.h"

UCLASS(Blueprintable)
class UMultiFX2_PostProcessingDefinition : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostProcessSettings Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostProcessingFXCurveSet DefaultCurves;
    
    UMultiFX2_PostProcessingDefinition();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float LongestCurve(bool bKillOnly) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasCurves() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CurvesCanKill() const;
    
};

