#pragma once
#include "CoreMinimal.h"
#include "AnimatedCreditEntry.h"
#include "CreditEntry.h"
#include "Screen.h"
#include "PhoenixCreditsScreen.generated.h"

class UCanvasPanel;
class UDataTable;
class UPhoenixCreditEntryWidget;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UPhoenixCreditsScreen : public UScreen {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UDataTable> CreditsDataTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RollAnimationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeBetweenEntries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* CreditsCanvasPanel;
    
private:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCreditEntry> AllCreditEntries;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAnimatedCreditEntry> AnimatedCreditEntries;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool DataTableLoaded;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool CreditsRolling;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool LastEntryReached;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float DurationMultiplier;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 CreditsEntryCounter;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float TotalRollTime;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float TimeToNextEntry;
    
public:
    UPhoenixCreditsScreen();
    UFUNCTION(BlueprintCallable)
    void StartRollingCredits();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UPhoenixCreditEntryWidget* CreateCreditEntry(const FCreditEntry CreditEntry);
    
};

