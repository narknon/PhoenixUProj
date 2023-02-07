#pragma once
#include "CoreMinimal.h"
#include "AvatarCreatorEventDelegate.h"
#include "PhoenixUserWidget.h"
#include "AvatarCreatorPage.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAvatarCreatorPage : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAvatarCreatorEvent OnCreatorItemHovered;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAvatarCreatorEvent OnCreatorItemUnhovered;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAvatarCreatorEvent OnCreatorSliderHovered;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAvatarCreatorEvent OnCreatorSliderUnhovered;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAvatarCreatorEvent OnAllIconsLoaded;
    
    UAvatarCreatorPage();
private:
    UFUNCTION(BlueprintCallable)
    void SetPlayerVoicePitch(int32 PlayerVoicePitch);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPlayerVoicePitch();
    
};

