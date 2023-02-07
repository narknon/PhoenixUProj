#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AvaAudio.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API UAvaAudio : public UObject {
    GENERATED_BODY()
public:
    UAvaAudio();
    UFUNCTION(BlueprintCallable)
    static void SetPlayerVoicePitch(int32 PlayerVoicePitch, bool WriteToSave);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnCurtainRaised();
    
    UFUNCTION(BlueprintCallable)
    void OnCurtainLowered();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetPlayerVoicePitch();
    
};

