#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "CreatureActivityThreshold.h"
#include "ECreatureNeed.h"
#include "ECreaturePregnancyState.h"
#include "EventHandleTriggeredDelegateDelegate.h"
#include "CreatureState.generated.h"

class UCreatureDefinition;
class UCreatureState;

UCLASS(Blueprintable)
class PHOENIX_API UCreatureState : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventHandleTriggeredDelegate ByproductCooldownEndedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventHandleTriggeredDelegate ByproductHarvestedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventHandleTriggeredDelegate NeedsChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventHandleTriggeredDelegate HappinessChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventHandleTriggeredDelegate PregnancyStateChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEventHandleTriggeredDelegate CreatureActorSpawnedDelegate;
    
public:
    UCreatureState();
    UFUNCTION(BlueprintCallable)
    void SetIsUncapturable(bool bInIsUncapturable);
    
    UFUNCTION(BlueprintCallable)
    void SetCanReturnToWild(bool bInCanReturnToWild);
    
    UFUNCTION(BlueprintCallable)
    void OnHarvestByproduct(FName CollectorID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUnbornCreature() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPregnant() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool IsNeedMet(const ECreatureNeed CreatureNeed) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInSanctuary() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsIncubating() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool IsInConflict() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool IsHappyEnoughToPlayWithToy() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEgg() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCreatureCaptured() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsByproductOnCooldown() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAlbino() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    UCreatureState* GetUnbornChildState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetTypeID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetTranslatedCreatureDisplayName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTimespan GetTimeLeftToGrowUp() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetScaleVariation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECreaturePregnancyState GetPregnancyState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FDateTime GetPregnancyStartDateTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPenUID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetNurturingSpaceID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMotherUID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsUncapturable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsMount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsMale() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool GetIsByproductReady() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool GetIsByproductHarvestableByPlayer(FString& OutErrorKey) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FDateTime GetIncubationStartDateTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetIconString() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    FTimespan GetHatchingTimeRemaining() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    float GetHappinessCap() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    float GetHappiness() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    FTimespan GetGestationTimeRemaining() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetFatherUID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCreatureDefinition* GetDefinition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCreatureUID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetCreatureName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void GetCreatureDisplayName(FString& OutName, bool& OutIsLocalizationKey) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetColorVariation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCanReturnToWild() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCanRename() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    FTimespan GetByproductCooldownTimeLeft() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    float GetByproductCooldownProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetBreedingGeneration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FDateTime GetBirthDateTime();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetAdultIconString() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<FCreatureActivityThreshold> GetActivityThresholds() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanStartActivity() const;
    
    UFUNCTION(BlueprintCallable)
    bool CanCreatureBreed(FString& ErrorMessage);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool AreAllNeedsMet() const;
    
};

