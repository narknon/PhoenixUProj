#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EUMGInputAction.h"
#include "EInputDeviceUsed.h"
#include "InputCheckpoint.h"
#include "Screen.h"
#include "SpellUnlockMiniGameData.h"
#include "SpellUnlockMiniGamePath.h"
#include "SpellMiniGameBase.generated.h"

class AActor;
class UDataTable;
class UMaterialInstance;
class UObject;
class USpellMiniGameSpark;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API USpellMiniGameBase : public UScreen {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_DELEGATE_OneParam(FAsyncUITextureLoadCallback, UTexture2D*, LoadedTex);
    DECLARE_DYNAMIC_DELEGATE_OneParam(FAsyncUIMaterialLoadCallback, UMaterialInstance*, LoadedMat);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreDrawTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpellMiniGameSpark* PlayerSpark;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpellMiniGameSpark* BadSpark;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D FailProgress;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* PlayerProxy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThreatChaserDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreDrawProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D PlayerSparkInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D LastTouchpadInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D SpellPathScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* SpellPathMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EUMGInputAction> PossiblePrompts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UDataTable> SpellMiniGameDataTable;
    
public:
    USpellMiniGameBase();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateButtonGlow(int32 Checkpoint, float GlowOpacity);
    
protected:
    UFUNCTION(BlueprintCallable)
    void StartMiniGameReset(const UObject* sender, const int32 RemoveWaitRequest);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetUseDefaultCamera(bool UseDefault);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetSpellIconImages(const TSoftObjectPtr<UTexture2D>& Icon, const TSoftObjectPtr<UTexture2D>& IconGlow, FVector2D Position);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ResetSparks();
    
public:
    UFUNCTION(BlueprintCallable)
    void ResetMiniGame();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PostMiniGameDataSet(FSpellUnlockMiniGameData Data);
    
    UFUNCTION(BlueprintCallable)
    void PauseMiniGame();
    
    UFUNCTION(BlueprintCallable)
    void PathTextureCallback(UTexture2D* MI);
    
    UFUNCTION(BlueprintCallable)
    void PathMaskCallback(UTexture2D* T2D);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUpdatePreDrawProgress(float NewProgress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUpdatePlayerProgress(FVector2D NewProgress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUpdateFailProgress(FVector2D NewProgress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartPressed();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartMiniGameReset();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpellTextureLoaded(UTexture2D* PathTexture);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpellMaskLoaded(UTexture2D* PathMask);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPreDrawComplete();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPathSplineSet(const FSpellUnlockMiniGamePath& Spline);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnMinigameSuccess();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnMinigameFullyLoaded();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnMinigameFailure(const UObject* sender);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputSuccess(int32 InputButtonIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputFailure(int32 InputIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputDeviceChanged(EInputDeviceUsed UsedInputDevice);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnExitPressed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnterInputWindow(int32 Checkpoint);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDestroySparks();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnButtonPreDraw(int32 ButtonIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBadSparkHitCheckpoint(int32 Checkpoint);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBadSparkEnterInputWindow(int32 Checkpoint);
    
    UFUNCTION(BlueprintCallable)
    void LogSpellMinigameData(const FString& LogData);
    
protected:
    UFUNCTION(BlueprintCallable)
    FVector2D GetProgressOnMask(const USpellMiniGameSpark* Spark);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetMiniGameName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsWaitingForStart() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsMiniGameActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsInInputWindow() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FInputCheckpoint> GetInputCheckpoints() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FInputCheckpoint GetCurrentCheckpointData() const;
    
    UFUNCTION(BlueprintCallable)
    void AddResetWaitRequest(const UObject* sender);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddInputButton(const FString& ButtonKey, FVector2D Position);
    
};

