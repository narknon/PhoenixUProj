#pragma once
#include "CoreMinimal.h"
#include "PhoenixUserWidget.h"
#include "FancyProgressBar.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UFancyProgressBar : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayBeforeDecay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DecayDuration;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mGhostProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mPreDecayProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mPreDecayGhostProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mInactiveDelayTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mDecayTimer;
    
public:
    UFancyProgressBar();
    UFUNCTION(BlueprintCallable)
    void SetProgress(const float Progress);
    
    UFUNCTION(BlueprintCallable)
    void SetGhostProgress(const float GhostProgress);
    
    UFUNCTION(BlueprintCallable)
    void ResetProgress(const float Progress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ProgressChanged(const float Progress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GhostProgressChanged(const float GhostProgress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FilledFeedback();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DepletedFeedback();
    
};

