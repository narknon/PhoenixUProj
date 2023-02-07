#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Templates/SubclassOf.h"
#include "DoorSettings.generated.h"

class UUserWidget;

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class UDoorSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> SpinnerWidgetClass;
    
    UDoorSettings();
};

