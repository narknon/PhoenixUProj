#pragma once
#include "CoreMinimal.h"
#include "HUDElementGroup.h"
#include "ZoneNotification.generated.h"

class UPhoenixTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class UZoneNotification : public UHUDElementGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* ZoneNotification_Header;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* ZoneNotification_Label;
    
    UZoneNotification();
    UFUNCTION(BlueprintCallable)
    void Notify(FName Header_Name, FName Label_Name, FName Image_Left, FName Image_Right, float duration_seconds, bool PlaySound);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideNotificationBP();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DisplayNotificationBP(bool PlaySound);
    
};

