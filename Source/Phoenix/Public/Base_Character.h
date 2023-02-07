#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "Ambulatory_Character.h"
#include "Moddable.h"
#include "ClothBudgeterInterface.h"
#include "LODBudgeterInterface.h"
#include "SignificanceInterface.h"
#include "SceneRigParticipant.h"
#include "EStandardManagedPriority.h"
#include "Base_Character_Interface.h"
#include "CharacterShutdownProvider_Interface.h"
#include "MultiFXHandle.h"
#include "OnSpellSuccessDelegate.h"
#include "QueryFinishedData.h"
#include "SocialReasoning_Interface.h"
#include "SocialResponse.h"
#include "Base_Character.generated.h"

class ASocialReasoning;
class UCharacterStateInfo;
class UClothSitComponent;
class UObject;
class UObjectStateInfo;
class UPhoenixManagedCharacter;
class UTraversalSettings;

UCLASS(Blueprintable)
class ABase_Character : public AAmbulatory_Character, public IBase_Character_Interface, public ISocialReasoning_Interface, public ISignificanceInterface, public ILODBudgeterInterface, public IClothBudgeterInterface, public IModdable, public ISceneRigParticipant, public ICharacterShutdownProvider_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixManagedCharacter* ManagedCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFXHandle ScratchFXHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSpellSuccess OnSpellSuccess;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTraversalSettings* TraversalSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShoulderFixupAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeOutAlphaFactor;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCharacterStateInfo* CachedCharacterStateInfo;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UClothSitComponent* ClothSitComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultMaxHeight;
    
public:
    ABase_Character();
    UFUNCTION(BlueprintCallable)
    void StartSettingTargetableByAiState(bool bTargetable, EStandardManagedPriority Priority, const UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingMaxHeightValue(float bValue, EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingMaxHeightEnabledValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingLODOverride(int32 LODOverride, UObject* Provider);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RunEQS_FindStations(EEnvQueryRunMode::Type RunMode, FQueryFinishedData& QueryFinishedDelegate);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RunEQS_FindSocialReasonings(EEnvQueryRunMode::Type RunMode, FQueryFinishedData& QueryFinishedDelegate);
    
    UFUNCTION(BlueprintCallable)
    void ReRegisterWithSignificanceManager();
    
    UFUNCTION(BlueprintCallable)
    void ReleaseFocusFromScriptedBehavior(FName InIdentifyingName);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void PlayerSighted();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool Nevermind();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetableByAi() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool Goodbye();
    
    UFUNCTION(BlueprintCallable)
    ASocialReasoning* GetSocialReasoning();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObjectStateInfo* GetObjectStateInfo() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCharacterStateInfo* GetCharacterStateInfo() const;
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingTargetableByAiState(EStandardManagedPriority Priority, const UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingMaxHeightValue(EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingMaxHeightEnabledValue(EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingLODOverride(UObject* Provider);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ExcuseMe();
    
    UFUNCTION(BlueprintCallable)
    void DisableCcd();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ConverseWithProxy(FSocialResponse& SocialResponse);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Converse(FSocialResponse& SocialResponse);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Chat();
    
    UFUNCTION(BlueprintCallable)
    void CaptureFocusForScriptedBehavior(FName InIdentifyingName);
    
    
    // Fix for true pure virtual functions not being implemented
};

