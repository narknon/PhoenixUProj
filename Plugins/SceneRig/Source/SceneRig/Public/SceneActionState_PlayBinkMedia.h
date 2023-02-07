#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "SceneActionState_PlayBinkMedia.generated.h"

class UBinkMediaPlayer;
class UUserWidget;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_PlayBinkMedia : public USceneRigActionState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* Widget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBinkMediaPlayer* BinkMediaPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasValidEnter;
    
public:
    USceneActionState_PlayBinkMedia();
private:
    UFUNCTION(BlueprintCallable)
    void OnMediaOpened(const FString& OpenedUrl);
    
    UFUNCTION(BlueprintCallable)
    void OnMediaFailedToOpen();
    
};

