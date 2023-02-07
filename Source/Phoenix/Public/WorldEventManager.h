#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "EStandardManagedPriority.h"
#include "WorldEventDataRow.h"
#include "WorldEventManager.generated.h"

class ALevelScriptActor;
class AWorldEventLocationActor;
class UDataTable;
class UWorldEventManager;

UCLASS(Blueprintable, NotPlaceable)
class UWorldEventManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* WorldEventsDataTable;
    
public:
    UWorldEventManager();
    UFUNCTION(BlueprintCallable)
    void StartSettingEventStreamingPausedValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnWorldEventLoaded(AWorldEventLocationActor* locationActor, const FWorldEventDataRow& dataRow);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
public:
    UFUNCTION(BlueprintCallable)
    FGameplayTagContainer GetWorldEventLocationTags(ALevelScriptActor* LevelScript);
    
    UFUNCTION(BlueprintCallable)
    static UWorldEventManager* Get();
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingEventStreamingPausedValue(EStandardManagedPriority Priority, UObject* InInstigator);
    
};

