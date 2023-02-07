#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "SceneActionState_PlayFMV.generated.h"

class UMediaPlayer;
class UUserWidget;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_PlayFMV : public USceneRigActionState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* Widget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMediaPlayer* MediaPlayer;
    
public:
    USceneActionState_PlayFMV();
private:
    UFUNCTION(BlueprintCallable)
    void OnMediaOpened(const FString& OpenedUrl);
    
};

