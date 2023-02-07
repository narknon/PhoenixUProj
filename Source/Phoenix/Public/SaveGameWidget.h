#pragma once
#include "CoreMinimal.h"
#include "SaveGameInfo.h"
#include "PhoenixUserWidget.h"
#include "SaveGameWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API USaveGameWidget : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    USaveGameWidget();
    UFUNCTION(BlueprintCallable)
    bool SaveGameInSlot(int32 SaveSlot);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RefreshListAfterSaveFailed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RefreshListAfterSave(const TArray<FSaveGameInfo>& SaveData);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 ParseSlotNumFromName(const FString& SlotName);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameFailed();
    
    UFUNCTION(BlueprintCallable)
    void OnAsyncSaveCompleted();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetUserSavesBySlot(TArray<FSaveGameInfo>& SaveData);
    
    UFUNCTION(BlueprintCallable)
    bool DeleteGameFromSlot(int32 SaveSlot);
    
};

