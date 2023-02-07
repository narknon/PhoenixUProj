#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AcknowledgeEventDelegate.h"
#include "AcknowledgmentStatChangedEventDelegate.h"
#include "AcknowledgementManager.generated.h"

class AActor;
class UAcknowledgement;
class UAcknowledgementManager;
class UGameLogicObject;

UCLASS(Blueprintable)
class PHOENIX_API UAcknowledgementManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAcknowledgmentStatChangedEvent AcknowledgementStatChangedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAcknowledgeEvent AcknowledgementEvent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGameLogicObject* AcknowledgementLogicContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, UAcknowledgement*> Acknowledgements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, UAcknowledgement*> TimeBasedAcknowledgements;
    
public:
    UAcknowledgementManager();
    UFUNCTION(BlueprintCallable)
    static void UpdateMiscStatStatic(const FName Key, const FString& Value);
    
    UFUNCTION(BlueprintCallable)
    static void UpdateMiscIntStatStatic(const FName Key, const int32 Value);
    
    UFUNCTION(BlueprintCallable)
    static void UpdateMiscBoolStatStatic(const FName Key, const bool bValue);
    
    UFUNCTION(BlueprintCallable)
    static void SetSpecialSpeakerForAcknowledgement(AActor* InSpecialSpeaker);
    
    UFUNCTION(BlueprintCallable)
    static void SetSpecialSpeakerByDBIDForAcknowledgement(const FName& InSpecialSpeakerName);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnPreLoadGame();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame();
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleStatChanged(const FName StatID, const int32 Value, const int32 Delta);
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleHouseChestAcknowledgement();
    
    UFUNCTION(BlueprintCallable)
    void HandleFleshLoaded(AActor* InFleshActor);
    
    UFUNCTION(BlueprintCallable)
    static UAcknowledgementManager* GetAcknowledgementManager();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UAcknowledgementManager* Get();
    
};

