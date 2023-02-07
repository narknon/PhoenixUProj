#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HintManager.generated.h"

class UGameLogicObject;
class UHint;

UCLASS(Blueprintable)
class UHintManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UHint*> Hints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGameLogicObject* GameLogicObject;
    
public:
    UHintManager();
private:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
public:
    UFUNCTION(BlueprintCallable)
    static UGameLogicObject* GetHintManagerGameLogicObject();
    
    UFUNCTION(BlueprintCallable)
    static UHint* GetHint(const FString& HintKey);
    
    UFUNCTION(BlueprintCallable)
    static void DestroyHint(UHint* Hint);
    
    UFUNCTION(BlueprintCallable)
    static UHint* CreateHint(const FString& Name);
    
};

